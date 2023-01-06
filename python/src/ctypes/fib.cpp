#include <iostream>

extern "C" {
    int Fibonacci(int number);
}

int Fibonacci(int number){
    if(number < 2){
        return number;
    } else {
        return Fibonacci(number - 1) + Fibonacci(number - 2);
    }
}

int main(){
    return 0;
}
