#include <iostream>

class Singleton {
private:
  static Singleton *instance;
  int param; // 假设我们有一个需要传入的参数

  // 私有构造函数，允许传入参数
  Singleton(int param) : param(param) {}

  // 禁止拷贝和赋值
  Singleton(const Singleton &) = delete;
  Singleton(Singleton &&) = delete;
  Singleton &operator=(const Singleton &) = delete;
  Singleton &operator=(Singleton &&) = delete;

public:
  // 静态方法，用于获取单例实例
  static Singleton *getInstance(int param) {
    if (instance == nullptr) {
      instance = new Singleton(param); // 第一次调用时创建实例
      std::cout << "******* get obj new ******* " << &instance << std::endl;
    }
    // 注意：这里我们假设后续调用getInstance时不再需要新的参数
    // 如果需要处理这种情况，可以考虑其他设计模式或重新设计单例
    std::cout << "******* get obj existed ******* " << &instance << std::endl;

    return instance;
  }

  // 其他成员函数...
};

// 静态成员初始化
Singleton *Singleton::instance = nullptr;
// 注意，这里是初始化，不是赋值，因此不同使用 Singleton::instance = nullptr
// 如果要在类定义内部初始化静态成员变量，那么该变量必须是常量表达式（constexpr），并且其类型必须是字面类型（literal
// type,编译期能确定值），通常是内置类型、enum、有常量表达式初始化器的类类型等。

// 对于单例模式，静态成员变量 instance
// 通常是一个指针，而指针类型不是字面类型，因此不能在类定义内部直接初始化。相反，您应该在类外部定义并初始化这个静态成员。

// 使用示例
int main() {
  Singleton *mySingleton = Singleton::getInstance(42);  // 传入参数42
  Singleton *mySingleton2 = Singleton::getInstance(41); // 传入参数41
  // ...
  return 0;
}
