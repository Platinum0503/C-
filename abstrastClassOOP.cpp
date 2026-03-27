#include <iostream>
#include <vector>
using namespace std;

class hinhHoc{
    private:
        string name;
    public:
        hinhHoc(string ten){ this->name = ten; }
        virtual float dienTich() = 0;
        virtual float chuVi() = 0;
        string getName() { return name; }

    void inThongTin(){
        cout << "hinh: " << getName();
        cout << "Dien tich: " << dienTich();
        cout << "Chu vi: " << chuVi();
    }
};
class hinhTron : public hinhHoc{
    private:    
        float r;
    public:
        hinhTron(float banKinh) : hinhHoc("hinh tron") {this->r = banKinh;}
        float dienTich() override{return 3.14*r*r; }
        float chuVi() override{ return 2 * 3.14 * r; }
};
class hinhChuNhat : public hinhHoc{
    private:    
        float a,b;
    public:
        hinhChuNhat(float a, float b) : hinhHoc("hinh chu nhat") {this->a = a; this->b = b;}
        float dienTich() override{ return a * b;}
        float chuVi() override { return 2 * (a+b);}
};
class hinhVuong : public hinhHoc{
    private:
        float a;
    public:
        hinhVuong(float a) : hinhHoc("Hinh vuong") {}
    float dienTich() override{ return a*a;}
    float chuVi() override { return a*4; }
};
int main(){
    vector<hinhHoc*> danhSach; //caution *
    danhSach.push_back(new hinhTron(4));
    danhSach.push_back(new hinhChuNhat(4, 6));
    danhSach.push_back(new hinhVuong(3));

    for(int i = 0; i < danhSach.size();i++){
        danhSach[i]->inThongTin();
        cout << '\n';
    }
    return 0;
}