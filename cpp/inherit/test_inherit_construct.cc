#include <iostream>
class Base {
public:
  Base(int x) {
    std::cout << " call Base constructor " << std::endl;
    // 基类构造函数，接受一个整数参数
    // 在这里进行基类的初始化
  }
};

class Derived : public Base {
public:
  Derived(int x, double y)
      : Base(
            x) { // 对于需要入参的基类构造函数，必须使用初始化列表显示调用基类构造函数；否则可以不用显示调用
    // Derived(int x, double y) { // error: no matching function for call to
    // ‘Base::Base()’
    std::cout << " call Derived constructor " << std::endl;
    // 派生类构造函数，接受一个整数和一个双精度浮点数参数
    // 通过初始化列表，将整数参数 x 传递给基类构造函数
    // 在这里进行派生类特有的初始化，可以使用参数 y
  }
};

int main() {
  Derived d(10, 20.5); // 创建派生类对象，同时将 10 传递给基类构造函数，20.5
                       // 用于派生类的初始化
  return 0;
}

// call Base constructor
// call Derived constructor
