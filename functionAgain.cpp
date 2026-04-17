#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    long long mang[n];
    vector<long long> d(n-1);
    for(int i = 0;i < n;i++){
        cin >> mang[i];
    }
    for(int i = 0;i < n-1;i++){
        d[i] = abs(mang[i] - mang[i+1]);
    }
    long long maxF = 0;
    for(int l = 0;l < n-1;l++){
        long long f = 0;
        int dau = 1;
        for(int r = l;r < n-1;r++){
            f += dau * d[r];
            dau = -dau; //đổi dấu
            maxF = max(maxF, f);
        }
    }
    cout << maxF << endl;
    return 0;
}