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

// g++ 这里输出 Dynamic type of b: 7Derived ，类型前添加数字7，编译器的行为
// type_info::name()
// 的输出是为了调试和诊断目的而设计的，并不保证在不同的编译器或编译设置之间保持一致。
// 如果需要在运行时以可靠的方式处理类型信息，可能需要寻找其他解决方案
