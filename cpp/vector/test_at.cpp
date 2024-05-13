#include <iostream>
#include <vector>

int main() {
  std::vector<int> aa{1, 2, 3};
  aa[0] = 5;
  aa.at(1) = 10;
  std::cout << "out of range vector [] " << aa[4] << std::endl;
  std::cout << "out of range vector at " << aa.at(4) << std::endl;
  return 0;
}

// 1.
// 异常处理：当访问超出范围的索引时，[]操作符不会进行任何检查，也不会抛出异常，但是结果异常，是未定义的。而at函数会检查索引是否超出范围，如果超出范围，会抛出std::out_of_range异常。
// 2.
// 性能：由于[]操作符不需要进行边界检查，因此在访问元素时通常比at函数更快一些。
// 总结：确认索引不会超出范围，否则建议使用at函数。
