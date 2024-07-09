#include <iostream>
#include <vector>

int tar = 5;

void find(std::vector<int> &x, int l, int r, int &idx) {
  int i = l, j = r;
  while (i <= j) {
    int mid = (i + j) / 2;
    if (x[mid] == tar) {
      idx = mid;
      return;
    } else if (x[mid] > tar) {
      j = mid - 1;
    } else {
      i = mid + 1;
    }
  }
}

int main() {
  std::vector<int> res = {1, 3, 5, 6, 6, 7, 9, 10};
  int idx = -1;
  find(res, 0, res.size() - 1, idx);
  std::cout << "find idx *** " << idx << std::endl;
  return 0;
}
