#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n >= 2 && n <= 100){
        n = n*2;
        for(int i = 0; i < n/2;i++){
            cout << i+1 << " " << n-i << '\n';
        }
    }
    return 0;
}