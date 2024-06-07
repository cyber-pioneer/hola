#include <iostream>

class B; // 前置声明

class A {
private:
  int a_ = 100;

public:
  // 提供一个公开接口，允许B访问A的私有数据
  int geta_() { return a_; }
};

class B {
private:
  int b_ = 200;

public:
  // 提供一个成员函数用于显示A的私有数据
  void DisplayA(A &obj) {
    std::cout << "call A.a " << obj.geta_() << std::endl;
  }

  // 提供一个公开接口，允许A访问B的私有数据
  int getb_() { return b_; }
};

int main() {
  A a;
  B b;

  // B通过A的公开接口访问A的私有数据
  b.DisplayA(a);

  // 假设A也需要访问B的私有数据，可以通过B的公开接口来实现
  // 但是在这个例子中，我们并没有在A中直接访问B的数据，而是在main函数中演示了这一点
  std::cout << "A can access B's secret data: " << b.getb_() << std::endl;

  return 0;
}
