#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class vector2D{
    private:
        int x;
        int y;
    public: 
        vector2D(int a, int b){
            x = a;
            y = b;
        }
    vector2D operator+(vector2D other){
        int xMoi = x + other.x;
        int yMoi = y + other.y;
            return vector2D(xMoi, yMoi);
    }vector2D operator-(vector2D other){
        int xMoi = x - other.x;
        int yMoi = y - other.y;
            return vector2D(xMoi, yMoi);
    }
    vector2D operator*(float soThuc){ //caution
        return vector2D(x * soThuc, y * soThuc);
    }
    float doDai(){
        return sqrt(x*x + y*y);
    }
    bool operator==(vector2D other){
        return x == other.x && y == other.y;
    }
    friend ostream& operator<<(ostream& os, vector2D v){
        os << v.x << " " << v.y;
        return os;
    }
};

int main(){
    vector2D a(1, 2);
    vector2D b(3, 4);
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * 2.0f << endl; //caution 2.0f nghĩa là float
                                    //2 --> int
                                    // 2.0 --> double
    
    return 0;
}