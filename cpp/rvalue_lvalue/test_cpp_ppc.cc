#include <iostream>
#include <vector>

int main(void) {
  for (size_t i = 0; i < 5; i++) {
    std::cout << i << std::endl;
  }

  for (size_t j = 0; j < 5; ++j) {
    std::cout << j << std::endl;
  }
  int m = 3;
  int n = m++;
  std::cout << m << " " << n << std::endl;

  int k = 3;
  int t = ++k;
  std::cout << k << " " << t << std::endl;
  return 0;
}
