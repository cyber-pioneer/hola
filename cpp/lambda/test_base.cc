#include <iostream>
#include <vector>

// error: ‘var’ is not captured
// int main() {
//     int var = 1;
//     auto sum = [](int a, int b) {
//         var=2;
//         return a+b;
//     };
//     std::cout<<var<<" "<<sum(2,3)<<" "<<var<< std::endl;
//     return 0;
// }

// 1 5 2
// [&]是引用捕获，lambda内可以修改外部的值
int main() {
  int var = 1;
  auto sum = [&](int a, int b) {
    var = 2;
    return a + b;
  };
  std::cout << var << " " << sum(2, 3) << " " << var << std::endl;
  return 0;
}

// error: assignment of read-only variable ‘var’
// [=] 常量捕获，lambda内不能修改外部变量的值
// int main() {
//     int var = 1;
//     auto sum = [=](int a, int b) {
//         var+=2;
//         return a+b;
//     };
//     std::cout<<var<<" "<<sum(2,3)<<" "<<var<< std::endl;
//     return 0;
// }

// error: ‘x’ was not declared in this scope
// []内必须是已有参数
// int main() {
//     int var = 1;
//     auto sum = [x](int a, int b) {
//         x+=2;
//         return a+b;
//     };
//     std::cout<<var<<" "<<sum(2,3)<<" "<<var<< std::endl;
//     return 0;
// }
