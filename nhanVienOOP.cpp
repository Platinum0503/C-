#include <iostream>
#include <vector>
using namespace std;

class nhanVien{
    private:    
        int ma;
        string ten;
        long long luongCoBan;
    public:
        nhanVien(int Ma, string name, long long salary){
            this->ma = Ma;
            this->ten = name;
            this->luongCoBan = salary;
        }
    virtual void tinhLuong(){
        cout << "Luong co ban: " << luongCoBan;
    }
    int getMa() { return ma; }
    string getTen() { return ten; }
    float getLuong() { return luongCoBan; }
};
class nhanVienVanPhong : public nhanVien{
    private:   
        long long phuCap = 500;
    public:
        nhanVienVanPhong(int ma, string ten, long long phuCap, long long salary) : nhanVien(ma, ten, salary) {
            this->phuCap = phuCap;
        }
    void tinhLuong() override{
        cout << getTen() << " (Van phong) - luong: "
            << getLuong() + phuCap << " VND\n";
    }
};
class nhanVienSanXuat : public nhanVien{
    private:
        int soCa = 200;
    public:
        nhanVienSanXuat(int ma, string ten, int soCa, long long salary) : nhanVien(ma, ten, salary) {
            this->soCa = soCa;
        }
    void tinhLuong() override{
        cout << getTen() << " (san xuat) - luong: "
            << getLuong() + 200*soCa << " VND\n";
    }
};
class quanLy : public nhanVien{
    private: 
        long long thuong = 1000;
    public:
        quanLy(int ma, string ten, long long thuong, long long salary) : nhanVien(ma, ten, salary) {
            this->thuong = thuong;
        }
    void tinhLuong() override{
        cout << getTen() << " (Quan ly) - luong: "
            << getLuong() + thuong << " VND\n";
    }
};
int main(){
    vector<nhanVien*> danhSach; 
    danhSach.push_back(new nhanVienVanPhong(1, "Huy", 500,5000));
    danhSach.push_back(new nhanVienSanXuat(2, "Khoi", 5, 7000));
    danhSach.push_back(new quanLy(3, "Loi", 1000, 10000));

    for(int i = 0;i < danhSach.size();i++){
        danhSach[i]->tinhLuong();
    }

    return 0;
}