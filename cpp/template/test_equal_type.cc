#include <iostream>
#include <type_traits>
#include <vector>

// 模板函数，用于判断两个参数的类型是否相同
template <typename T1, typename T2>
void checkVariableTypes(const T1 &var1, const T2 &var2) {
  if (std::is_same<T1, T2>::value) {
    std::cout << "The variables are of the same type." << std::endl;
  } else {
    std::cout << "The variables are of different types." << std::endl;
  }
}

// template<typename T1>
// void checkVariableTypes(const T1& var1, const T1& var2) {
//     std::cout<< 1 <<std::endl;
//     // if (std::is_same<T1, T2>::value) {
//     //     std::cout << "The variables are of the same type." << std::endl;
//     // } else {
//     //     std::cout << "The variables are of different types." << std::endl;
//     // }
// }

int main() {
  // int a = 10;
  // int b = 20;
  // double c = 3.14;
  std::vector<int> a = {1, 2};
  std::vector<int> b = {1, 2};
  std::vector<float> c = {1., 2};

  checkVariableTypes(a, b); // 输出: The variables are of the same type.
  checkVariableTypes(a, c); // 输出: The variables are of different types.

  return 0;
}
