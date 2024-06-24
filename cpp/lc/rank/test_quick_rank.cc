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

void dfs(std::vector<int> &nums, int l1, int r1) {
  if (l1 >= r1)
    return;
  int l = l1;
  int r = r1;
  int mid = l;

  while (l<r) {
    int mid_v = nums[mid];
    if (nums[mid] <= nums[r]) {
      r --;
    } else if (nums[l] < nums[mid]) {
      l ++;
    } else if (nums[l] > nums[r]){
      std::swap(nums[l], nums[r]);
    } 

  }
  std::swap(nums[mid], nums[l]);

  dfs(nums, l1, mid-1);
  dfs(nums, mid + 1, r1);
}

int main() {
  std::vector<int> org = {5, 2, 3, 3, 7};

  auto ref = org;
  std::sort(ref.begin(), ref.end());
  dfs(org, 0, org.size() - 1);
  check(org, ref);
  for (auto x : org) {
    std::cout << x << " ";
  }
  std::cout<<std::endl;
  return 0;
}
