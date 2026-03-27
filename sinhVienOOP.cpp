#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class sinhVien{
    private:
        int ma;
        string ten;
        float diemToan, diemLy, diemHoa;
    public:
        sinhVien(int Ma, string name, float toan, float ly, float hoa){
            this->ma = Ma;
            this->ten = name;
            this->diemToan = toan;
            this->diemLy = ly;
            this->diemHoa = hoa;
        }
    float tinhDiemTB(){
        float tb;
        tb = (diemHoa+diemLy+diemToan)/3;
        return tb;
    }
    string xepLoai(){
        if(tinhDiemTB() >= 8){
            return "Gioi";
        }else if(tinhDiemTB() >= 6.5){
            return "Kha";
        }else if(tinhDiemTB() >= 5){
            return "Trung binh";
        }
        return "Yeu";
    }
    void inThongTin(){
        cout << "Ma: " << ma << " | " << "Ten: " << ten << " | " 
            << "Diem toan: " << diemToan << " | " << "Diem hoa: " << diemHoa << " | "
            << "Diem ly: " << diemLy << endl;
    }
    int getMa() { return ma; }
    string getTen() { return ten; }
    float getToan() { return diemToan;} 
    float getHoa() { return diemHoa; }
    float getLy() { return diemLy; }
};
class lopHoc{
    private:
        string tenLop;
        vector<sinhVien> lop;
    public:
        lopHoc(string ten) { tenLop = ten;}
        void themSinhVien(sinhVien sv){
            for(int i = 0;i < lop.size();i++){
                lop.push_back(sv);
                cout << "Them thanh cong!\n";
            }
        }
        void hienThi(){
            for(int i = 0;i < lop.size();i++){
                lop[i].inThongTin();
            }
        }
        void timSinhVien(){
            string name;
            cout << "Nhap ten can tim: ";
            cin >> name;
            for(int i = 0;i < lop.size();i++){
                if(lop[i].getTen() == name){
                    cout << "tim thay: " << name;
                    lop[i].inThongTin();
                }
            }
        }
        void xepHang(){
            for(int i = 0;i < lop.size();i++){
                sort(lop.begin(), lop.end(), [](sinhVien a, sinhVien b){
                    return a.tinhDiemTB() > b.tinhDiemTB();
                });
                }
                for(int i = 0; i < lop.size();i++){
                lop[i].inThongTin();
            }
        }
};
void menu(){
    cout << "\n=== Sinh Vien ===\n";
    cout << "1.Them sinh vien\n";
    cout << "2.Hien thi danh sach\n";
    cout << "3.Tim sinh vien theo ten\n";
    cout << "4.Xem bang xep hang\n";
    cout << "0.Thoat";
}
int main(){
    lopHoc lop("CNTT01");
    int luaChon;

    do{
        menu();
        cin >> luaChon;

        switch(luaChon){
            case 1:{
                    int ma;
                    string ten;
                    float toan, ly, hoa;

                    cout << "Nhap ma: ";
                    cin >> ma;

                    cout << "Nhap ten: ";
                    cin.ignore();
                    getline(cin, ten);

                    cout << "Nhap diem toan: ";
                    cin >> toan;
                    cout << "Nhap diem ly: ";
                    cin >> ly;
                    cout << "Nhap diem hoa: ";
                    cin >> hoa;

                    lop.themSinhVien(sinhVien(ma, ten, toan, ly, hoa));
                    cout << "Them thanh cong!\n";
                break;
            }
            case 2:{
                    lop.hienThi();
                break;
            }
            case 3:{
                string ten;
                cout << "Nhap ten can tim: ";
                cin >> ten;
                cin.ignore();
                //dung lopHoc
                break;
            }
            case 4:{
                    lop.xepHang();
                break;
            }
            case 0:{
                cout << "Tam biet!\n";
                break;
            }
            default: {
                cout << "Nhap khong hop le! nhap lai: ";
            }
        }
    }while(luaChon != 0);
    return 0;
}