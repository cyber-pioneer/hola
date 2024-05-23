#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
// #include<typeid>

void fn(std::vector<std::vector<int>> &v, std::vector<int> &res,
        std::vector<int> &tmp) {
  std::cout << "tmp size: " << tmp.size() << std::endl;
  if (tmp.size() == 0) {
    v.push_back(res);
    std::cout << "res size: " << res.size() << std::endl;
    return;
  }
  for (int i = 0; i < tmp.size(); i++) {
    std::vector<int> tmp1 = tmp;
    std::vector<int> res1 = res;
    res1.push_back(tmp1[i]);
    for (auto i : tmp1) {
      std::cout << i << " .. ";
    }
    tmp1.erase(tmp1.begin() + i);
    fn(v, res1, tmp1);
  }
}

int main() {
  std::vector<int> v = {1, 2, 3};
  std::vector<std::vector<int>> res;
  std::vector<int> tt;
  fn(res, tt, v);
  for (auto i : res) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
  std::cout << res.size() << std::endl;
}
