#include <iostream>
#include <vector>
using namespace std;

class sach{
    private:
        int ma;
        string ten;
        string tacGia;
        int namXuatBan;
    public:
        sach(int Ma, string name, string tg, int namXB){
            this->ma = Ma;
            this->ten = name;
            this->tacGia = tg;
            this->namXuatBan = namXB;
        }
    void inThongTin(){
        cout << "Ma: " << ma << " | " << "Ten: " << ten << " | "
            << "Tac gia: " << tacGia << " | " << "nam xuat ban: " << namXuatBan;
    }
    int getMa() { return ma; }
    string getTen() { return ten; }
    string getTacGia() { return tacGia; }
    int getNamXB() {  return namXuatBan; }
};
class docGia{
    private:
        vector<sach> sachDangMuon;
        int ma;
        string ten;
    public:
        docGia(int Ma, string name){
            this->ma = Ma;
            this->ten = name;
        }
    string getTen() { return ten; }
    int getMa() {  return ma; }
        void muonSach(sach s){
            sachDangMuon.push_back(s);
        }    
        void traSach(int maSach){
            for(int i = 0; i < sachDangMuon.size();i++){
                if(sachDangMuon[i].getMa() == maSach){
                    sachDangMuon.erase(sachDangMuon.begin() + i);
                    cout << "Xoa danh sach thanh cong!" << endl;
                    return;
                }
            }
        }
        void inSachDangMuon(){
            if(sachDangMuon.empty()){
                cout << "danh sach rong!" << endl;
            }
            for(int i = 0;i < sachDangMuon.size();i++){
                sachDangMuon[i].inThongTin();
            }
        }
};
class thuVien{
    private:
        vector<sach> danhSachSach;
        vector<docGia> danhSachDocGia;
    public:
        void themSach(sach s){
            danhSachSach.push_back(s);
        }
        int timSach(string ten){
            for(int i = 0;i < danhSachSach.size();i++){
                if(danhSachSach[i].getTen() == ten){
                    return i;
                }
            }
            return -1;

        }
        void hienThiSach(){
            for(int i = 0; i < danhSachSach.size();i++){
                danhSachSach[i].inThongTin();
            }
        }
        void choMuon(docGia& dg, string tenSach){
            int index = timSach(tenSach);
            if(index == -1){
                cout << "Khong tim thay sach!" << endl;
                return;
            }
            dg.muonSach(danhSachSach[index]);
            danhSachSach.erase(danhSachSach.begin() + index);
            cout << "Cho muon thanh cong!" << endl;
        }
};
void menu(){
    cout << "=== THU VIEN ===" << endl;
    cout << "1.Xem danh sach sach" << endl;
    cout << "2.Xem danh sach doc gia" << endl;
    cout << "3.Them sach" << endl;
    cout << "4.Cho muon" << endl;
    cout << "5.Tra sach" << endl;
    cout << "6.Tim sach" << endl;
    cout << "7.Tim kiem sach (theo ten/tac gia)" << endl;
    cout << "8.Hien thi danh sach" << endl;
    cout << "0.Thoat" << endl;
}
int main(){
    thuVien tv;
    docGia dg(1, "Nguyen van A");

    int luaChon;
    do{
        menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        switch(luaChon){
            case 1: {
                    tv.hienThiSach();
                break;
            }
            case 2: {
                    dg.inSachDangMuon();
                break;
            }
            case 3:{
                int ma;
                string ten;
                string tenTacGia;
                int namXB;
                cout << "Nhap ma: "; cin >> ma; cin.ignore();
                cout << "Nhap ten: "; getline(cin, ten);
                cout << "Tac gia: "; getline(cin, tenTacGia);
                cout << "Nam XB: "; cin >> namXB;
                    tv.themSach(sach(ma, ten, tenTacGia, namXB));
                break;
            }
            case 4:{
                string tenSach;
                    cout << "nhap ten sach muon muon: ";
                    getline(cin, tenSach);
                    tv.choMuon(dg, tenSach);
                break;
            }
            case 5:{
                int maSach;
                cout << "Nhap ma sach muon tra: ";
                cin >> maSach;
                dg.traSach(maSach);
                break;
            }
            case 6:{
                string timSach;
                cout << "Nhap sach muon tim: ";
                getline(cin, timSach);
                int index = tv.timSach(timSach);
                if(index == -1){
                    cout << "Khong tim thay sach!\n";
                }else {
                    cout << "Tim thay sach\n";
                }
                break;
            }
            case 7:{
                string tacGia;
                string tenSach;
                cout << "Nhap ten sach: ";
                getline(cin, tenSach);
                cout << "Nhap ten tac gia: ";
                getline(cin, tacGia);
                
                int index = tv.timSach(tenSach);
                if(index == -1){
                    cout << "Khong tim thay sach\n";
                }else {
                    cout << "tim thay sach\n";
                }
                break;
            }
            case 8:{
                tv.hienThiSach();
                break;
            }
            case 0:{
                cout << "Tam biet!" << endl;
                break;
            }
            default:{
                cout << "Nhap khong hop le! (Nhap lai)";
            }
        }
    }while(luaChon != 0);

    return 0;
}