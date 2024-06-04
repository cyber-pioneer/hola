#include <iostream>

class Base {
public:
  Base(const Base &) =
      delete; // 禁止拷贝构造
              // //这些构造函数放在public内就可以了，因为声明了删除，放哪都一样
  Base(Base &&) = delete;                 // 禁止移动构造
  Base &operator=(const Base &) = delete; // 禁止拷贝赋值
  Base &operator=(Base &&) = delete;      // 禁止移动赋值

  static Base *getInstance() { // 静态成员函数，可以直接调用，不依赖对象的建立
    static Base
        base; // 静态对象，声明周期与程序一致，只创建一次，无论getInstance多少次，都指向同一个对象
    std::cout << "******* get obj ******* " << &base << std::endl;
    return &base; // 返回引用，否则会拷贝，调用移动构造
  }

private:
  // 构造函数放在private内，防止外部创建对象
  Base() { std::cout << "create Base()" << std::endl; }
};

int main() {
  // Base aa; // error: ‘Base::Base()’ is private within this context
  Base *aa = Base::getInstance();
  Base *bb = Base::getInstance();
  return 0;
}

// output:
// create Base()
// ******* get obj ******* 0x4041b2
// ******* get obj ******* 0x4041b2
