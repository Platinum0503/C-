#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

enum class PieceType {EMPTY, PAWN, ROOK, KNIGHT, BITSHOP, QUEEN, KING};
enum class Color {NONE,WHITE, BLACK};

struct Position{
    int row;
    int col;

    Position(int r, int c) : row(r), col(c) {}
    Position() : row(-1), col(-1) {} //positon khong hop le
};

bool isValidPosition(Position pos){
    return pos.row >= 0 && pos.row < 8 &&
           pos.col >= 0 && pos.row < 8;
}
struct ChessPiece{
    PieceType type;
    Color color;
    Position position;

    //contructor
    ChessPiece() : type(PieceType::EMPTY), color(Color::NONE), position(-1, -1) {}

    ChessPiece(PieceType t, Color c, Position pos) :
                type(t), color(c), position(pos) {}
    bool isEmpty(){
        return type == PieceType::EMPTY;
    }
};

void initializaEmptyBoard(ChessPiece board[8][8]){
    for(int row = 0;row < 8;row++){
        for(int col = 0;col < 8;col++){
           board[row][col] = ChessPiece();
           board[row][col].position = Position(row, col);
        }
    }
}
ChessPiece board[8][8];

//hàm đặt quân cờ
void placePiece(ChessPiece board[8][8], PieceType type, Color color, int row, int col){
    board[row][col] = ChessPiece(type, color, Position(row, col));
}
bool isValidPawnMove(ChessPiece board[8][8], Position from, Position to){
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    //tốt trắng đi lên giảm row, tốt đen đi xuống tăng row
    int direction = (piece.color == Color::WHITE) ? -1 : 1;

    //di chuyển 1 ô
    if(to.row == from.row + direction && to.col == from.col){   //caution
        return target.isEmpty(); //phải là ô trống 
    }
    //move 2 ô từ vị trí ban đầu
    int start = (piece.color == Color::WHITE) ? 6 : 1;
    if(to.row == from.row + 2 * direction && to.col == from.col && from.col == start){
        //cả 2 ô sphải trống
        return target.isEmpty() && board[from.row + direction][from.col].isEmpty();
    }
    //eat chéo
    if(abs(to.col-from.col) == 1 && to.row == from.row + direction){
        return !target.isEmpty() && target.color != piece.color;
    }
    return false;
}
bool isValidRook(ChessPiece board[8][8], Position from, Position to){

    if(from.row != to.row && from.col != to.col){
        return false;
    }
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }
    if(from.col == to.col){ // đi ngang
        int start = min(from.col, to.col) + 1; //+1 ở đây là bỏ qua ô xuất phát
        int end = max(from.col, to.col);
        for(int col = start;start < end;start++){
            if(!board[from.row][col].isEmpty()){ //         caution 
                //ở đây row cố định, col sẽ thay đổi
                return false; //có quân chắn đường đi
            }
        }
    }else { //đi dọc
        int start = min(from.row,from.col) + 1; //+1 ở đây là bỏ qua ô xuất phát
        int end = max(from.row,from.col);
        for(int row = start;start < end;start++){
            if(!board[row][from.col].isEmpty()){ //            caution
                //ở đây col cố định, row sẽ thay đổi
                return false;
            }
        }
    }
    return true;
}
bool isValidKnight(ChessPiece board[8][8], Position from, Position to){ 
    int rowDiff = abs(to.row - from.row);
    int colDiff = abs(to.col - from.col);

    //knight move 2-1 | 1-2
    if(!(rowDiff == 2 && colDiff == 1 || rowDiff == 1 && colDiff == 2)){
        return false;
    }

    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];
    
    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }
    return true;
}
bool isValidBitshop(ChessPiece board[8][8], Position from, Position to){
    int colDiff = abs(from.col - to.col);
    int rowDiff = abs(from.row - to.row);

    if(!(rowDiff == colDiff)){ //caution
        return false;
    }
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }
    //check đường đi có bị chắn ko
    //xác định hướng di chuyển
    int rowDirection = (to.row > from.row) ? 1 : -1;
    int colDirection = (to.col > from.col) ? 1 : -1;

    //check từng ô trên đường đi
    int currentRow = from.row + rowDirection; //caution
    int currentCol = from.col + colDirection; //caution

    while(currentRow != to.row && currentCol != to.col){
        if(!board[currentRow][currentCol].isEmpty()){
            return false;
        }
        currentRow += rowDirection;
        currentCol += colDirection;
    }
    return true;
}
bool isValidQueen(ChessPiece board[8][8], Position from, Position to){
    //queen = rook + bitshop
    //nếu đi được như rook or bitshop --> hợp lệ

    return isValidBitshop(board, from, to) || 
           isValidRook(board, from, to);
}
bool isValidKing(ChessPiece board[8][8], Position from, Position to){
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    int rowDiff = abs(from.row - to.row);
    int colDiff = abs(from.col - to.col);

    if(rowDiff > 1 || colDiff > 1){
        return false;
    }
    if(rowDiff == 0 && colDiff == 0){
        return false;
    }
    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }
    return true;
}
//hàm tổng hợp kiểm tra nước đi
bool isValidMove(ChessPiece board[8][8], Position from, Position to){
    //check move hợp lệ
    if(!(isValidPosition(from)) || !(isValidPosition(to))){ //      caution
        return false; 
    }
    //kiểm tra from và to khác nhau
    if(from.row == to.row || from.col == to.col){
        return false;
    }
    ChessPiece piece = board[from.row][from.col];
    //kiểm tra ô xuất phát có quân ko
    if(piece.isEmpty()){
        return false;
    }
    //kiểm tra theo loại quân
    switch(piece.type){
        case PieceType::PAWN:
                return isValidPawnMove(board, from, to);
        case PieceType::ROOK:
                return isValidRook(board, from,to);
        case PieceType::KING:
                return isValidKnight(board, from, to);
        case PieceType::BITSHOP:

        default: 
            return false;
    }
}
//lấy tất cả nước đi có thể của 1 quân
vector<Position> getPosibleMove(ChessPiece board[8][8], Position from){ //caution
    vector<Position> moves;

    //duyệt toản bộ bàn cờ
    for(int row = 0;row < 8;row++){
        for(int col = 0;col < 8;col++){
            Position to(row, col);
            if(isValidMove(board, from, to)){
                moves.push_back(to);
            }
        }
    }
    return moves;
}
//lấy kí hiệu quân cờ
char getPieceSymbol(ChessPiece piece){
    if(piece.isEmpty()) return '-';

    char symbols[7] = {' ', 'P', 'R', 'N', 'B', 'Q', 'K'};
    char symbol = symbols[static_cast<int>(piece.type)];
    //chữ thường = đen, HOA =  Trắng
    if(piece.color == Color::BLACK){
        symbol = tolower(symbol);
    }
    return symbol;
}
//in board
void printBoard(ChessPiece board[8][8]){
    cout << "\n a b c d e f g h" << endl;
    cout << "  ---------------" << endl;

    for(int row = 0;row < 8;row++){
        cout << 8-row << "|"; //số hàng
        for(int col = 0;col < 8;col++){
            cout << getPieceSymbol(board[row][col]) << " ";
        }
        cout << "|" << 8-row << endl;
    }
    cout << "  ---------------" << endl;
    cout << "\n a b c d e f g h" << endl;
}
int main(){
    ChessPiece board[8][8];
    initializaEmptyBoard(board);

    //đặt quân test
    placePiece(board, PieceType::PAWN, Color::WHITE, 6, 4);
    placePiece(board, PieceType::ROOK, Color::WHITE, 7, 0);
    placePiece(board, PieceType::KNIGHT, Color::BLACK, 0, 1);

    printBoard(board);

    //test PAWN
    cout << "=== TEST PAWN ===" << endl;
    vector<Position> pawnMoves = getPosibleMove(board, Position(6, 4)); 
    cout << "Position move: " << pawnMoves.size() << endl;
    for(Position move : pawnMoves){
        cout << "   -> (" << move.row << ", " << move.col << ")" << endl;
    }
    //tương đương
   // for(int i = 0; i < pawnMoves.size(); i++) {
  //  Position move = pawnMoves[i];
 //   cout << "   -> (" << move.row << ", " << move.col << ")" << endl;
//     }
    //test ROOK
    cout << "=== TEST ROOK ===" << endl;
    vector<Position> rookMoves = getPosibleMove(board, Position(7, 0));
    cout << "Position move: " << rookMoves.size() << endl;
    
    cout << "=== TEST KNIGHT ===" << endl;
    vector<Position> knightMoves = getPosibleMove(board, Position(0, 1));
    cout << "Position move: " << knightMoves.size() << endl;
    
    return 0;   
}