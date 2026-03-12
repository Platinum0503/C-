#include <iostream>
using namespace std;

class Car{
    public:
        string make;
        string mode1;
        int year;
        string color;

        void accelerate(){
            cout << "you step on the gas!\n";
        }
        void brake(){
            cout << "you step on the brakes!\n";
        }
};

int main(){
    Car car1;

    car1.make = "Ford";
    car1.mode1 = "Mustang";
    car1.year = 2023;
    car1.color = "silver";
    
    cout << car1.make << '\n';
    cout << car1.mode1 << '\n';
    cout << car1.year << '\n';
    cout << car1.color << '\n';

    car1.accelerate();
    car1.brake();
    return 0;
}