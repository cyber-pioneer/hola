#include <iostream>

class ClassB; // 前置声明，因为ClassA中需要用到ClassB的指针或引用

class ClassA {
private:
  int secretDataA = 100;

public:
  // 声明ClassB的成员函数为友元，使其能够访问ClassA的私有成员
  friend void accessDataA(ClassB);
};

class ClassB {
private:
  int secretDataB = 200;

public:
  // 用于访问ClassA的私有数据的函数
  friend void ClassA::accessDataA(ClassA &a);

  // 提供一个公开接口，允许ClassA访问ClassB的私有数据
  int getSecretDataB() { return secretDataB; }
};

void ClassA::accessDataA(ClassA &a) {
  std::cout << "ClassB can access ClassA's secret data: " << a.secretDataA
            << std::endl;
}

int main() {
  ClassA a;
  ClassB b;

  // ClassB通过其成员函数访问ClassA的私有数据
  b.accessDataA(a);

  // 假设ClassA也需要访问ClassB的私有数据，可以通过ClassB的公开接口来实现
  // std::cout << "ClassA can access ClassB's secret data: " <<
  // b.getSecretDataB() << std::endl;

  return 0;
}
