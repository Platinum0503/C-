#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> number;
    string input; 
    getline(cin, input);
    for(int i = 0;i < input.length();i++){
        if(isdigit(input[i])){
            number.push_back(input[i] - '0');
        }
    }
    sort(number.begin(), number.end());
    for(int i = 0; i < number.size();i++){
        if(i > 0) cout << "+";
        cout << number[i];
    }
    return 0;
}