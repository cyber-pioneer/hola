#include <iostream>
#include <typeinfo>

class Base {
public:
  virtual ~Base() {} // 虚析构函数，使类成为多态基类
};

class Derived : public Base {};

int main() {
  Base *b = new Base();
  Derived *d = new Derived();

  const std::type_info &b_type = typeid(*b);
  const std::type_info &d_type = typeid(*d);

  std::cout << "b is of type: " << b_type.name() << std::endl;
  std::cout << "d is of type: " << d_type.name() << std::endl;

  // 尝试动态转换
  Base *ptr = dynamic_cast<Base *>(d); // 向上转型，总是安全的
  if (ptr != nullptr) {
    std::cout << "Dynamic cast to Base* succeeded." << std::endl;
  }

  Derived *derivedPtr = dynamic_cast<Derived *>(b); // 尝试向下转型
  if (derivedPtr == nullptr) {
    std::cout << "Dynamic cast to Derived* failed." << std::endl;
  } else {
    std::cout << "Dynamic cast to Derived* succeeded." << std::endl;
  }

  delete b;
  delete d;
  return 0;
}

// output:
// b is of type: 4Base
// d is of type: 7Derived
// Dynamic cast to Base* succeeded.
// Dynamic cast to Derived* failed.
