#include <iostream>

int &getLocalVariableReference() {
  int localVariable = 42; // 这是一个局部变量
  return localVariable;   // 错误：返回局部变量的引用
}

int main() {
  int &ref = getLocalVariableReference(); // ref 成为悬挂引用
  std::cout << ref << std::endl; // 未定义行为，因为 ref 指向的对象已经不存在了
  return 0;
}
