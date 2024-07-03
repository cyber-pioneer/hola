#include <iostream>
#include <memory>
// https://blog.csdn.net/m0_75215937/article/details/135591922
// case 有问题，待修复

// std::weak_ptr 是一个不控制对象生命周期的智能指针，它指向一个由
// std::shared_ptr 管理的对象。由于 weak_ptr
// 不持有对对象的强引用（即不会增加引用计数）， 因此它不会阻止 shared_ptr
// 所指向的对象被销毁。当你想避免循环引用但又需要访问 shared_ptr
// 所管理的对象时，weak_ptr 是非常有用的。

// 然而，你不能直接通过 weak_ptr 来访问它所指向的对象，因为 weak_ptr 可能在
// shared_ptr 对象已经被销毁后仍然保持有效，即它可能是一个“悬空”的指针。
// 为了安全地访问 weak_ptr 所指向的对象，你需要首先将其转换为
// std::shared_ptr，这可以通过调用 weak_ptr 的 lock() 成员函数来实现。

struct Foo;
struct Bar;

struct Bar {
  std::shared_ptr<Foo> foo;
  void someMethodOfBar() {
    std::cout << "call someMethodOfBar in Bar" << std::endl;
    // ... Bar的方法实现 ...
  }
  // ... 其他成员和方法 ...
};

struct Foo {
  std::weak_ptr<Bar> bar;
  void doSomethingWithBar() {
    // 尝试获取对Bar的shared_ptr引用
    std::shared_ptr<Bar> barPtr = bar.lock();
    if (barPtr) {
      // 如果成功获取到shared_ptr，则可以使用它
      barPtr->someMethodOfBar();
    } else {
      // 否则，Bar可能已经被销毁了
      std::cout << "Bar has been destroyed." << std::endl;
    }
  }
  // ... 其他成员和方法 ...
};

int main() {
  std::shared_ptr<Foo> foo = std::make_shared<Foo>();
  std::shared_ptr<Bar> bar = std::make_shared<Bar>();

  foo->bar = bar;
  bar->foo = foo;

  // ... 在这里进行一些操作 ...

  foo->doSomethingWithBar(); // 假设Bar此时还存在，则调用其someMethodOfBar方法

  // 当foo和bar的最后一个shared_ptr被销毁时，它们所指向的对象也会被销毁
  // 由于foo和bar是通过make_shared创建的，所以它们的内存是连续分配的，销毁效率更高

  return 0;
}
