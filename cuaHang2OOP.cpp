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
        sanPham(int Ma, string name, float value, int kho){
            this->ma = Ma;
            this->ten = name;
            this->gia = value;
            this->tonKho = kho;
        }
    void inThongTin(){
        cout << "Ma: " << ma << endl;
        cout << "Ten: " << ten << endl;
        cout << "Gia: " << gia << endl;
        cout << "Kho: " << tonKho << endl;
    }
    int getMa() { return ma; }
    string getTen() { return ten; }
    float getGia() { return gia; }
    int getTonKho() { return tonKho; }
};
class khachKhach{
    private: 
        int ma, sdt;
        string ten;
    public:
        khachKhach(int Ma, int number, string name){
            this->ma = Ma;
            this->sdt = number;
            this->ten = name;
        }
        virtual float tinhGiam() = 0;

        void inThongTin(){
            cout << "Ma: " << ma << endl;
            cout << "Sdt: " << sdt << endl;
            cout << "Ten: " << ten << endl;
        }
    int getMa(){ return ma;}
    string getTen() { return ten;}
};
class khachHangVip : public khachKhach{
    public:
        khachHangVip(int ma, int sdt, string ten) : khachKhach(ma, sdt, ten) {}
        float tinhGiam() override { return 20.0 ;}
};
class khachHangThuong: public khachKhach{
    public:
        khachHangThuong(int ma, int sdt, string ten) : khachKhach(ma, sdt, ten) {}
        float tinhGiam() override { return 5.0;}
};
class cuaHang{
    private:
        vector<sanPham> sp;
        vector<khachKhach*> kh; // * là con trỏ → lưu địa chỉ object
                        //Không có * → lưu bản sao → mất polymorphism
                        // Có *       → lưu địa chỉ → tinhGiam() gọi đúng VIP/Thuong
    public:
        void themSanPham(sanPham s){
            sp.push_back(s);
        }
        void themKhachHang(int ma, int sdt, string name, string loai){
            if(loai == "VIP"){
                kh.push_back(new khachHangVip(ma, sdt, name));
            }else{
                kh.push_back(new khachHangThuong(ma, sdt, name));
            }
            cout << "Them thanh cong!\n";
        }
        void tinhTien(int maSP, int maKH){
            int indexSP = -1;
            for(int i = 0; i < sp.size();i++){
                if(sp[i].getMa() == maSP){
                    indexSP = i;
                    break;
                }
            }
            if(indexSP == -1){
                cout << "Khong tim thay san pham!\n";
                return;
            }
            int indexKH = -1;
            for(int i = 0;i < kh.size();i++){
                if(kh[i]->getMa() == maKH){
                    indexKH = i;
                    break;
                }
            }
            if(indexKH == -1){
                cout << "Khong tim thay khach hang!\n"; return;
            }
            float gia = sp[indexSP].getGia();
            float phanTram = kh[indexKH]->tinhGiam();
            float giaSau = gia * (1-phanTram/100);

            cout << "Gia goc: " << gia << " VND\n";
            cout << "Giam gia: " << phanTram << "%\n";
            cout << "Gia sau giam: " << giaSau << " VND\n";
        }
        void hienThiSanPham(){
            if(sp.empty()){
                cout << "Rong!" << endl;
                return;
            }
            for(int i = 0;i <sp.size();i++){
                sp[i].inThongTin();
            }
        }
        void hienThiKhachHang(){
            if(kh.empty()){
                cout << "Rong!" << endl;
                return;
            }
            for(int i = 0;i < kh.size();i++){
                kh[i]->inThongTin();
            }
        }
};
void menu(){
    cout << "\n=== MENU ===\n";
    cout << "1.Them san pham\n";
    cout << "2.Them khach hang\n";
    cout << "3.In thong tin khach hang\n";
    cout << "4.In thong tin san pham\n";
    cout << "5.Tinh tien\n";
    cout << "0.Thoat\n";
    cout << "Nhap lua chon cua ban: ";
}
int main(){
    int luaChon;
    cuaHang ch;
    do{
        menu();
        cin >> luaChon;
        switch(luaChon){
            case 1:{
                    int ma; string ten; float gia; int kho;
                    cout << "Nhap ma: "; cin >> ma;
                    cout << "Nhap ten: "; cin.ignore(); getline(cin, ten);
                    cout << "Nhap gia: "; cin >> gia;
                    cout << "Ton kho: "; cin >> kho;
                    ch.themSanPham(sanPham(ma, ten, gia, kho));
                break;
            }
            case 2:{
                int ma, sdt; string ten, loai;
                cout << "Nhap ma: "; cin >> ma;
                cout << "Nhap sdt: "; cin >> sdt;
                cout << "Nhap ten: "; cin.ignore(); getline(cin, ten);
                cout << "Loai(thuong/VIP): "; cin >> loai;
                ch.themKhachHang(ma, sdt, ten, loai);
                break;
            }
            case 3:{
                ch.hienThiKhachHang();
                break;
            }
            case 4:{
                ch.hienThiSanPham();
                break;
            }
            case 5:{
                   int maSP, maKH;
                cout << "Nhap ma san pham: "; cin >> maSP;
                cout << "Nhap ma Khach hang: "; cin >> maKH;
                ch.tinhTien(maSP, maKH);
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