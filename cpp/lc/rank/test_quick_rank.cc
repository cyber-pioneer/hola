#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

void check(std::vector<int> ref, std::vector<int> actual) {
  if (ref.size() != actual.size())
    throw std::runtime_error(" rank diff ");
  for (int i = 0; i < ref.size(); ++i) {
    if (ref[i] != actual[i])
      throw std::runtime_error(" value diff ");
  }
}

void dfs(std::vector<int> &nums, int l, int r) {
  if (l >= r)
    return;
  int mid = l;
  for (int i = l; i <= r; i++) {
    std::cout << l << mid << r << std::endl;
    if (nums[i] < nums[mid]) {
      std::swap(nums[mid], nums[i]);
      mid = i;
    }
  }
  dfs(nums, l, mid);
  dfs(nums, mid + 1, r);
}

int main() {
  std::vector<int> org = {7, 2, 4, 5, 3, 3, 7};

  auto ref = org;
  std::sort(ref.begin(), ref.end());
  dfs(org, 0, org.size() - 1);
  // check(org, ref);
  for (auto x : org) {
    std::cout << x << " ";
  }
  return 0;
}
