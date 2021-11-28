#include<iostream>
template <typename T>
void func(T t){
    std::cout<<t<<std::endl;
}


template <typename T>
void func(T t){
    std::cout<<t<<std::endl;
}

template <typename T>
void func(T* t){
    std::cout<<*t<<std::endl;
}

int main(){
    int x=0;
    int *p=&x;
    func(x);
    func(p);
    return 0;
}