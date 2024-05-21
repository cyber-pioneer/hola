#include <cassert>
#include <iostream>

template <typename T> class SimpleUniquePtr {
private:
  T *ptr;

  // 禁止拷贝构造和拷贝赋值
  SimpleUniquePtr(const SimpleUniquePtr &) = delete;
  SimpleUniquePtr &operator=(const SimpleUniquePtr &) = delete;

public:
  // 默认构造函数，初始化为空指针
  SimpleUniquePtr() : ptr(nullptr) {}

  // 构造函数，接受一个指针
  explicit SimpleUniquePtr(T *p) : ptr(p) {}

  // 移动构造函数
  SimpleUniquePtr(SimpleUniquePtr &&other) noexcept : ptr(other.ptr) {
    other.ptr = nullptr;
  }

  // 移动赋值运算符
  SimpleUniquePtr &operator=(SimpleUniquePtr &&other) noexcept {
    if (this != &other) {
      delete ptr;
      ptr = other.ptr;
      other.ptr = nullptr;
    }
    return *this;
  }

  // 析构函数，删除所指向的对象
  ~SimpleUniquePtr() { delete ptr; }

  // 解引用操作符
  T &operator*() const {
    assert(ptr != nullptr);
    return *ptr;
  }

  // 箭头操作符
  T *operator->() const {
    assert(ptr != nullptr);
    return ptr;
  }

  // 获取原始指针（不推荐使用，除非必要）
  T *get() const { return ptr; }

  // 检查是否为空指针
  bool operator==(std::nullptr_t) const { return ptr == nullptr; }

  // 检查是否非空指针
  bool operator!=(std::nullptr_t) const { return ptr != nullptr; }

  // 重置指针，删除当前对象并指向新对象（可为nullptr）
  void reset(T *newPtr = nullptr) {
    delete ptr;
    ptr = newPtr;
  }
};

int main() {
  // 使用SimpleUniquePtr管理动态分配的内存
  SimpleUniquePtr<int> p(new int(42));
  std::cout << *p << std::endl; // 输出 42
  p.reset();                    // 删除int对象，p变为空指针
}

// 在C++中，智能指针是一种用于管理动态分配内存的对象，它们可以在适当的时候自动删除所指向的对象，从而防止内存泄漏。
// C++11标准库中提供了几种智能指针：std::unique_ptr、std::shared_ptr和std::weak_ptr。
// 这些智能指针已经足够强大且高效，因此在大多数情况下，我们不需要自己从头开始实现智能指针。

// 这个SimpleUniquePtr类实现了unique_ptr的一些基本功能：它拥有一个指向动态分配对象的指针，并在析构时自动删除该对象。
// 它还提供了移动构造函数和移动赋值运算符，以便在移动语义上下文中高效地使用。此外，它还提供了解引用操作符、箭头操作符以及一些其他实用方法。
