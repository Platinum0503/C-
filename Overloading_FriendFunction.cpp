#include <iostream>
using namespace std;

int ucln(int a, int b){
    while(b != 0){
        int temp;
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class phanSo {
    private:
        int tuSo;
        int mauSo;
    public:
        phanSo(int a, int b){
            int g = ucln(a , b);
            tuSo = a / g;
            mauSo = b / g;
        }
        phanSo operator+(phanSo other){
            int tuSoMoi = tuSo * other.mauSo + other.tuSo *mauSo;
            int mauSoMoi = mauSo * other.mauSo;
            return phanSo(tuSoMoi, mauSoMoi);
        }
        phanSo operator*(phanSo other){
            return phanSo(tuSo * other.tuSo, mauSo * other.mauSo);
        }
        bool operator==(phanSo other){
            return tuSo == other.tuSo && mauSo == other.mauSo;
        }
        // Khai báo friend → operator<< được phép nhìn vào private
        friend ostream& operator<<(ostream& os, phanSo p){
            // Hàm này đứng ngoài class nhưng thấy được tuSo, mauSo
            os << p.tuSo << "/" << p.mauSo;
            return os;
        }
};
//  ostream& os → chính là cout
//  phanSo p → chính là object bạn muốn in
//  Trả về ostream& → để dùng được nối tiếp như cout << a << b

int main(){
    phanSo a(1, 2);
    phanSo b(1, 3);

    cout << a + b << endl; // 5/6
    cout << a * b << endl; // 1/6
    cout << (a == b) << endl; // 0 (false)

    return 0;
}