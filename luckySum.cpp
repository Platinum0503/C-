#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> lucky;

void generate(long long cur){
    if(cur > 1e10) return;
    lucky.push_back(cur);
    generate(cur * 10 + 4);
    generate(cur * 10 + 7);
}

long long nextLucky(long long x){ //ham nay có thể xoá nếu dùng dòng for hiện tại
    for(long long num : lucky){
        if(num >= x) return num;
    }
    /* for(int i = 0; i < lucky.size(); i++){
    long long num = lucky[i];
    } */
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    generate(4);
    generate(7);
    sort(lucky.begin(), lucky.end());

    long long l,r;
    cin >> l >> r;
    long long tong = 0;
    /*for(int i = l;i <= r;i++){
       tong += nextLucky(i);
    } */

    for(int i = 0;i < lucky.size();i++){
        long long start = (i == 0) ? 1 : lucky[i-1] + 1;
        long long end = lucky[i];

        long long lo = max(l, start);
        long long hi = min(r, end);

        if(lo <= hi) tong += (hi - lo + 1) *lucky[i];
    }
    cout << tong;
    return 0;
}