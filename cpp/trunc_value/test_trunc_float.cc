#include <cmath> // 用于std::isinf函数
#include <iostream>
#include <limits> // 用于std::numeric_limits<float>::infinity()函数

float truncateInfinityAndMaxValue(float value, float maxValue) {
  if (std::isinf(value) || value > maxValue) {
    return maxValue;
  }
  return value;
}

int main() {
  float maxValue =
      float(std::numeric_limits<double>::max()); // 设置你想要的最大值
  float value1 = 123.45f; // 一个大于最大值的普通浮点数
  float value2 = std::numeric_limits<float>::max(); // 无穷大值

  float truncatedValue1 = truncateInfinityAndMaxValue(value1, maxValue);
  float truncatedValue2 = truncateInfinityAndMaxValue(value2, maxValue);

  std::cout << "Original Value1: " << value1
            << ", Truncated: " << truncatedValue1 << std::endl;
  std::cout << "Original Value2: "
            << "inf"
            << ", Truncated: " << truncatedValue2 << std::endl;

  return 0;
}
