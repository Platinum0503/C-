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
        sanPham(int Ma, string name, float price, int kho){
            this->ma = Ma;
            this->ten = name;
            this->gia = price;
            this->tonKho = kho;
        }
    void inThongTin(){
        cout << "Ma: " << ma << '\n';
        cout << "Ten: " << ten << '\n';
        cout << "Gia: " << gia << '\n';
        cout << "ton kho: " << tonKho << '\n';
    }
    void giamGia(float phanTram){
        cout << "Giam gia: " << gia*phanTram/100 << '\n'; //caution
    } 
    int getMa() { return ma; }
    string getTen() { return ten; }
    float getGia() { return gia; }
    int getKho() { return tonKho;}
};
class khachHang{
    private:    
        int ma;
        string ten;
        int sdt;
    public:
        khachHang(int Ma, string name, int number){
            this->ma = Ma;
            this->ten = name;
            this->sdt = number;
        }
    virtual float tinhGiam() = 0; //caution
    void inThongTin(){
    cout << "Ma: " << ma << " | Ten: " << ten << " | SDT: " << sdt << '\n';
    }
    int getMa() {return ma;}
    string getTen() { return ten; }
};
class khachHangVIP : public khachHang{
    private:
        int giamGia = 20;
    public:
        khachHangVIP(int MA, string name, int number) : khachHang(MA, name, number) {
            this->giamGia = giamGia;
        }
    float tinhGiam() override{
       return 20.0;
    }
};
class khachHangThuong : public khachHang{
    private:
        int giamGia = 5;
    public:
        khachHangThuong(int MA, string name, int number) : khachHang(MA, name, number){
            this->giamGia = giamGia;
        }
    float tinhGiam() override{
        return 5.0;
    }
};
class cuaHang{
    private:
        vector<sanPham> sp;
        vector<khachHang*> khach;
    public:
        void themSanPham(sanPham s){
            sp.push_back(s);
            cout << "Them thanh cong!\n";
        }
        void themKhachHang(int ma, string ten, int sdt, string loai){
            if(loai == "vip"){
                khach.push_back(new khachHangVIP(ma, ten, sdt));
            }else{
                khach.push_back(new khachHangThuong(ma, ten, sdt));
            }
            cout << "Them thanh cong!" << endl;
        }
        void tinhTien(int maKH, int maSP){
            int indexSP = -1;
            for(int i = 0;i < sp.size();i++){
                if(sp[i].getMa() == maSP){
                    indexSP = i;
                    break;
                }
            }
            if(indexSP == -1){
                cout << "khong tim thay SP!\n"; return;
            }
            int indexKH = -1;
            for(int i = 0;i < khach.size();i++){
                if(khach[i]->getMa() == maKH){
                    indexKH = i;
                    break;
                }
            }
            if(indexKH == -1){ cout << "khong tim thay khach hang!\n"; return; }

            float gia = sp[indexSP].getGia();
            float phanTram = khach[indexKH]->tinhGiam();
            float giaSau = gia * (1 - phanTram/100); //caution

            cout << "Gia goc: " << gia << " VND\n";
            cout << "Giam gia: " << phanTram << "%\n";
            cout << "Gia sau giam: " << giaSau << " VND\n";
        }
        void hienThiSanPham(){
            if(sp.empty()){
                cout << "Rong!\n";
                return;
            }
            for(int i = 0;i < sp.size();i++){
                sp[i].inThongTin();
            }
        }
        void hienThiKhachHang(){
            if(khach.empty()){
                cout << "Danh sach rong!\n"; return;
            }
            for(int i = 0;i < khach.size();i++){
                khach[i]->inThongTin();
            }
        }
};
void menu(){
    cout << "\n=== MENU ===\n";
    cout << "1.Them san pham\n";
    cout << "2.Them khach hang\n";
    cout << "3.Mua hang\n";
    cout << "4.Xem danh sach san pham\n";
    cout << "5.Xem danh sach khach hang\n";
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
                cout << "Ma: "; cin >> ma;
                cout << "Ten: "; cin.ignore(); getline(cin, ten);
                cout << "Gia: "; cin >> gia;
                cout << "Ton kho: "; cin >> kho;
                ch.themSanPham(sanPham(ma, ten, gia, kho));
                break;
            }
            case 2:{
                int ma, sdt; string ten, loai;
                cout << "Ma: "; cin >> ma;
                cout << "Ten: "; cin.ignore(); getline(cin, ten);
                cout << "SDT: "; cin >> sdt;
                cout << "Loai(vip/thuong): "; cin >> loai;
                ch.themKhachHang(ma, ten, sdt, loai);
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
                cout << "Nhap khong hop le!(Nhap lai: )";
            }
        }
    }while(luaChon != 0);
    return 0;
}