#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    /* for(int i = 1;i <= n*2;i++){
        if(i == n*2 && m % 2 != 0){
            cout << i;
            return 0;
        }
        cout << ((m+1)/2)+i << " " << i << " ";
    }   */ //cách này chỉ đúng với m <= 2n -> nếu lớn hơn thì sai hoàn toàn

    for(int i = 1;i <= n;i++){
        int nonWinTrai = 2*n +(2*i-1);
        int winTrai = 2*i - 1;
        int nonWinPhai = 2*n + (2*i);
        int winPhai = 2*i;

        if(nonWinTrai <= m) cout << nonWinTrai << " ";
        if(winTrai <= m) cout << winTrai << " ";
        if(nonWinPhai <= m) cout << nonWinPhai << " ";
        if(winPhai <= m) cout << winPhai << " ";
    }

    //cách 2
    int a, b; //a là số hàng, b là số người lên xe
    cin >> a >> b;

    //seat[i] = số thứ tự người ngồi ghế i (0 nếu trống)
    //ghế 1..2n là window, 2n+1..4n là non-window
    vector<int> seat(4*n + 1, 0); //khời tạo mảng vector với độ rộng 4*n+1 -> tất cả giá trị index = 0
    
    //gán người vào ghế theo thứ tự lên xe
    int person = 1;
    for(int i = 1;i <= n && person <= m;i++){
        seat[2*i-1] = person++; //win trái hàng i
        if(person <= m)
        seat[2*i] = person++; //win phai hang i
    }
    //non-window seats sau
    for(int i = 1;i <= m && person <= m;i++){
        seat[2*n + 2*i-1] = person++; //non-window trai hang i
        if(person <= m)
        seat[2*n + 2*i] = person++; // non-window phai hang i
    }

    //xuong xe theo thu tu
    for(int i = 1;i <= n;i++){
        if(seat[2*n + 2*i-1])   cout << seat[2*n + 2*i-1] <<" "; //non-win trai
        if(seat[2*i-1])         cout << seat[2*i-1] << " ";     //win trai
        if(seat[2*n + 2*i])     cout << seat[2*n + 2*i] << " "; //non-win phai
        if(seat[2*i])           cout << seat[2*i] << " ";       //win phai 
    }
    return 0;
}