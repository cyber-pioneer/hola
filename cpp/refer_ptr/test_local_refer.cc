#include <iostream>

// error reference to local variable ‘localVariable’ returned
// [-Wreturn-local-addr] int &getLocalVariableReference(int &a) {
//   int localVariable = a+1; // 这是一个局部变量，生命周期：跟随函数被销毁
//   return localVariable;   // 错误：返回局部变量的引用
// }

// output: 3
// int &getLocalVariableReference(int &a) {
//   a = a+1;
//   return a; // 输入的引用变量周期，生命周期与输入一致
// }

// x: 3, y: 3
// int &getLocalVariableReference(int& a) {
//   int& b = a;
//   b+=1; //
//   危险操作，b与a指向相同地址，b的修改也会改变原始输入a的值，因此输出一般加入const修饰用来限制a被篡改
//   return b; // 生命周期与输入一致
// }

// int &getLocalVariableReference(const int& a) {
//   int& b = a; // binding reference of type ‘int&’ to ‘const int’ discards
//   qualifiers b+=1; return b;
// }

// int &getLocalVariableReference(const int &a) {
//   int b = a;
//   b+=1;
//   return b; // reference to local variable ‘b’ returned [-Wreturn-local-addr]
// }

// x: 2, y: 3
// int getLocalVariableReference(const int &a) {
//   int b = a;
//   b+=1;
//   return b;
// }

// int* getLocalVariableReference(const int &a) {
//   int b = a;
//   b+=1;
//   return &b; // address of local variable ‘b’ returned [-Wreturn-local-addr]
// }

// // x: 2, y: 0x679e74
// int* getLocalVariableReference(const int &a) {
//   int* b = new int(2); //new
//   新建的指针对象地址会在堆上，若无手动delete，生命周期与程序一致 b+=1; return
//   b;
// }

// // x: 2, y: 0x40419c
// int* getLocalVariableReference(const int &a) {
//   static int b = a; //static 修饰的对象地址也会放在堆上
//   b+=1;
//   return &b; // address of local variable ‘b’ returned [-Wreturn-local-addr]
// }

int main() {
  int x = 2;
  auto y = getLocalVariableReference(x); // ref 成为悬挂引用
  std::cout << "x: " << x << ", y: " << y
            << std::endl; // 未定义行为，因为 ref 指向的对象已经不存在了
  return 0;
}
