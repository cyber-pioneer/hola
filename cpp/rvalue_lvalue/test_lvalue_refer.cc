#include <iostream>

int getLocalVariableReference(int &x) {
  int localVariable = 42 + x;
  return localVariable;
}

int main() {
  int x = 5;

  // cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type
  // ‘int’ 这里 rvalue of type ‘int’ 是5，
  // 是int类型临时变量，不能用临时变量去初始化一个非const类型的引用，因为地址指向的内容可能会改变，那么临时变量就失效了，没有意义
  // int ref = getLocalVariableReference(5);
  int ref = getLocalVariableReference(x); // 此时x非临时变量，是有实际地址的
  std::cout << ref << std::endl;
  return 0;
}
