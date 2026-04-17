#include <iostream>
#include <string>
using namespace std;

bool isRXCY(string s){
    if(s[0] != 'R') return false;

    int i = 1;
    while(i < s.size() && isdigit(s[i])) i++;
    if(i == 1 || s[i] != 'C') return false;
    i++;
    while(i < s.size() && isdigit(s[i])) i++;
    return i == s.size();
}
int chuToSo(string s){
    int col = 0;
    for(int i = 0;i < s.size();i++){
        col = col * 26 + (s[i] - 'A' + 1);
    }
    return col;
}
string soToChu(int n){
    string result = "";
    while(n > 0){
        n--;
        result = char('A' + n%26) + result;
        n /= 26;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(isRXCY(s)){
            int i = 1;
            string hang = "", cot = "";
            while(isdigit(s[i])) hang += s[i++]; //lấy số sau R
            i++; //skip qua C
            while(i < s.size()) cot += s[i++]; //lấy số sau C

            cout << soToChu(stoi(cot)) << hang << '\n';
        //stoi() = string to int, chuyển chuỗi "55" thành số 55    
        }else{
            string chu = "", so = "";
            int i = 0;
            while(isalpha(s[i])) chu+= s[i++]; //lấy phần chữ
            //isalpha kiểm tra có phải chữ cái không
            while(i < s.size()) so += s[i++]; //lấy phần số
            cout << "R" << so << "C" << chuToSo(chu) << '\n';
        }
    }
    return 0;
}