#include <iostream>
#include <stack>
#include <vector>

int main() {
  // 使用初始化列表初始化一个int类型的stack
  std::vector<int> a = {1, 2, 3};
  std::stack<int> myStack(a.begin(), a.end());

  // 打印stack的元素
  while (!myStack.empty()) {
    std::cout << ' ' << myStack.top();
    myStack.pop();
  }

  return 0;
}
