#include<iostream>

int func(int i);

int main(){
    int n = 2;
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        sum += func(i);
    }
    std::cout << "result: " << sum << std::endl;
}

int func(int i){
    int value = 1;
    while(i % 2 == 0){
        i = i / 2;
        value = 2 * value;
    }
    return i / value;
}