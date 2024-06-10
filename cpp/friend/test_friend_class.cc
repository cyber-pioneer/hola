#include <iostream>

class A {
private:
  int a_ = 100;

public:
  // 声明B为友元类
  friend class B;

  // 其他成员函数...
};

class B {
public:
  // B类的成员函数可以访问A类的私有成员a_
  void DisplayA(const A &obj) {
    std::cout << "call A.a " << obj.a_ << std::endl;
  }

  // 其他成员函数...
};

int main() {
  A a;
  B b;

  // B类的成员函数可以访问A类的私有成员
  b.DisplayA(a);

  return 0;
}
