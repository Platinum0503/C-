#include <iostream>
#include <vector>
using namespace std;

class sanPham{
    private:
        int ma;
        string ten;
        double gia;
        int soLuong;
    public:
        sanPham(int Ma, string name, double value, int count){
            this->ma = Ma;
            this->ten = name;
            this->gia = value;
            this->soLuong = count;
        }
    void inThongTin(){
        cout << "Ma: " << ma << " | " << "Ten: " << ten << " | "
            << "Gia: " << gia << " | " << "So luong: " << soLuong << endl;
    }
    int getMa() { return ma; }
    string getTen() { return ten; }
    double getGia() { return gia; }
    int getSoLuong() { return soLuong; }
};
class gioHang{
    private:
        vector<sanPham> gioHang;
        int maGiamGia = 1234;
    public:
        void themGiohang(sanPham s){
            gioHang.push_back(s);
            cout << "Them vao gio hang thanh cong!\n";
        }
        void xoaSanPham(int ma){
            for(int i = 0;i < gioHang.size();i++){
                if(gioHang[i].getMa() == ma){
                    gioHang.erase(gioHang.begin() + i);
                    cout << "Xoa thanh cong!\n";
                    return;
                }
            }
        }
        void hienThi(){
            if(gioHang.empty()){
                cout << "Gio hang rong!\n";
                return;
            }
            for(int i = 0; i < gioHang.size();i++){
                gioHang[i].inThongTin();
                return;
            }
        }
        void tinhTong(){
            int MA;
            double tong = 0;
            for(int i = 0; i < gioHang.size();i++){
                tong += gioHang[i].getGia() * gioHang[i].getSoLuong();
            }
            cout << "Tong: " << tong << '\n';
            cout << "Nhap ma giam gia(neu co | 0 de huy): ";
            cin >> MA;
            if(MA == 0){
              cout << "Tong: " << tong << '\n';  
            } else if(MA == maGiamGia){
                cout << "Giam thanh cong 10%\n";
                cout << "Tong: " << tong-tong/100*10;
            }
        }
};
void menu(){
    cout << "\n=== MENU === \n";
    cout << "1.Them san pham\n";
    cout << "2.Xoa gio hang\n";
    cout << "3.Xem gio hang\n";
    cout << "4.Ting tong tien\n";
    cout << "0.Thoat\n";
}
int main(){
    gioHang gh;
    int luaChon;

    do{
        menu();
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();
        switch(luaChon){
            case 1:{
                int ma;
                string ten;
                double gia;
                int soLuong;
                cout << "Nhap ma: ";
                cin >> ma;
                cin.ignore();
                cout << "Nhap ten: ";
                getline(cin, ten);
                cout << "Nhap gia: ";
                cin >> gia;
                cout << "Nhap so luong: ";
                cin >> soLuong;
                gh.themGiohang(sanPham(ma, ten, gia, soLuong));
                break;
            }
            case 2:{
                int Ma;
                cout << "Nhap ma muon xoa: ";
                cin >> Ma;  
                gh.xoaSanPham(Ma);
                break;
            }
            case 3:{
                gh.hienThi();
                break;
            }
            case 4:{
                gh.tinhTong();
                break;
            }
            case 0:{
                cout << "Tam biet!\n";
                break;
            }
            default:{
                cout << "Nhap khong hop le! Nhap lai:";
            }
        }
    }while(luaChon != 0);
    return 0;
}