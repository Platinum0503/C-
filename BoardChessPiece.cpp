#include <iostream>
using namespace std;

int main(){
    cout << "   a b c d e f g h" << endl;
    for(int row = 0;row < 8;row++){
        cout << 8 - row << " ";
        for(int col = 0;col < 8;col++){
            cout << ". "; //ô trống
        }
        cout << 8 - row << endl;
    }
    cout << "   a b c d e f g h" << endl;
    return 0;
}