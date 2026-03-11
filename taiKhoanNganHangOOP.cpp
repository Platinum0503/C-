#include <iostream>
using namespace std;

class taiKhoanNganHang{
    private:
        string tenChuTaiKhoan;
        float soDu = 10000;
    public:
        taiKhoanNganHang(string ten, float soDuBanDau){
            tenChuTaiKhoan = ten;
            soDu = soDuBanDau;
        }
    void napTien(){
        float tienNap;
        cout << "nhap so tien ban muon nap: ";
        cin >> tienNap;
        soDu = soDu + tienNap;
        cout << "Nap tien thanh cong!\n";
        cout << "So du hien tai cua ban la: " << soDu;
    }
    void rutTien(){
        float tienRut;
        cout << "Nhap so tien ban muon rut: ";
        cin >> tienRut;
        if(tienRut > soDu){
            cout << "So du cua ban khong du!" << endl;
        } else {
            cout << "Rut thanh cong " << tienRut << "\n";
            soDu = soDu - tienRut;
            cout << "So tien con lai cua ban la: " << soDu << endl;
        }
    }
    void xemSoDu(){
        cout << "So du con lai cua ban la: " << soDu << endl;
    }
};
void menu(){
    cout << "\n=== DICH VU NGAN HANG ===\n";
    cout << "1.Rut tien\n";
    cout << "2.Nap tien\n";
    cout << "3.Xem so du\n";
    cout << "0.Thoat\n";
}
int main(){
    taiKhoanNganHang people("Nguyen Van A", 10000);
    
    int input;
    do {
        menu();
        cin >> input;

        switch(input){
            case 1: people.rutTien();
                break;
            case 2: people.napTien();
                break;
            case 3: people.xemSoDu();
                break;
            case 0: 
                cout << "Tam biet!" << endl;
                break;
            default:
                cout << "Nhap khong hop le! Vui long nhap (1-3)";
                break;
        }
    }while(input != 0);

    return 0;
}