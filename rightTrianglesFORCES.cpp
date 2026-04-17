#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    int count = 0;
    char arr[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> arr[i][j];
        }   
    }

    vector<int> row(n, 0), col(m, 0); //tạo vector với n, m phần tử = 0 cho từng index
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(arr[i][j] == '*'){
                row[i]++;
                col[j]++;
            }
        }
    }
    long long tong = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(arr[i][j] == '*'){
            tong += (row[i]-1) * (col[j]-1);
            }
        }
    }
    cout << tong;
    return 0;
}