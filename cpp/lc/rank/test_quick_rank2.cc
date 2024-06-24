#include <iostream>
#include <vector>

void dfs(std::vector<int> &res, int l, int r) {
  if (l >= r)
    return;
  int i = l;
  int j = r;
  int tmp = res[l];
  while (i < j) {
    while (res[r] >= tmp && i < j) {
      r--;
      res[i] = res[j];
    }
    while (res[l] < tmp && i < j) {
      l++;
      res[j] = res[i];
    }
  }
  res[i] = tmp;
  dfs(res, l, i - 1);
  dfs(res, i + 1, r);
}

int main() {
  std::vector<int> v = {3, 6, 4, 1, 3, 7, 9, 2, 4, 5, 0};
  for (int &i : v) {
    std::cout << i << " ";
  }
  dfs(v, 0, v.size() - 1);
  for (int &i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
