#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string x;
    int output = 0;
    for(int i = 0; i < n;i++){
        cin >> x;
            if(x[0] == '+' || x[x.size() - 1] == '+'){
                output++;
            }else{
                output--;
            }
    }
    cout << output;

    return 0;
}