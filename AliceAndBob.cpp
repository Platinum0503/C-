#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int l = 0, r = n-1;
    long long timeAlice = 0, timeBob = 0;
    int countAlice = 0, countBob = 0;
    while(l <= r){
        if(timeAlice <= timeBob){
            timeAlice += arr[l++];
            countAlice++;
        }else{
            timeBob += arr[r--];
            countBob++;
        }
    }
    cout << countAlice << " " << countBob;
    return 0;
}