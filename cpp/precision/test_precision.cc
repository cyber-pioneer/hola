#include <algorithm>
#include <cfenv>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

namespace {
template <typename T> bool isCloseEqualMax_value(T const value) {
  T max_value = std::numeric_limits<T>::max();
  T tol = std::numeric_limits<T>::denorm_min();
  return (max_value - value) < tol;
}
} // namespace

float truncateInfinityAndMaxValue(float value, float maxValue) {
  if (std::isinf(value) || value > maxValue) {
    return maxValue;
  }
  return value;
}

int main() {
  float v = std::numeric_limits<float>::lowest();
  auto res = isCloseEqualMax_value<float>(v);
  float tt = -float(std::numeric_limits<double>::max());

  std::cout << " tt>v " << (tt < v) << " " << v << std::endl;

  std::cout << " " << res << std::endl;
  std::ostringstream ss;
  // if (res)
  std::fesetround(FE_TOWARDZERO); //朝0近似，正数会截断
  ss << std::setprecision(std::numeric_limits<float>::max_digits10);
  ss << std::showpoint;
  ss << truncateInfinityAndMaxValue(tt, v);
  std::string result = ss.str();
  std::cout << result << std::endl;
  return 0;
}
