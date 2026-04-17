#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long m, n, a;
    cin >> n >> m >> a;

    long long row = (m + a - 1)/a;
    long long col = (n + a - 1)/a;

    cout << "row: " << row << endl; 
    cout << "col: " << col << endl;
    cout << "So phien can tim la: " << row * col << endl;
    return 0;
}