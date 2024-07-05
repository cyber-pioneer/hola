#include<iostream>



void fn(int &a, int *b) {
    a = 0;
    b = 0;
}

int main() {
    int a = 1;
    int b = 1;
    int *c = &b;
    std::cout<<a<<"  "<<b<<"  "<<c<<" "<<*c<<std::endl;
    fn(a, c);
    std::cout<<a<<"  "<<b<<"  "<<c<<" "<<*c<<std::endl;
}

// 1  1  0x16d78f518 1
// 0  1  0x16d78f518 1
// 作为入参，引用变量无法重新指向其他变量，但是指针会