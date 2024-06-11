#include <iostream>

class Base {
public:
  void show() { // 虚函数
    std::cout << "Base class" << std::endl;
  }
};

class Derived : public Base {
public:
  void show() override { // 重写基类中的虚函数
    std::cout << "Derived class" << std::endl;
  }
};

int main() {
  Base *basePtr;      // 基类指针
  Derived derived;    // 派生类对象
  basePtr = &derived; // 指针指向派生类对象
  derived.show();     // 动态绑定调用Derived类的show()
  return 0;
}
