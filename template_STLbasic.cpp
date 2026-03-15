#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stack {
    private:
        vector<T> data; //use vector to save
    public:
        void push(T value){
            data.push_back(value);
        }
        T pop(){
            if(data.empty()){
                cout << "stack empty" << endl;
                return T{};
            }
            T top = data.back();
            data.pop_back();
            return top;
        }
        bool isEmpty(){
            return data.empty();
        }
};

int main(){
    Stack<int> intStack;
    Stack<string> stringStack;

    intStack.push(10);
    intStack.push(20);
    
    cout << intStack.pop() << endl;
    cout << intStack.pop() << endl;

    stringStack.push("Hello");
    stringStack.push("World");

    cout << stringStack.pop() << endl;
    cout << stringStack.pop() << endl;

    return 0;
}