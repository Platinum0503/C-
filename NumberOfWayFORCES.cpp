#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if(n < 2){
        cout << 0;
        return 0;
    }
    long long arr[n];

   // long long tong = arr[0] + arr[1];
    long long tong = 0; //cần tính tổng của mảng/3 thay vì tổng 2 số đầu

    for(int i = 0;i < n;i++){
        cin >> arr[i];
        tong += arr[i];
    }

    if(tong % 3 != 0){
        cout << 0;
        return 0;
    }
    long long muc_tieu = tong/3;
    long long tong_hien_tai = 0;
    long long dem_phieu = 0;
    long long count = 0;

    for(int i = 0;i < n -1;i++){
        tong_hien_tai += arr[i];
        if(tong_hien_tai == 2 * muc_tieu){
            count += dem_phieu;
        }
        if(tong_hien_tai == muc_tieu){
            dem_phieu++;
        }
    }
    cout << count;
    return 0;
}