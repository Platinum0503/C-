#include <iostream>
#include <vector>
using namespace std;

class sanPham{
    private:
        int ma;
        string ten;
        float gia;
        int tonKho;
    public:
        sanPham(int MA, string name, float value, int kho){
            this->ma = MA;
            this->ten = name;
            this->gia = value;
            this->tonKho = kho;
        }
    void inThongTin(){
        cout << "Ma: " << ma << " | " << "Ten: " << ten << " | "
            << "Gia: " << gia << " | " << "Ton kho: " << tonKho << endl;
    }
    int getMa() { return ma;}
    string getTen() { return ten;}
    float getGia() { return gia;}
    int getKho() { return tonKho;}
};
class khachHang{
    private:
        int ma, sdt;
        string ten;
    public:
        khachHang(int MA, int number, string name){
            this->ma = MA;
            this->sdt = number;
            this->ten = name;
        }
    virtual float tinhGiam() = 0; //pure virtual

    void inThongTin(){
        cout << "Ma: " << ma << " | " << "SDT: " << sdt << " | " 
            << "Ten: " << ten << endl;
    }
    int getMa(){ return ma;}    //getter
    string getTen() { return ten;}
};
class khachHangVip : public khachHang{
    private:    
        
    public:
        khachHangVip(int Ma, int number, string name) : khachHang(Ma, number, name) {}
    float tinhGiam() override{
        return 20.0;
    }
};
class khachHangThuong: public khachHang{
    private:    
       
    public:
        khachHangThuong(int Ma, int number, string name) : khachHang(Ma, number, name) {}
    float tinhGiam() override{
        return 5.0;
    }
};
class cuaHang{
    private:
        vector<sanPham> danhSachSP;
        vector<khachHang*> danhSachKH; //caution *
    public:
        void themSanPham(sanPham s){
            danhSachSP.push_back(s);
        }
        void themKhachHang(int ma, int sdt, string name, string loai){
            if(loai == "VIP"){
                danhSachKH.push_back(new khachHangVip(ma, sdt, name));
            }else{
                danhSachKH.push_back(new khachHangThuong(ma, sdt, name));
            }
            cout << "Them thanh cong!\n";
        }
        void tinhTien(int maKH, int maSP){
            int indexKH = -1;
            for(int i = 0;i < danhSachKH.size();i++){
                if(danhSachKH[i]->getMa() == maKH){
                    indexKH = i;
                    break;
                }
            }
            if(indexKH == -1){
                cout << "Khong tim thay khach hang!\n"; return;
            }
            int indexSP = -1;
            for(int i = 0;i < danhSachSP.size();i++){
                if(danhSachSP[i].getMa() == maSP){
                    indexSP = i;
                    break;
                }
            }
            if(indexSP == -1){
                cout << "Khong tim thay san pham!\n"; return ;
            }
            float gia = danhSachSP[indexSP].getGia();
            float phanTram = danhSachKH[indexKH]->tinhGiam();
            float giaSau = gia * (1 - phanTram/100); //caution

            cout << "Gia goc: " << gia << " VND\n";
            cout << "Giam gia: " << phanTram << "%\n";
            cout << "Gia sau giam: " << giaSau << " VND\n";
        }
        void hienThiSanPham(){
            if(danhSachSP.empty()){
                cout << "Rong!\n";
                return;
            }
            for(int i = 0;i < danhSachSP.size();i++){
                danhSachSP[i].inThongTin();
            }
        }
        void hienThiKhachHang(){
            if(danhSachKH.empty()){
                cout << "Rong!\n";
            }
            for(int i = 0;i < danhSachKH.size();i++){
                danhSachKH[i]->inThongTin();
            }
        }
};
void menu(){
    cout << "\n=== MENU ===\n";
    cout << "1.Them san pham\n";
    cout << "2.Them khach hang\n";
    cout << "3.Mua hang\n";
    cout << "4.Xem danh sach sp\n";
    cout << "5.Xem danh sach KH\n";
    cout << "0.Thoat\n";
}
int main(){
    int luaChon;
    cuaHang ch;
    do{
        menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        switch(luaChon){
            case 1:{
                    int ma; string ten; float gia; int kho;
                    cout << "Nhap ma: "; cin >> ma;
                    cout << "Nhap ten: "; cin.ignore(); getline(cin, ten);
                    cout << "Nhap gia: "; cin >> gia;
                    cout << "Nhap kho: "; cin >> kho;
                    ch.themSanPham(sanPham(ma, ten, gia, kho));
                    break;
            }
            case 2:{
                int ma, sdt; string ten, loai;
                cout << "Ma: "; cin >> ma;
                cout << "Ten: "; cin.ignore(); getline(cin, ten);
                cout << "SDT: "; cin >> sdt;
                cout << "Loai(vip/thuong): "; cin >> loai;
                ch.themKhachHang(ma, sdt, ten, loai);
                break;
            }
            case 3:{
                    int maKH, maSP;
                cout << "Ma khach hang: "; cin >> maKH;
                cout << "Ma san pham: "; cin >> maSP;
                ch.tinhTien(maKH, maSP);
                break;
            }
            case 4:{
                    ch.hienThiSanPham();
                break;
            }
            case 5:{
                ch.hienThiKhachHang();
                break;
            }
            case 0:{
                cout << "Tam biet!\n";
                break;
            }
            default:{
                cout << "Nhap ko hop le!(Nhap lai): ";
            }
        }
    }while(luaChon != 0);
    return 0;
}