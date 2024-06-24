#include <algorithm>
#include <iostream>
#include <vector>

void dfs(std::vector<int> &res, int l, int r) {
  if (l >= r)
    return;
  int i = l;
  int j = r;
  int tmp = res[l];
  while (i < j) {
    while (res[j] >= tmp && i < j) { // if not >=, 5,2,3,4,5, swap(5, 5);
      j--;
    }
    while (res[i] < tmp && i < j) {
      i++;
    }
    std::swap(res[j], res[i]);
  }
  std::swap(res[l], res[i]);
  dfs(res, l, i);
  dfs(res, i + 1, r);
}

int main() {
  std::vector<int> v = {3, 6, 4, 1, 3, 7, 9, 2, 4, 5, 0};
  dfs(v, 0, v.size() - 1);
  for (int &i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
