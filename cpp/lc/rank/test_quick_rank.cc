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

std::vector<int> dfs(std::vector<int> nums) {
  int len = nums.size();
  if (len <= 1) {
    return nums;
  }
  std::vector<int> l;
  std::vector<int> r;
  int mid = len / 2; // mid可以是任意固定的索引，比如0
  for (int i = 0; i < len; ++i) {
    if (i == mid)
      continue;
    if (nums[i] >= nums[mid]) {
      r.push_back(nums[i]);
    } else {
      l.push_back(nums[i]);
    }
  }
  std::vector<int> res;
  for (auto i : dfs(l)) {
    res.push_back(i);
  }
  res.push_back(
      nums[mid]); // 注意这里是把中间的数插入到最后面，而不是在前面（因为前面已经排好序了
  for (auto j : dfs(r)) {
    res.push_back(j);
  }
  return res;
}

int main() {
  std::vector<int> org = {7, 2, 4, 5, 3, 3, 7};

  auto ref = org;
  std::sort(ref.begin(), ref.end());
  auto res = dfs(org);
  check(res, ref);
  // for (auto x : res) {
  //   std::cout << x << " ";
  // }
  return 0;
}
