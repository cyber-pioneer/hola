#include <algorithm>
#include <iostream>
#include <vector>

void dfs(std::vector<int> &res, int l, int r) {
  std::cout << "begin 3*** " << std::endl;
  if (l >= r)
    return;
  int i = l;
  int j = r;
  int tmp = res[l];
  while (i < j) {
    std::cout << "begin 4*** " << i << j << std::endl;
    while (res[j] > tmp && i < j) {
      j--;
    }
    while (res[i] <= tmp && i < j) {
      i++;
    }
    std::swap(res[j], res[i]);
  }
  std::swap(res[l], res[i]);
  dfs(res, l, i - 1);
  dfs(res, i + 1, r);
}

int main() {
  std::cout << "begin*** " << std::endl;
  std::vector<int> v = {3, 6, 4, 1, 3, 7, 9, 2, 4, 5, 0};
  for (int &i : v) {
    std::cout << "begin*** 2" << std::endl;
    std::cout << i << " ";
  }
  dfs(v, 0, v.size() - 1);
  for (int &i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
