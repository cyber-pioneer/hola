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

void dfs(std::vector<int> &nums, int l_n, int r_n) {
  if (l_n >= r_n)
    return;
  int l = l_n;
  int r = r_n;
  int mid = l;
  while (l < r) {
    if (nums[r] >= nums[mid]) {
      r--;
    } else if (nums[l] <= nums[mid]) {
      l++;
    } else if (nums[l] > nums[r]) {
      std::swap(nums[l], nums[r]);
    }
  }
  std::swap(nums[l], nums[mid]);

  dfs(nums, l_n, mid);
  dfs(nums, mid + 1, r_n);
}

int main() {
  std::vector<int> org = {2, 6, 5, 3, 3, 7};

  auto ref = org;
  std::sort(ref.begin(), ref.end());
  dfs(org, 0, org.size() - 1);
  // check(org, ref);
  for (auto x : org) {
    std::cout << x << " ";
  }
  return 0;
}
