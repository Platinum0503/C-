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
    virtual void keuAm(){
        cout << "..." << endl;
    }
    string getName() { return name; }
};
class Dog : public dongVat{
    public:
        Dog(string ten, int tuoi) : dongVat(ten, tuoi) {}
        void keuAm() override {
            cout << "Gau Gau" << endl;
        }
};
class Cat : public dongVat{
    public:
        Cat(string ten, int tuoi) : dongVat(ten, tuoi) {}
        void keuAm() override {
            cout << "Meo Meo" << endl;
        }
};
void menu(){
    cout << "=== MENU ===" << endl;
    cout << "1.Dog" << endl;
    cout << "2.Cat" << endl;
    cout << "0.Thoat" << endl;
}
int main(){
    dongVat* cho = new Dog("chill", 1);
    cout << cho->getName() << endl;
    cho->keuAm();

    dongVat* meo = new Cat("miu", 2);
    cout << meo->getName() << endl;
    meo->keuAm();
    return 0;
}