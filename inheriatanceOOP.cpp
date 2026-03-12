#include <iostream>
using namespace std;

class dongVat{
    private:
        string name;
        int age;
    public:
        dongVat(string ten, int tuoi){
            name = ten;
            age = tuoi;
        }
    virtual void keuAm(){ //virtual cho phép con override hàm
        cout << "..." << endl;
    }
    string getName() {  return name; }
};
class Dog : public dongVat {
    public:
        Dog(string ten, int tuoi) : dongVat(ten, tuoi) {} //call constructor cha
        void keuAm(){
            cout << "Gau Gau" << endl;
        }
};
class Cat : public dongVat {
    public:
        Cat(string ten, int tuoi) : dongVat(ten, tuoi) {}
        void keuAm(){
            cout << "Meo Meo" << endl;
        }
};
class Duck : public dongVat {
    public:
        Duck(string ten, int tuoi) : dongVat(ten, tuoi) {}
        void keuAm(){
            cout << "Quak Quak" << endl;
        }
};
void menu(){
    cout << "danh sach cac loai dong vat\n";
    cout << "1.Dog\n";
    cout << "2.Cat\n";
    cout << "3.Duck\n";
    cout << "0.Thoat\n";
}
int main(){
    Dog dog("Buddy", 3);
    Cat cat("Kitty", 2);
    Duck duck("Donald", 1);
    
    int luaChon;
    do{
        menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        switch(luaChon){
            case 1: cout << dog.getName() << "Keu: ";
                    dog.keuAm();
                    break;
            case 2: cout << cat.getName() << "Keu: ";
                    cat.keuAm();
                    break;
            case 3: cout << duck.getName() << "Keu: ";
                    duck.keuAm();
                    break;
            case 0: cout << "Tam biet!" << endl;
                break;
            default: cout << "Khong hop le! nhap lai";
                break;
        }

    }while(luaChon != 0);

    return 0;
}