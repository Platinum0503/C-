#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class observer{
    protected:
        string ten;
    public:
        observer(string name){
            this->ten = name;
        }
        virtual void nhanThongBao(string tb) = 0;
};
class khachHang : public observer{
    public:
        khachHang(string ten) : observer(ten) {}
        void nhanThongBao(string tb) override{
             cout << ten << " nhan: " << tb << "\n";
        }
};
class sanPham{
    protected:
        string ten, trangThai;
        vector<observer*> danhSach; // * vì abstract ??
    public:
        sanPham(string ten){
            this->ten = ten;
            this->trangThai = "chua xac dinh";
        }
        void dangKy(observer* ob){
            danhSach.push_back(ob);
        }
        void huyDangKy(observer* ob){
             for(int i = 0; i < danhSach.size(); i++){
                if(danhSach[i] == ob){
                    danhSach.erase(danhSach.begin() + i);
                    cout << "Huy dang ky thanh cong!\n";
                    return;
                }
            }  
        }
        void thongBao(string tb){
            for(int i = 0; i < danhSach.size(); i++){
                danhSach[i]->nhanThongBao(tb);
            }
        }
        void capNhapTrangThai(string tt){
            trangThai = tt;
                thongBao(ten + " - " + trangThai);  // Tự động thông báo
        }
        virtual void inThongTin(){
            cout << "Ten: " << ten << "\n";
            cout << "Trang thai: " << trangThai << "\n";
        }
};
class sanPhamThucPham : public sanPham{
    private:   
        string hanSuDung;
    public: 
        sanPhamThucPham(string ten, string han) : sanPham(ten){
            this->hanSuDung = han;
        }
        void inThongTin() override{
            sanPham::inThongTin();
            cout << "\nHan su dung: " << hanSuDung << '\n';
        }
};
class sanPhamDienTu : public sanPham{
    private:    
        int baoHanh;
    public:
        sanPhamDienTu(string ten, int bh) : sanPham(ten){
            this->baoHanh = bh;
        }
        void inThongTin() override{
            sanPham::inThongTin();
            cout << "\nBao hanh: " << baoHanh << '\n';
        }
};
class sanPhamFactory{
    public:
        static sanPham* tao(string loai, string ten, string hsd = "", int bh = 0){
            if(loai == "thucpham") return new sanPhamThucPham(ten, hsd);
            if(loai == "dientu") return new sanPhamDienTu(ten, bh);
                return new sanPham(ten); //???
        }
};
class cuaHangConfig{ //singleton
    private:
        static cuaHangConfig* instance;
        cuaHangConfig() {} //này là sao?
        string name = "My shop";
        string phienBan = "1.0.0";
        string ngonNgu = "Vietnamese";
    public:
        static cuaHangConfig* getInstance(){
            if(instance == nullptr){
                instance = new cuaHangConfig(); //caution
            }
            return instance;
        } //mik cứ quên static dùng để làm j 
        void hienThiCauHinh(){
            cout << "Ten cua hang: " << name << '\n';
            cout << "Phien ban: " << phienBan << '\n';
            cout << "Ngon ngu: " << ngonNgu << '\n';
        }
        void setNgonNgu(string n){
            ngonNgu = n;
            cout << "Set thanh cong ngon ngu thanh: " << n << '\n';
        }
};
cuaHangConfig* cuaHangConfig::instance = nullptr; //khởi tạo
int main(){
    cuaHangConfig* config = cuaHangConfig::getInstance(); //vì sao là get
    config->hienThiCauHinh();

    //factory
    sanPham* sp1 = sanPhamFactory::tao("dientu",   "iphone", "", 12);
    sanPham* sp2 = sanPhamFactory::tao("thucpham", "sua", "2025-12-31");

    //observer
    khachHang kh1("An");
    khachHang kh2("Binh");

    sp1->dangKy(&kh1);
    sp1->dangKy(&kh2);

    sp1->capNhapTrangThai("Het hang");
    //an & binh nhan thong bao

    sp1->huyDangKy(&kh2);
    sp1->capNhapTrangThai("Co hang");
    //chi an nhan thong bao
    return 0;
}