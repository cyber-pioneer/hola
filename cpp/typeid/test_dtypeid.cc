#include <iostream>
#include <typeinfo>

class Base {
public:
  virtual ~Base() {} // 虚析构函数使得类成为多态基类
};

class Derived : public Base {};

int main() {
  int x = 5;
  float y = 3.14f;
  Base *b = new Derived();

  std::cout << "Type of x: " << typeid(x).name() << std::endl;
  std::cout << "Type of y: " << typeid(y).name() << std::endl;
  std::cout << "Dynamic type of b: " << typeid(*b).name() << std::endl;

  delete b; // 不要忘记释放动态分配的内存
  return 0;
}
