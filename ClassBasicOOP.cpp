#include <iostream>
#include <vector>
using namespace std;

class sanPham {
    private:
        int ma;
        string ten;
        float gia;
        int soLuong;
    public:
        sanPham(int Ma, string name, float prices, int count){
            ma = Ma;
            ten = name;
            gia = prices;
            soLuong = count;
        }
    void inThongTin(){
        cout << "ma: " << ma << '\n';
        cout << "ten: " << ten << '\n';
        cout << "gia: " << gia << '\n';
        cout << "so luong: " << soLuong << '\n';
    }
    void giamGia(float phamTram){
        gia = gia * (1 - phamTram/ 100);
        cout << "gia sau giam: " << gia << endl;
    }
};

int main(){
    vector<sanPham> danhSach;
    danhSach.push_back(sanPham(1, "Ao thun", 150000, 10));
    danhSach.push_back(sanPham(2, "Quan jean", 300000, 5));
    danhSach.push_back(sanPham(3, "Giay",   500000, 3));

    cout << "===Danh sach san pham===\n";
    for(int i = 0;i < danhSach.size();i++){
        danhSach[i].inThongTin();
    }
    cout << "\n=== GIAM GIA ===\n";
    danhSach[0].giamGia(10); //giam 10%
    danhSach[1].giamGia(20); //giam 20%

    return 0;
}