#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long x[60001], v[60001];

bool canMeet(double t){
    double left = -1e18;
    double right = 1e18;
    for(int i = 0;i < n;i++){
        left = max(left, x[i] - v[i]*t);
        right = min(right, x[i] + v[i]*t);
    }
    return left <= right;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0;i < n;i++) cin >> x[i];
    for(int i = 0;i < n;i++) cin >> v[i];

    double lo = 0, hi = 2e9;
    for(int i = 0;i < 100;i++){
        double mid = (lo+hi)/2;
        if(canMeet(mid)) hi = mid;
        else lo = mid;
    }
    cout << fixed; //caution in ra 12 chữ số thập phân
    cout.precision(12); //in ra 12 chữ số thập phân
    cout << hi;
    return 0;
}