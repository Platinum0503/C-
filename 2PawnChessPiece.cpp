#include <iostream>
#include <algorithm>
using namespace std;

struct Position{
    int row;
    int col;
};
void initBoard(char board[8][8]){
    for(int row = 0; row < 8;row++){
        for(int col = 0;col < 8;col++){
            board[row][col] = '.';
        }
    }
}
void placePiece(char board[8][8],char piece, Position pos){
    board[pos.row][pos.col] = piece;    
}
void movePiece(char board[8][8], Position from, Position to){
    char piece = board[from.row][from.col];

    //đặt quân vào vị trí mới
    board[to.row][to.col] = piece;

    //xoá vị trí cũ
    board[from.row][from.col] = '.';
}
void printBoard(char board[8][8]){
    cout << "   a b c d e f g h" << endl;
    for(int row = 0;row < 8;row++){
        cout << 8-row << " ";
        for(int col = 0;col < 8;col++){
            cout << board[row][col] << " ";
        }
        cout << 8-row << endl;
    }
    cout << "   a b c d e f g h" << endl;
}
bool canPawnMoveOneSquare(char board[8][8], Position from, Position to){
    char piece = board[from.row][from.col];

    //kiểm tra có phải là Pawn ko
    if(piece != 'P' && piece != 'p'){
        return false;
    }
    //caution kiểm tra cột k đổi
    if(from.col != to.col){
        return false;
    }
    //kiểm tra đi đúng 1 ô
    //Pawn trắng (P) đi lên: row giảm 1
    if(piece == 'P' && to.row == from.row - 1){
        //kiểm tra ô đích trống
        return board[to.row][to.col] == '.';
    }   

    //Pawn đen (p) đi xuống: row tăng 1
    if(piece == 'p' && to.row == from.row + 1){
        //kiểm tra ô đích trống    
        return board[to.row][to.col] == '.';
    }
    return false;
}
bool PawnMove2Piece(char board[8][8], Position from, Position to){
    char piece = board[from.row][from.col];
    //kiểm tra có phải Pawn ko
    if(piece != 'P' && piece != 'p'){
        return false;
    }
    //kiểm tra cột ko đổi (đi thẳng)
    if(from.col != to.col){
        return false;
    }

    int direction = (piece == 'P') ? -1 : 1;
    int start = (piece == 'P') ? 6 : 1;
    //kiểm tra đang ở vị trí ban đầu
    if(from.row != start){
        return false;
    }
    //kiểm tra đi đúng 2 ô
    if(to.row != from.row + 2 * direction){
        return false;
    }
    //kiểm tra ô đích trống
    if(board[to.row][to.col] != '.'){
        return false;
    }
    //kiểm tra ô giữa cũng trống
    int middleRow = from.row + direction;
    if(board[middleRow][from.col] != '.'){
        return false;
    }
    return true;
}
//hàm ăn chéo
bool canPawnCapture(char board[8][8], Position from, Position to){
    char piece = board[from.row][from.col];

    //kiểm tra có phải là Pawn k
    if(piece != 'P' && piece != 'p'){
        return false;
    }

    int direction = (piece == 'P') ? -1 : 1;

    //kiểm tra đi chéo 1 ô
    if(abs(to.col-from.col) != 1){
        return false;
    }
    //kiểm tra đi đúng 1 hàng theo hướng
    if(to.row != from.row + direction){
        return false;
    }
    //kiểm tra ô đích có quân địch
    char target = board[to.row][to.col];
    if(target != '.'){
        return false; //ko có j để ăn
    }
    //kiểm tra ko phải là quân cùng màu
    if((piece == 'P' && target == 'P') || (piece == 'p' && target == 'p')){
        return false;
    }
    //có thể ăn nếu
    // - P (trắng) ăn p (đen) or quân khác viết thường
    // - p (đen) ăn P (trắng) or quân khác viết Hoa
    return true; 
}
int main(){
    char board[8][8];
    initBoard(board);

    cout << "=== TEST 1: DI CHUYEN 1 O ==" << endl;
    Position e2 = {6, 4};
    placePiece(board, 'P', e2);
    printBoard(board);

    Position e3 = {5, 4};
    if(canPawnMoveOneSquare(board, e2, e3)){
        cout << "Nuoc di hop le!" << endl;
        movePiece(board, e2, e3);
        printBoard(board);
    } else {
        cout << "Nuoc di ko hop le!" << endl;
    }
    cout << "\n=== TEST 2: DI CHUYEN 2 O ===" << endl;
    Position d2 = {6, 3};
    placePiece(board, 'P', d2);
    printBoard(board);

    Position d4 = {4, 3};
    if(canPawnMoveOneSquare(board, d2, d4)){
        cout << "nuoc di 2 o hop le!" << endl;
        movePiece(board, d2, d4);
        printBoard(board);
    }else {
        cout << "nuoc di ko hop le!" << endl;
    }
    cout << "\n=== TEST 3: EAT CHEO ==="<< endl;
    Position e5 = {3, 4};
    Position d6 = {2, 3};
    placePiece(board, 'p', d6); //đặt quân đen ở d6
    printBoard(board);

    //di chuyển quân trắng từ e3 (đa di chuyển trước đó)
    //lấy lại vị trí hiện tại của quân trắng
    Position currentWhite = {5, 4}; //e3

    if(canPawnMoveOneSquare(board, currentWhite, d6)){
        cout << "Eat cheo thanh cong!" << endl;
        movePiece(board, currentWhite, d6);
        printBoard(board);
    }else{
        cout << "eat cheo khong hop le!" << endl;
    }
    return 0;
}