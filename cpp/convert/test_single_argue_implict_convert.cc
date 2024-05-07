#include <iostream>

class MyClass {
public:
    // 单参数构造函数
    MyClass(int value) : m_value(value) {
        std::cout << "MyClass constructor called with value: " << m_value << std::endl;
    }

    // 成员函数，用于打印成员变量的值
    void printValue() {
        std::cout << "Value in MyClass object: " << m_value << std::endl;
    }

private:
    int m_value;
};

void printMyClassValue(MyClass& obj) {
    obj.printValue();
}

int main() {
    MyClass obj(42);
    // 直接使用int类型的值来调用需要MyClass类型参数的函数
    // 这里会发生隐式转换，即自动调用MyClass的单参数构造函数来创建一个临时的MyClass对象
    printMyClassValue(obj);  // 输出: MyClass constructor called with value: 42
                            //      Value in MyClass object: 42

    return 0;
}