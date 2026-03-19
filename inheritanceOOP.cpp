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
    virtual void bonus(){
        cout << "..." << endl;
    }
    string getname() { return ten; }
    float getLuong() { return luongCoBan; }
};
class nhanVienVanPhong : public nhanVien{
    private:
        long long phuCap; //caution
    public:
        nhanVienVanPhong(int Ma, string name, long long salary, long long phuCap) : nhanVien(Ma, name, salary) { this->phuCap = phuCap;}
    long long tinhLuong() override{
        return getLuong() + phuCap;
    }
};
class nhanVienSanXuat : public nhanVien{
    private:
        int soCa;
    public:
        nhanVienSanXuat(int Ma, string name, long long salary, int soCa) : nhanVien(Ma, name, salary) {this->soCa = soCa;}
    long long tinhLuong() override{
        return getLuong() + soCa * 200000; //mỗi ca + 200k  
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
    vector<nhanVien*> danhSach; //caution *
    danhSach.push_back(new nhanVienVanPhong(1, "Khoi", 15000000,500000));
    danhSach.push_back(new nhanVienSanXuat(2, "minh", 12000000, 5));
    danhSach.push_back(new quanLy(3, "Linh", 20000000,1000000));
    
    // Polymorphism - gọi tinhLuong() đúng loại
    long long tongQuy = 0;
    for(int i = 0;i < danhSach.size();i++){
        cout << danhSach[i]->getname() << ": "
            <<danhSach[i]->tinhLuong() << " VND\n";
        tongQuy += danhSach[i]->tinhLuong();
    }
    cout << "Tong quy luong: " << tongQuy << " VND\n";

    return 0;
}