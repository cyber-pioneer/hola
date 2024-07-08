#include <algorithm>
#include <iostream>
#include <vector>


int main() {
  std::vector<int> v = {3, 6, 4, 1, 3, 7, 9, 2, 4, 5, 0};

  // rank vector here

  for (int &i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
