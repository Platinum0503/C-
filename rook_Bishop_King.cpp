#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int rook;
    if(r1 == r2 || c1 == c2){
        rook = 1;
    }else{
        rook = 2;
    }

    int bishop;
    if(abs(r1-r2) == abs(c1-c2)){
        bishop = 1; //cung duong cheo
    }else if((r1+c1) % 2 == (r2+c2) % 2){
        bishop = 2;
    }else{
        bishop = 0;
    }
    
    int king = max(abs(r1-r2) , abs(c1-c2));

    cout << rook << " " << bishop << " " << king << endl;
    return 0;
}