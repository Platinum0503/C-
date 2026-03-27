#include <iostream>
#include <vector>
using namespace std;

class sach{
    private:
        int ma;
        string ten, tacGia;
        int namXuatBan;
    public: 
        sach(int ma, string ten, string tacGia, int namXB){
            this->ma = ma;
            this->ten = ten;
            this->tacGia = tacGia;
            this->namXuatBan = namXB;
        }
        string getTen() { return ten; }
        string getTenTacGia() { return tacGia; }
        int getMa() { return ma; }

        void inThongTin(){
            cout << ma << " | " << ten << " | " << tacGia
                << " | " << namXuatBan << endl;
        }
};
class DocGia {
    private:  
        int ma;
        string ten;
        vector<sach> sachDangMuon; //danh sách sách đang mượn
    public:
        DocGia(int ma, string ten){
            this->ma = ma;
            this->ten = ten;
        } 
        string getTen() { return ten; }
        int getMa() { return ma; }

        void muonSach(sach s){
            sachDangMuon.push_back(s); //thêm sách vào danh sách mượn
        }
        void traSach(int maSach){
            for(int i = 0;i < sachDangMuon.size();i++){
                if(sachDangMuon[i].getMa() == maSach){
                    sachDangMuon.erase(sachDangMuon.begin() + i); //xoá khỏi danh sách
                    cout << "Tra sach thanh cong!\n";
                    return; // ???
                }
            }
            cout << "khong tim thay sach!\n"; 
        }
        void inSachDangMuon(){
            if(sachDangMuon.empty()){
                cout << "khong co sach dang muon!\n";
                return;
            }
            for(int i = 0;i < sachDangMuon.size();i++){
                sachDangMuon[i].inThongTin();
            }
        }
};
class thuVien {
    private:
        vector<sach> danhSachSach;
        vector<DocGia> danhSachDocGia;
    public:
        void themSach(sach s){
            danhSachSach.push_back(s);
            cout << "Them sach thanh cong!" << endl;
        }
        void hienThiSach(){
            for(int i = 0; i < danhSachSach.size();i++){
                danhSachSach[i].inThongTin();
            }
        }
        int timSach(string ten){
            for(int i = 0; i < danhSachSach.size();i++){
                if(danhSachSach[i].getTen() == ten){
                    return i;
                }
            }
            return -1;
        }
        void choMuon(DocGia& dg, string tenSach){ //why use &
            int index = timSach(tenSach);
            if(index == -1){
                cout << "khong co sach nay!\n";
                return;
            }
            dg.muonSach(danhSachSach[index]);
            danhSachSach.erase(danhSachSach.begin() + index); //xoá khỏi thư viện
            cout << "cho muon thanh cong!\n";
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
    DocGia dg(1, "Nguyen Van A");
    int luaChon;

    do{
        menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore(); //delete '\n' trong buffer
        switch(luaChon){
            case 1:{
                tv.hienThiSach();
                break;
            }
            case 2:{
                dg.getTen();
                break;
            }
            case 3: {
                int ma, namXB;
                string ten, tacGia;
                cout << "Ma sach: "; cin >> ma; cin.ignore();
                cout << "Ten sach: "; getline(cin, ten);
                cout << "Tac gia: "; getline(cin, tacGia);
                cout << "nam XB: "; cin >> namXB;
                tv.themSach(sach(ma, ten, tacGia, namXB)); 
                break;
            }
            case 4: {
                string tenSach;
                cout << "ten sach muon muon: ";
                getline(cin, tenSach);
                tv.choMuon(dg, tenSach);
                break;
            }
            case 5: {
                int maSach;
                cout << "sach muon tra: ";
                cin >> maSach;
                dg.traSach(maSach);
                break;
            }
            case 6: {
                string tenSach;
                cout << "ten sach can tim: ";
                getline(cin, tenSach);
                int index = tv.timSach(tenSach);
                if(index == -1){
                    cout << "Khong tim thay sach!\n";
                }else {
                    cout << "Tim thay sach!\n";
                }
                break; 
            }
            case 7: {
                string tenSach, tacGia;
                cout << "ten sach can tim: ";
                getline(cin, tenSach);
                cout << "ten tac gia can tim: ";
                getline(cin, tacGia);
                int index = tv.timSach(tenSach);
                if(index == -1){
                    cout << "Khong tim thay sach!\n";
                }else {
                    cout << "Tim thay sach!\n";
                }
                break;
            }
            case 8: {
                tv.hienThiSach();
                break;
            }
            case 0: {
                cout << "Tam biet!"; break;
            }
            default: cout << "Nhap ko hop le! Nhap lai: ";
                break;
        }
    }while(luaChon != 0);
    
    return 0;
}