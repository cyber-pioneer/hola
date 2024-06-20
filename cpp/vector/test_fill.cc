#include <algorithm> // 包含 std::fill
#include <iostream>
#include <vector>

int main() {
  // 创建一个包含一些初始值的 vector
  std::vector<int> my_vector = {1, 2, 3, 4, 5};

  // 打印原始 vector
  std::cout << "Original vector:" << std::endl;
  for (int value : my_vector) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  // 使用 std::fill 替换所有元素为特定值（例如0）
  std::fill(my_vector.begin(), my_vector.end(), 0);

  // 打印替换后的 vector
  std::cout << "Modified vector:" << std::endl;
  for (int value : my_vector) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  return 0;
}
