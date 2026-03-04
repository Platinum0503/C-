#include <iostream>
using namespace std;

int main(){
    char board[8][8];

    for(int row = 0;row < 8;row++){
        for(int col = 0;col < 8;col++){
            board[row][col] = '.';
        }
    }
    board[6][4] = 'P';

    board[1][4] = 'P';

    cout << "   a b c d e f g h" << endl;
    for(int row = 0;row < 8;row++){
        cout << 8-row << " ";
        for(int col = 0;col < 8;col++){
            cout << board[row][col] << " ";
        }
        cout << 8-row << endl;
    }
    cout << "   a b c d e f g h" << endl;

    return 0;
}