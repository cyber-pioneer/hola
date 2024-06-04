#include <iostream>
#include <vector>

template <typename T1, typename T2> void foo(T1, T2) {}

void bar() {
  foo<int>(1, 2.0); // 可以推导，T2为double
}

void baz() {
  foo<int>(1,
           "hello"); // 错误：无法从字符串字面量推导T2的类型，除非有合适的转换
}

int main() {
  const auto str = "hello world"; // 错误
  std::cout << "C++ version: " << __cplusplus << std::endl;
  baz();
  return 0;
}
