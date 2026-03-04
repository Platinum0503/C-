#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

enum class PieceType {EMPTY, PAWN, ROOK, KNIGHT, BITSHOP, QUEEN, KING};
enum class Color {EMPTY, BLACK, WHITE};

struct Position {
    int row;
    int col;

    Position(int r, int c) : row(r), col(c) {}
    Position() : row(-1), col(-1) {} //position ko hop le
};
bool isValidPosition(Position pos){
    return pos.row >= 0 && pos.row < 8 &&
           pos.col >= 0 && pos.col < 8;
}
struct ChessPiece{
    PieceType type;
    Color color;
    Position position;

    //contructor
    ChessPiece() : type(PieceType::EMPTY), color(Color::EMPTY), position(-1, -1) {}

    ChessPiece(PieceType t, Color c, Position pos) : 
                type(t), color(c), position(pos) {}
    bool isEmpty(){
        return type == PieceType::EMPTY;
    }
};

void iniializeEmptyBoard(ChessPiece board[8][8]){
    for(int row = 0;row < 8;row++){
        for(int col = 0;col < 8;col++){
            board[row][col] = ChessPiece();
            board[row][col].position = Position(row, col);
        }
    }
}
bool canPawnMoveOneSqure(ChessPiece board[8][8], Position from, Position to){
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    int direction = (piece.color == Color::WHITE) ? -1 : 1;

    if(to.row == from.row + direction && to.col == from.col){
        return target.isEmpty();
    }
    return false;
}
bool canPawnMoveTwoPiece(ChessPiece board[8][8], Position from, Position to){
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    int direction = (piece.color == Color::WHITE) ? -1 : 1;
    int startRow = (piece.color == Color::WHITE) ? 6 : 1;

    //kiểm tra vị trí ban đầu
    if(from.row != startRow){
        return false;
    }
    //kiểm tra cột k đổi
    if(to.col != from.col){
        return false;
    }
    //kiểm tra đi đúng 2 ô
    if(to.row != from.row + 2*direction){
        return false;
    }
    //kiểm tra ô đích trống
    if(!target.isEmpty()){
        return false;
    }
    //kiểm tra ô giữa trống
    int middleRow = from.row + direction;
    if(!board[middleRow][from.col].isEmpty()){
        return false;
    }
    return true;
}
bool isValidKnightMove(ChessPiece board[8][8], Position from, Position to){
    int rowDiff = abs(from.row - to.row);
    int colDiff = abs(from.col - to.col);

    if(!((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2))){
        return false;
    }
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    //ko eat color == color
    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }
    return true;
}
bool isValidKingMove(ChessPiece board[8][8], Position from, Position to){
    int rowDiff = abs(from.row - to.row);
    int colDiff = abs(from.col - to.col);

    //king chỉ đi 1 ô
    if(rowDiff > 1 || colDiff > 1){
        return false;
    }
    //phải di chuyển
    if(rowDiff == 0 && colDiff == 0){
        return false;
    }

    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    //ko eat quan == color
    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }
    return true;
}
bool isValidRookHorizontal(ChessPiece board[8][8], Position from, Position to){
    //kiểm tra cùng hàng
    if(from.row != to.row){
        return false;
    }
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    //ko eat quan == color
    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }
    //kiem tra duong di
    int start = min(from.col, to.col) + 1;
    int end = max(from.col, to.col);

    for(int col = start;col < end;col++){
        if(!board[from.row][col].isEmpty()){
            return false; //có quân chắn
        }
    }
    return true;
}
bool isValidBitshopMove(ChessPiece board[8][8], Position from, Position to){
    int rowDiff = abs(from.row - to.row);
    int colDiff = abs(from.col - to.col);

    if(!(rowDiff == colDiff)){
        return false;
    }

    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }

    int rowDirection = (to.row > from.row) ? 1 : -1;
    int colDirection = (to.col > from.col) ? 1 : -1;

    int currentRow = from.row + rowDirection;
    int currentCol = from.col + colDirection;

    while(currentRow != to.row && currentCol != to.col){
        if(!board[currentRow][currentCol].isEmpty()){
            return false;
        }
        currentRow += rowDirection; //caution  not understand
        currentCol += colDirection; //caution
    }
    return true;
}
bool isValidRookMove(ChessPiece board[8][8], Position from, Position to){
    if(from.row != to.row && from.col != to.col){
        return false;
    }

    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    if(!target.isEmpty() && target.color == piece.color){
        return false;
    }

    //move ngang
    if(from.row == to.row){
        int start = min(from.col, to.col) + 1;
        int end = max(from.col, to.col);
        for(int col = start;col < end;col++){
            if(!board[from.row][col].isEmpty()){
                //ở đây row cố định
                return false;
            }
        }
    }
    else {
        int start = min(from.row, to.row) + 1;
        int end = max(from.row,to.row);
        for(int row = start;row < end;row++){
            if(!board[row][from.col].isEmpty()){
                return false;
            }
        }
    }
    return true;
}
bool isValidQueenMove(ChessPiece board[8][8], Position from, Position to){
    return isValidRookHorizontal(board, from, to) || isValidRookMove(board, from, to) ||
            isValidBitshopMove(board, from, to);
}
bool canPawnCapture(ChessPiece board[8][8], Position from, Position to){
    ChessPiece piece = board[from.row][from.col];
    ChessPiece target = board[to.row][to.col];

    int direction = (piece.color == Color::WHITE) ? -1 : 1;
    
    /* return to.row == from.row + direction 
        && abs(to.col - from.col) == 1
        && !target.isEmpty() 
        && target.color != piece.color; */

    if(direction == 1 && to.row == from.row + direction){
        return true;
    }
    if(to.row == from.row + direction && abs(to.col - from.col) == 1){
        return true;
    }
    if(!target.isEmpty() && target.color != piece.color){
        return true;
    }
    return false;
}
bool isValidMove(ChessPiece board[8][8], Position from, Position to){
    if(!isValidPosition(from) || !isValidPosition(to)){
        return false;
    }
    if(from.row == to.row && from.col == to.col){
        return false;
    }
    ChessPiece piece = board[from.row][from.col];

    if(piece.isEmpty()){
        return false;
    }
    switch(piece.type){
        case PieceType::ROOK:
            return isValidRookMove(board, from, to) || isValidRookHorizontal(board, from, to);
        case PieceType::PAWN:
            return canPawnMoveOneSqure(board, from, to) || canPawnMoveTwoPiece(board, from, to) || canPawnCapture(board, from, to);
        case PieceType::BITSHOP:
            return isValidBitshopMove(board, from, to);
        case PieceType::KNIGHT:
            return isValidKnightMove(board, from, to);
        case PieceType::QUEEN:
            return isValidQueenMove(board, from, to);
        case PieceType::KING:
            return isValidKingMove(board, from, to);
        default: return false;
    }
}
void placePiece(ChessPiece board[8][8], PieceType type, Color color, int row, int col){
    board[row][col] = ChessPiece(type, color, Position(row, col)); //caution
}
//lấy tất cả nước đi có thể của 1 quân
vector<Position> getPositionMove(ChessPiece board[8][8], Position from){ //caution
    vector<Position> move;
    for(int row = 0;row < 8;row++){
        for(int col = 0; col < 8;col++){
            Position to(row, col);
            if(isValidMove(board, from, to)){
                move.push_back(to);
            }
        }
    }
    return move;
}
vector<Position> getPosibleMoves(ChessPiece board[8][8], Position from){
    vector<Position> move;
    for(int row = 0;row < 8;row++){
        for(int col = 0;col < 8;col++){
            Position to(row, col);
            if(isValidMove(board, from, to)){
                    move.push_back(to);
            }
        }
    }
    return move;
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
void printBoard(ChessPiece board[8][8]){
    cout << "\n a b c d e f g h" << endl;
    cout << "  ---------------" << endl;
    for(int row = 0;row < 8;row++){
        cout << 8 - row << "|";
        for(int col = 0;col < 8;col++){
            ChessPiece piece = board[row][col];

            if(piece.isEmpty()){
                cout << '-';
                continue;
            }
            char symbols[7] = {' ', 'P', 'R', 'N','B', 'Q', 'K'};
            char symbol = symbols[static_cast<int>(piece.type)];
            //chữ HOA = TRẮNG, thường = đen
            if(piece.color == Color::BLACK){
                symbol = tolower(symbol);
            }
            cout << symbol; //caution (can wrong)
        }
        cout<< "|" << 8 - row << endl;
    }
    cout << " ---------------";
    cout << "\n a b c d e f g h";
}

int main(){
    ChessPiece board[8][8];
    iniializeEmptyBoard(board);

    //đặt quân test
    placePiece(board, PieceType::PAWN,Color::WHITE, 6, 4);
    placePiece(board, PieceType::ROOK, Color::WHITE, 7, 0);
    placePiece(board, PieceType::KNIGHT, Color::BLACK, 0, 1);

    printBoard(board);

    //test PAWN
    cout << "\n=== TEST PAWN(e2) ===" << endl;
    vector<Position> pawnMoves = getPosibleMoves(board, Position(6, 4));
    cout << "Position move: " << pawnMoves.size() << endl;
    for(Position move : pawnMoves){
        cout << "   -> (" << move.row << ", " << move.col << ")" << endl;
    }
    //test ROOK
    cout << "\n=== TEST ROOK ===" << endl;
    vector<Position> rookMoves = getPosibleMoves(board, Position(7, 0));
    cout << "Position move: " << rookMoves.size() << endl;
    for(Position move : rookMoves){
        cout << "   -> (" << move.row << ", " << move.col << ")" << endl;
    }

    //test knight
    cout << "\n=== TEST KNIGHT ===" << endl;
    vector<Position> knightMove = getPosibleMoves(board, Position(0, 1));
    cout << "Position move: " << knightMove.size() << endl;

    return 0;
}


