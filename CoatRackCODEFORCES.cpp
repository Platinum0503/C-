#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int line1[2];
    for(int i = 0; i < 2;i++){
        cin >> line1[i];
    }

    vector<int> line2(line1[0]);
    for(int i = 0;i < line1[0];i++){
        int khach;
        cin >> khach;
        line2[i] = khach;
    }

    int m;
    cin >> m;

    sort(line2.begin(), line2.end());

    int loiNhuan = 0;
    int hookDung = min(m, line1[0]);
    for(int i = 0; i < hookDung;i++){
        loiNhuan += line2[i];
    }
    
    if(m > line1[0]){
        loiNhuan = loiNhuan - (m-line1[0]) * line1[1];
    }
    cout << loiNhuan;

    return 0;
}