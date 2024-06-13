#include <iostream>
#include <queue>
#include <stack>
#include <vector>
// #include<deque>

// deque 头文件已包含在 stack和queue内

int main() {
  std::vector<int> v = {1, 2, 3, 4};
  std::deque<int> d = {1, 2, 3};
  // std::stack<int> s = {1,2,3}; //错误！容器适配器不支持这样的列表初始化
  // std::stack<int> s(v); //错误！stack是基于deque实现的，不能直接用vector构造,
  // no known conversion for argument 1 from ‘std::vector<int>’ to
  // ‘std::stack<int>&&’
  std::stack<int> s(d);
  std::queue<int> q;
  return 0;
}
