#include <iostream>
#include <string>
using namespace std;

class MatKhau{
    private:
        string matKhau;
    public:
        MatKhau(){
            matKhau = "";
        }
    bool kiemTra(string mk){
        if(mk.length() < 8){
            cout << "Mat khau phai tren 8 ky tu!\n";
            return false;
        }
        bool coSo = false;
            for(int i = 0; i < mk.length();i++){
                if(isdigit(mk[i])){    //dùng isdigit() để kiểm tra ký tự có phải số không
                    coSo = true;
                    break;
                }
            }
            if(!coSo){
                cout << "Mat khau phai co it nhat 1 so!\n";
                return false;
            }
        return true;
    }
    void datMatKhau(){
        string mk;
        cout << "Nhap mk cua ban(8 ky tu va 1 number): ";
        cin >> mk;
        if(kiemTra(mk)){
            matKhau = mk;
            cout << "Dat mat khau thanh cong!\n";
        }
    }
    void dangNhap(){
        string mk;
        cout << "Nhap mat khau: ";
        cin >> mk;
        if(mk == matKhau){
            cout << "Dang nhap thanh cong!\n";
        }else {
            cout << "Dang nhap khong thanh cong!\n";
        }
    }
};

int main(){
    MatKhau tk;
    tk.datMatKhau();

    tk.dangNhap();

    return 0;
}