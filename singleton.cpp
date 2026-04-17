#include <iostream>
using namespace std;

class Singleton{
    private:
        static Singleton* instance; //save object duy nhat
        Singleton() {}              //constructor private
                                    //ko ai được tạo từ ngoài
    public:
        static Singleton* getInstance(){
            if(instance == nullptr){
                instance = new Singleton(); //tạo lần đầu
            }
            return instance; // lần sau trả về cái cũ
        }                                    
};
// khởi tạo static
Singleton* Singleton::instance = nullptr;
int main(){
    
    return 0;
}