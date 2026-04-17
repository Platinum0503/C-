#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    string m;

    cin >> n;
    cin >> m;

    if(n.length() != m.length()){
        return 0;
    }
    for(int i = 0; i < n.size();i++){
        if(n[i] != m[i]){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    return 0;
}