#include <iostream>
#include <vector>
using namespace std;

class chiTieu{
    private:    
        int ngay;
        float chi;
        string loai;
    public: 
        chiTieu(int day, float money, string loai){
            this->ngay = day;
            this->chi = money;
            this->loai = loai;
        }
    void inThongTin(){
        cout << "Ngay " << ngay << " | " << 
             "chi: " << chi << endl;
    }
    float getChi() { return chi; }
    string getLoai() { return loai; }
};
class caNhan{
    private:    
        vector<chiTieu> danhSachChi;
        float tien;
    public:
        caNhan(float money){
            this->tien = money;
        }
    void thu(chiTieu money){
            danhSachChi.push_back(money);
            cout << "Them thu thanh cong!\n";
    }
    void chi(chiTieu money){
        danhSachChi.push_back(money);
        cout << "Them chi thanh cong!\n";
    }
    void tinhTong(){
        float tongThu = tien;
        float tongChi = 0;
        for(int i = 0; i < danhSachChi.size();i++){
            if(danhSachChi[i].getLoai() == "Thu"){
                tongThu += danhSachChi[i].getChi();
            }else {
                tongChi += danhSachChi[i].getChi();
            }
            cout << "Tong thu: " << tongThu << " VND\n";
            cout << "Tong chi: " << tongChi << " VND\n";
        }
    }
    void lichSu(){
        if(danhSachChi.empty()){
            cout << "Chua co giao dich nao!\n";
        }
        for(int i = 0; i < danhSachChi.size();i++){
            danhSachChi[i].inThongTin();
        }
    }
};
void menu(){
    cout << "\n=== MENU ===\n";
    cout << "1.Them thu\n";
    cout << "2.Them chi\n";
    cout << "3.Tinh tong\n";
    cout << "4.Xem lich su\n";
    cout << "0.Thoat\n";
}
int main(){
    caNhan nguoi(1000000);
    int luaChon;

    do{
        menu();
        cin >> luaChon;
        switch(luaChon){
            case 1:{
                    int day;
                    float money;
                    cout << "Ngay: ";
                    cin >> day;
                    cout << "Thu: ";
                    cin >> money;
                    nguoi.thu(chiTieu(day, money, "Thu"));                                   
                break;
            }
            case 2:{
                    float CHI;
                    int ngay;
                    cout << "Ngay: ";
                    cin >> ngay;
                    cout << "Thu: ";
                    cin >> CHI;
                    nguoi.chi(chiTieu(ngay, CHI, "Chi"));
                break;
            }
            case 3:{    
                    nguoi.tinhTong();
                break;
            }
            case 4:{
                nguoi.lichSu();
                break;
            }
            case 0:{
                cout << "Tam biet!";
                break;
            }
            default:{
                cout << "Nhap khong hop le! Nhap lai: ";
            }
        }
    }while(luaChon != 0);
    return 0;
}