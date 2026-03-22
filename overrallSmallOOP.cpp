#include <iostream>
#include <vector>
using namespace std;

class sanPham{
    private:
        int ma;
        string tenHang;
        long long gia;
        int soLuong;
    public:     
        sanPham(int Ma, string name, long long value, int count){
            this->ma = Ma;
            this->tenHang = name;
            this->gia = value;
            this->soLuong = count;
        }
    void inThongTin(){
        cout << "Ma: " << ma << " | " << "Ten hang: " << tenHang << " | "
                << "Gia: " << gia << " | " << "So luong: " << soLuong;
    }
    int getMa() { return ma; }
    string getName() { return tenHang; }
    long long getGia() { return gia; }
    int getSoLuong() { return soLuong; }

};
class gioHang{
    private:
        vector<sanPham> danhSach;
        int maGiamGia = 1234;
    public:
        void themSanPham(sanPham s){
            danhSach.push_back(s);
            cout << "Them thanh cong!\n";
        }
        void xoaSanPham(int ma){
            for(int i = 0;i < danhSach.size();i++){
                if(danhSach[i].getMa() == ma){
                    danhSach.erase(danhSach.begin() + i);
                    cout << "Xoa thanh cong!" << endl;
                    return;
                }
            }
            cout << "khong tim thay san pham nao!\n";
        }
        void tinhTong(){
            long long tong = 0;
            for(int i = 0;i < danhSach.size();i++){
                tong += danhSach[i].getGia() * danhSach[i].getSoLuong();
            }
            cout << "Tong: " << tong << " VND" << endl;

            int giamGia;
            cout << "Nhap ma giam gia(neu co | 0 to refuse): ";
            cin >> giamGia;
            if(giamGia == maGiamGia){
                cout << "Giam 10%! tong con: " << tong * 90/100 << " VND\n";
            }else if(giamGia != 0){
                cout << "Ma ko hop le!\n";
            }
        }
        void hienThiThongTin(){
            if(danhSach.empty()){
                cout << "Gio hang rong!\n";
                return;
            }
            for(int i = 0;i < danhSach.size();i++){
                danhSach[i].inThongTin();
            }
        }
};
void menu(){
    cout << "=== MENU ===\n";
    cout << "1.Them san pham\n";
    cout << "2.Xoa san pham\n";
    cout << "3.xem gio hang\n";
    cout << "4.tinh tong tien\n";
    cout << "0.Thoat\n";
}
int main(){
    gioHang gh;
    int luaChon;

    do{
        menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();

        switch(luaChon){
            case 1:{
                    int ma;
                    string tenHang;
                    long long gia;
                    int soLuong;

                    cout << "Nhap ma: ";
                    cin >> ma;
                    cin.ignore();

                    cout << "Nhap ten hang: ";
                    getline(cin, tenHang);

                    cout << "Gia: ";
                    cin >> gia;
                    cout << "so luong: ";
                    cin >> soLuong;
                gh.themSanPham(sanPham(ma, tenHang, gia, soLuong));
                break;
            }
            case 2:{
                int ma;
                cout << "Nhap ma: ";
                cin >> ma;
                gh.xoaSanPham(ma);
                break;
            }
            case 3:{
                gh.hienThiThongTin();
                break;
            }
            case 4:{
                gh.tinhTong();
                break;
            }
            case 0:{
                cout << "Tam biet!" << endl;
                break;
            }
            default:    
                cout << "Nhap khong hop le! (vui long nhap 1-5)" << endl;
        }
    }while(luaChon != 0);

    return 0;
}