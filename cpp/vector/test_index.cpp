#include <iostream>
#include <vector>

int main() {
  std::vector<int> aa{0, 1, 2};
  std::vector<int> bb(aa.begin(), aa.begin() + 2);
  for (auto &i : bb) {
    std::cout << "i*** " << i << std::endl;
  }
  return 0;
}

// i*** 0
// i*** 1

// 迭代器初始化遵循左闭右开原则，注意要确保索引在容器内，否则不会报错，但是产生异常值
