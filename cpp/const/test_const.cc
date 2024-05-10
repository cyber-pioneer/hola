// https://blog.csdn.net/weixin_43886592/article/details/106477848

// error: passing ‘const MyClass’ as ‘this’ argument discards qualifiers
// [-fpermissive]

// 这个编译错误表明你正在尝试在一个非常量对象上调用一个只能在常量对象上被调用的成员函数。C++中，常量成员函数保证在执行过程中不会修改对象的状态，即不会改变任何成员变量。如果你尝试在一个非常量对象上调用这样的成员函数，编译器会报错，因为这可能违反了该函数的契约。

// 解决方法：

// 确保你不在常量对象上调用非常量成员函数。如果你需要修改对象的状态，你应该使用非常量成员函数。如果你不需要修改状态，那么你应该将成员函数声明为常量，并确保不会修改任何成员变量。

#include <iostream>

class MyClass {
public:
  void nonConstFunction() {
    std::cout << "call nonConstFunction " << std::endl;
    // 修改成员变量的操作
  }
  void constFunction() const {
    std::cout << "call ConstFunction " << std::endl;
    // 只读操作，不会修改成员变量
  }
};

int main() {
  const MyClass myConstObject;
  myConstObject.constFunction(); // 正确
  // myConstObject.nonConstFunction(); // 错误，会导致编译错误

  MyClass myObject;
  myObject.nonConstFunction(); // 正确
  return 0;
}
