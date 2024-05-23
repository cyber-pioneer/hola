#include <iostream>
#include <vector>

void fn(std::vector<int> v, int t = 0) {
  v.push_back(2);
  v.erase(v.begin());
}

void fn2(std::vector<int> &v, int t = 0) {
  v.push_back(2);
  v.erase(v.begin());
}

int main() {
  std::vector v = {1, 2, 3};
  auto v1 = v;
  v1.push_back(5);
  auto &v2 = v;
  v2.push_back(5);
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  fn(v);
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  fn2(v);
  for (auto i : v) {
    std::cout << i << " ";
  }
}
