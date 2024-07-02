#include <algorithm>
#include <iostream>
#include <vector>

void dfs(std::vector<int> &res, int l, int r) {
  if (l >= r)
    return;
  int i = l;
  int j = r;
  int tar_idx = l; // any index
  int tar = res[tar_idx];
  std::cout << "** " << i << j << std::endl;
  for (int m = i; m <= j; m++) {
    std::cout << res[m] << " " << std::endl;
  }
  while (i < j) {
    while (res[j] >= tar && i < j) {
      // if not >=, 5,2,3,4,5, swap(5, 5); 确保j对应的值小于tar
      // if i<=j ,i++ may > j or i may > j--
      // 先右后左，对于[4,2,1,0]，i,j[0,3] --> [0,2,1,4] -->i=2,j=2
      // 若先左后右，对于[4,2,1,0]，i,j[0,3]
      // -->[0,2,1,4]-->i=3,j=3-->dfs(res,0,3)死循环
      j--;
    }
    while (res[i] < tar && i < j) {
      i++;
    }
    std::cout << "== " << i << j << std::endl;

    std::swap(res[j], res[i]);
  }
  std::swap(res[tar_idx], res[i]);
  dfs(res, l, i);
  dfs(res, i + 1, r);
}

int main() {
  // std::vector<int> v = {3, 6, 4, 1, 3, 7, 9, 2, 4, 5, 0};
  std::vector<int> v = {4, 2, 1, 0};
  dfs(v, 0, v.size() - 1);
  for (int &i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
