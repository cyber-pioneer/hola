#include <iostream>

class MyClass {
public:
  // 单参数构造函数
  MyClass(int value) : m_value(value) {
    std::cout << "MyClass constructor called with value: " << m_value
              << std::endl;
  }

  // 成员函数，用于打印成员变量的值
  void printValue() {
    std::cout << "Value in MyClass object: " << m_value << std::endl;
  }

private:
  int m_value;
};

void printMyClassValue(MyClass &obj) { obj.printValue(); }

// int main() {
//   MyClass obj(42);
//   printMyClassValue(obj);

// // outputs:
// // MyClass constructor called with value: 42
// // Value in MyClass object: 42

//   return 0;
// }

int main() {
  MyClass obj(42);
  // 直接使用int类型的值来调用需要MyClass类型参数的函数
  // 这里会发生隐式转换，即自动调用MyClass的单参数构造函数来创建一个临时的MyClass对象
  // & 关键字阻止了隐式转换
  printMyClassValue(12);

  // outputs:
  // test_single_argue_implict_convert_err2.cc: In function ‘int main()’:
  // test_single_argue_implict_convert_err2.cc:38:21: error: cannot bind
  // non-const lvalue reference of type ‘MyClass&’ to an rvalue of type
  // ‘MyClass’
  //    38 |   printMyClassValue(12);
  //       |                     ^~
  // test_single_argue_implict_convert_err2.cc:6:3: note:   after user-defined
  // conversion: ‘MyClass::MyClass(int)’
  //     6 |   MyClass(int value) : m_value(value) {
  //       |   ^~~~~~~
  // test_single_argue_implict_convert_err2.cc:20:33: note:   initializing
  // argument 1 of ‘void printMyClassValue(MyClass&)’
  //    20 | void printMyClassValue(MyClass& obj) { obj.printValue(); }

  return 0;
}
