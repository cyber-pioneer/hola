#include <memory>

struct Foo;
struct Bar;

struct Foo {
  std::shared_ptr<Bar> bar;
  // ... 其他成员 ...
};

struct Bar {
  std::shared_ptr<Foo> foo;
  // ... 其他成员 ...
};

int main() {
  std::shared_ptr<Foo> foo = std::make_shared<Foo>();
  std::shared_ptr<Bar> bar = std::make_shared<Bar>();

  foo->bar = bar;
  bar->foo = foo;

  // foo 和 bar 相互持有对方的 shared_ptr
  // 当 foo 和 bar 离开作用域时，它们的引用计数仍然为 1
  // 因此，它们所指向的内存不会被释放

  return 0;
}
