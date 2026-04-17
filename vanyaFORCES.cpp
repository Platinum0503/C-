#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h; //n là số người | h là chiều cao hàng rào
    cin >> n >> h;

    int cao[n];
    int chieuRong = 0;
    for(int i = 0;i < n;i++){
        cin >> cao[i];
        if(cao[i] > h){
            chieuRong += 2;
        }else{
            chieuRong += 1;
        }
    }
    cout << chieuRong;
    return 0;
}