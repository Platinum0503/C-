#include <iostream>
using namespace std;

int main(){
    char board[8][8];

    // TODO 2.2: Khởi tạo tất cả ô = '.'
    for(int row = 0;row < 8;row++){
        for(int col = 0;col < 8;col++){
            board[row][col] = '.';
        }
    }
    //in bàn cờ từ mảng
    cout << "   a b c e d f g h" << endl;
    for(int row = 0;row < 8;row++){
        cout << 8-row << " "; //caution
        for(int col = 0;col < 8;col++){
            cout << board[row][col] << " ";
        }
        cout << 8 - row << endl;
    }
    cout << "   a b c e d f g h" << endl;
    return 0;
}
