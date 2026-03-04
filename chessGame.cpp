#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum class PieceType {EMPTY, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING};
enum class Color {NONE, WHITE, BLACK};

struct Position {
    int row; //hang (0-7)
    int col; //cot (0-7)

    //contrustor //caution
    Position(int r, int c) : row(r), col(c) {}
    Position() : row(-1), col(-1) {} //position ko hop le
};
//check position hợp lệ (in ban co 8x8)
bool isValidPosition(Position pos){
    return pos.row >= 0 && pos.row < 8 &&
           pos.col >= 0 && pos.col < 8;
}
struct ChessPiece {
    PieceType type;
    Color color;
    Position position;

    //contrustor
    ChessPiece() : type(PieceType::EMPTY), color(Color::NONE), position(-1, -1) {};

    ChessPiece(PieceType t, Color c, Position pos)
            : type(t), color(c), position(pos) {}
    bool isEmpty() {
        return type == PieceType::EMPTY;
    }
};

ChessPiece board[8][8];

void initializaEmptyBoard(ChessPiece board[8][8]){
    for(int row = 0; row < 8;row++){
        for(int col = 0; col < 8;col++){
            board[row][col] = ChessPiece(); //all ô trống
            board[row][col].position = Position(row, col);
        }
    }
}
// Hàm đặt quân cờ lên bàn
void placePiece(ChessPiece board[8][8], PieceType type, Color color, int row, int col){
    board[row][col] = ChessPiece(type, color, Position(row, col)); //caution
}
bool isValidPawnMove(ChessPiece board[8][8], Position from, Position to){
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    // Tốt trắng đi lên (giảm row), tốt đen đi xuống (tăng row)
    int direction = (piece.color == Color::WHITE) ? -1 : 1;

    //move straight 1 ô
    if(to.row == from.row + direction && to.col == from.col){
        return target.isEmpty(); //phải là ô trống
    }
    //move straight 2 ô từ vị trí ban đầu
    int startRow = (piece.color == Color::WHITE) ? 6 : 1;
    if(from.row == startRow && to.col == from.col && to.row == from.col + 2 * direction){
        //cả 2 ô phải trống
        return target.isEmpty() && board[from.row + direction][from.col].isEmpty();
    }
    //eat chéo
    if(abs(to.col - from.col) == 1 && to.row == from.row + direction){
        return !target.isEmpty() && target.color != piece.color;
    }
    return false;
}
// kiểm tra nước đi hợp lệ cho ROOK (xe)
bool isValidRook(ChessPiece board[8][8], Position from, Position to){
    //xe chỉ đi thẳng hàng or cột
    if(from.row != to.row && from.col != to.col){
        return false;
    }
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    //kiểm tra đích đến ko phải quân cùng màu
    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }
    //kiểm tra đường đi không có quân chắn
    if(from.row == to.row){ //di chuyển ngang
        int start = min(from.col, to.col) + 1; //+1 ở đây là bỏ qua ô xuất phát
        int end = max(from.col, to.col);
        for(int col = start;col < end;col++){
            if(!board[from.row][col].isEmpty()){
                return false; //có quân chắn đường
            }
        }
    }else { //di chuyển dọc
        int start = min(from.row, to.row) + 1; //+1 ở đây là bỏ qua ô xuất phát
        int end = max(from.row, to.row);
        for(int row = start;row < end;row++){
            if(!board[row][from.row].isEmpty()){
                return false; //có quân chắn đường
            }
        }   
    }
    return true;
}
//kiểm tra nước đi hợp lệ cho KNIGHT (Mã)
bool isValidKnightMove(ChessPiece board[8][8], Position from, Position to){
    int rowDiff = abs(to.row - from.row);
    int colDiff = abs(to.col - from.col);

    //Mã đi chữ L: (2,1) or (1,2)
    if(!((rowDiff == 2 && colDiff == 1 || colDiff == 2 && rowDiff == 1))){
        return false;
    }
    
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    //kiểm tra đích đến ko phải là quân cùng màu
    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }
    return true;
}
//hàm tổng hợp kiểm tra nước đi
bool isValidMove(ChessPiece board[8][8], Position from, Position to){
    //kiểm tra vị trí hợp lệ
    if(!isValidPosition(from) || !isValidPosition(to)){
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
                return isValidRook(board, from, to);
        case PieceType::KNIGHT:
                return isValidKnightMove(board, from, to);
        //TUDO: thêm bishop, Queen, King
        default:
            return false;
    }
}
//lấy all nước đi có thể của 1 quân
vector<Position> getPossibleMoves(ChessPiece board[8][8], Position from){
    vector<Position> moves;

    //duyệt toàn bộ bàn cờ
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

    //chữ thường = đen, chữ hoa = trắng
    if(piece.color == Color::BLACK){
        symbol = tolower(symbol); //tolwer chuyển từ HOA sang thường
    }
    return symbol;
}
//in bàn cờ
void printBoard(ChessPiece board[8][8]){
    cout << "\n a b c d e f g h" << endl;
    cout << " ---------------" << endl;

    for(int row = 0; row < 8;row++){
        cout << 8 - row << "|"; //số hàng
        for(int col = 0; col < 8;col++){
            cout << getPieceSymbol(board[row][col]) << " ";
        }
        cout << "|" << 8 - row << endl;
    }
    cout << " --------------" << endl;
    cout << " a b c d e f g h" << endl;
}
int main(){
    ChessPiece board[8][8];
    initializaEmptyBoard(board);

    //đặt quân test
    placePiece(board, PieceType::PAWN, Color::WHITE, 6, 4); //e2
    placePiece(board, PieceType::ROOK, Color::WHITE, 7, 0); //a1
    placePiece(board, PieceType::KNIGHT, Color::BLACK, 0, 1); //b8

    printBoard(board);

    //test PAWN
    cout << "=== TEST PAWN (e2) ===" << endl;
    vector<Position> pawnMoves = getPossibleMoves(board, Position(6, 4));
    cout << "Possible move: " << pawnMoves.size() << endl;
    for(Position move : pawnMoves){
        cout << "   -> (" << move.row << ", " << move.col << ")" << endl;
    }
    //test ROOK
    cout << "\n=== TEST ROOK (a1) === "<< endl;
    vector<Position> rookMoves = getPossibleMoves(board, Position(7, 0));
    cout << "Possible moves: " << rookMoves.size() << endl;

    //test knight
    cout << "\n=== TEST KNIGHT (b8) ===" << endl;
    vector<Position> knightMoves = getPossibleMoves(board, Position(0, 1));
    cout << "Possible move: " << knightMoves.size() << endl;    

    return 0;
}