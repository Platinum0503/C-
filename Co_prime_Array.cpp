#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> result;
    int input;
    for(int i = 0;i < n;i++){
        cin >> input;
        result.push_back(input);
    }
    vector<int> output;
    int k = 0;
    for(int i = 0;i < n;i++){
        output.push_back(result[i]);
        if(i < n-1 && gcd(result[i], result[i+1]) != 1){
            output.push_back(1);
            k++;
        }   
    }
    cout << k << '\n';
    for(int i = 0;i < output.size();i++){
        cout << output[i] << " ";
    }
    return 0;
}