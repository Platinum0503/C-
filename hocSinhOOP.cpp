#include <iostream>
#include <string>
#include <vector>
using namespace std;

class hocSinh{
    public:
        string ten;
        int tuoi;
        float diemToan;
        float diemVan;
    void nhapThongTin(){
        cout << "Nhap ten: ";
        getline(cin, ten); //đọc cả câu có dấu

        cout << "Nhap tuoi: ";
        cin >> tuoi;

        cout << "Nhap diem toan: ";
        cin >> diemToan;

        cout << "Nhap diem van: ";
        cin >> diemVan;

        cin.ignore(); //xoá '\n' còn sót trong buffer sau khi dùng cin >>
    }
    void inThongTin(){
        cout << "Ten: " << ten << '\n';
        cout << "Tuoi: " << tuoi << '\n';
        cout << "D.Toan: " << diemToan << '\n';
        cout << "D.Van: " << diemVan << '\n';
    }
};

int main(){
    vector<hocSinh> danhSach(3); //mảng 3 học sinh

    for(int i = 0; i < 3;i++){
        cout << "Hoc sinh thu " << i+1 << '\n';
        danhSach[i].nhapThongTin();
    }

    for(int i = 0;i < 3;i++){
        danhSach[i].inThongTin();
    }

    return 0;
}