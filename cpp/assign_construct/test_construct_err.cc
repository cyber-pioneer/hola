#include <iostream>

class Base {
  int *data;

public:
  Base(int x) { std::cout << "init Base obj" << std::endl; }
  Base(const Base &) { std::cout << " copy constructor called" << std::endl; }
  Base(const Base &&) { std::cout << " move constructor called" << std::endl; }

  Base &operator=(Base &other) {
    if (this == &other) //防止自拷贝
      return *this;
    std::cout << " copy assign called" << std::endl;
    this->data = other.data;
    return *this;
  }
  Base &operator=(Base &&other) {
    if (this == &other)
      return *this;
    this->data = other.data;
    other.data = nullptr;
    std::cout << " move assign called" << std::endl;
    return *this;
  }
};

int main() {
  // Base b1; // no matching function for call to ‘Base::Base()’
  // 即这样无入参的的对象初始化，会默认调用不带入参的 构造函数
  // Base::Base()，一旦构造函数需要入参，就会报错
  Base b1(1); // init Base obj
  // Base b1 = Base(1); //与Base b1(1)
  // 原理不一致，但是因为编译器的优化，实际运行是一致的，详情见readme.md

  // Base b2(b1);
  // Base b3 = std::move(b1);
  // b3 = b1;
  return 0;
}
