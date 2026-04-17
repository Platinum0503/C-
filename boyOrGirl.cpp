#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int count = 0;
    sort(s.begin(), s.end());
    for(int i = 0;i < s.size();i++){
        if(i == 0 || s[i] != s[i-1]){
            count++;
        }
    }
    if(count % 2 == 0){
        cout << "CHAT WITH HER!" << endl;
    }else {
        cout << "IGNORE HIM!" << endl;
    }
    return 0;
}