#include <iostream>

class MyClass {
private:
  int secretValue;

public:
  MyClass() : secretValue(42) {} // 构造函数，初始化secretValue为42

  // 声明一个友元函数
  // friend void revealSecret(MyClass& obj);
};

// 实现友元函数，注意它不是MyClass的成员函数
friend void revealSecret(MyClass &obj) {
  // 友元函数可以访问MyClass的私有成员
  std::cout << "The secret value is: " << obj.secretValue << std::endl;
}

int main() {
  MyClass myObj;       // 创建一个MyClass对象
  revealSecret(myObj); // 调用友元函数来揭示私有成员的值
  return 0;
}
