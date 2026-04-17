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
            ma = Ma;
            ten = name;
            luongCoBan = salary;
        }
    virtual long long tinhLuong(){
        return luongCoBan;
    }
    string getName() { return ten; }
    long long getLuong() { return luongCoBan; }
};
class nhanVienVanPhong : public nhanVien{
    private:
        int soCa;
    public:
        nhanVienVanPhong(int Ma, string name, long long salary, int soCa) : nhanVien(Ma, name, salary) {this->soCa = soCa;}
    long long tinhLuong() override{
        return getLuong() + soCa * 200000;
    }    
};
class nhanVienSanXuat : public nhanVien{
    private:
        int phuCap;
    public:
        nhanVienSanXuat(int Ma, string name, long long salary, int phuCap) : nhanVien(Ma, name, salary) {this->phuCap = phuCap;}
    long long tinhLuong() override {
        return getLuong() + phuCap;
    }
};
class quanLy : public nhanVien{
    private:
        long long thuong;
    public:
        quanLy(int Ma, string name, long long salary, long long thuong) : nhanVien(Ma, name, salary) {this->thuong = thuong;}
    long long tinhLuong() override {
        return getLuong() + thuong;
    }
};
int main(){
    vector<nhanVien*> danhSach;

    danhSach.push_back(new nhanVienVanPhong(1, "khoi", 15000000,5));
    danhSach.push_back(new nhanVienSanXuat(2, "huy", 12000000, 200000));
    danhSach.push_back(new quanLy(3, "linh", 20000000, 1000000));

    long long tongQuy = 0;
    for(int i = 0;i < danhSach.size();i++){
        cout << danhSach[i]->getName() << ": "
            << danhSach[i]->tinhLuong() << " VND\n";
        tongQuy += danhSach[i]->tinhLuong();
    }
    cout << "Tong quy: " << tongQuy << endl;

    return 0;
}