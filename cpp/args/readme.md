1. 函数形参名称是可选的，即某些场景下，形参名称是不用定义的：


声明不用，定义时使用
'''
#include<iostream>

int fn(int);

int fn(int x) {
    return x * 2;
}

int main(){
    std::cout<<fn(2)<<std::endl;
}
'''

实际没有使用到
'''
#include<iostream>


int fn(int) {
    return 2;
}

int main(){
    std::cout<<fn(2)<<std::endl;
}
'''

构造函数声明时
'''
ClassName(const ClassName&){}
'''
