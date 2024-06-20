#include <algorithm> // 包含 std::replace
#include <iostream>
#include <vector>

int main() {
  // 创建一个包含一些初始值的 vector
  std::vector<int> my_vector = {1, 2, 3, 2, 5, 2, 7};

  // 打印原始 vector
  std::cout << "Original vector: ";
  for (int value : my_vector) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  // 使用 std::replace 替换所有 2 为 9
  std::replace(my_vector.begin(), my_vector.end(), 2, 9);

  // 打印替换后的 vector
  std::cout << "Modified vector: ";
  for (int value : my_vector) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  return 0;
}
