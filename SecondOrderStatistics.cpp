#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    cout << arr[1] << endl;
    return 0;
}