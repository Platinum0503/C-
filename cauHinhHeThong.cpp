#include <iostream>
using namespace std;

class cauHinhHeThong{
    private:
        static cauHinhHeThong* instance;
        cauHinhHeThong() {}

        string tenApp = "MyApp";
        string phienBan = "1.0.0";
        string ngonNgu = "Vietnamese";

    public:
        static cauHinhHeThong* getInstance(){
            if(instance == nullptr){
                instance = new cauHinhHeThong();
            }
                return instance;
        }
        void hienThiCauHinh(){
            cout << "Ten app: " << tenApp << '\n';
            cout << "Phien ban: " << phienBan << '\n';
            cout << "Ngon ngu: " << ngonNgu << '\n';
        }
        void setNgonNgu(string ng){
            ngonNgu = ng;
        }
};
cauHinhHeThong* cauHinhHeThong::instance = nullptr;
int main(){

    cauHinhHeThong* c1 = cauHinhHeThong::getInstance();
    cauHinhHeThong* c2 = cauHinhHeThong::getInstance();

    c1->setNgonNgu("English");

    c2->hienThiCauHinh();

    cout << (c1 == c2); // 1 -> true
    return 0;
}