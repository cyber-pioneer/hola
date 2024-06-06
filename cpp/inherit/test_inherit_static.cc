#include <iostream>

class Parent {
  int value = 0;

public:
  static void staticFunc() {
    std::cout << "Parent's static function " << value << std::endl;
  }
  // private:
  //     int value = 0;
};

class Child : public Parent {
  // Child does not declare or define its own staticFunc
};

int main() {
  // 调用父类的静态成员函数
  Parent::staticFunc(); // 输出 "Parent's static function"

  // 使用子类的作用域解析运算符来调用父类的静态成员函数也是合法的
  Child::staticFunc(); // 输出 "Parent's static function"

  // 尝试在子类中定义同名静态函数会导致编译错误，因为这不是继承
  // static void Child::staticFunc() { ... } //
  // 错误：不能在子类中定义同名静态函数

  return 0;
}
