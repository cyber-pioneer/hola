#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <vector>

void print_cpp_version() {
#if defined(__GNUC__) && defined(__cplusplus)
  // GCC 和兼容的编译器（如 Clang）
  // __cplusplus 宏通常设置为编译时指定的C++标准的年份值（如 201103L 对于 C++11,
  // 201402L 对于 C++14, 201703L 对于 C++17, 202002L 对于 C++20）
  std::cout << "C++ version supported by the compiler: C++" << __cplusplus
            << std::endl;
#elif defined(_MSC_VER)
  // MSVC 编译器
  // MSVC 不提供直接检查C++版本的宏，但你可以根据 _MSC_VER 的值来推测
  // 但是请注意，这不是一个准确的方法，因为_MSC_VER的更新并不总是与C++标准的更新同步
  int cpp_version = 0;
  if (_MSC_VER >= 1920)
    cpp_version = 20; // 大约对应于 MSVC 2019 和更新版本，支持 C++20
  // ... 可以添加更多条件来检测其他版本
  std::cout << "C++ version supported by the compiler: C++" << cpp_version
            << std::endl;
#else
  std::cout << "Unknown compiler, unable to detect C++ version." << std::endl;
#endif
}

using namespace std;

template <typename T> void print(T x) {
  std::cout << "********* test type case " << typeid(T).name() << " ********* "
            << std::endl;
  for (auto item : x) {
    cout << item << " ";
  }
  cout << endl;
}

void test_vector() {
  vector<int> a = {2, 3, 4};
  vector<int> bb{5, 6, 7, 8, 9, 8};
  a.assign(bb.begin(), bb.begin() + 4); // 原始a的数据不会保留，会被重新构造
  print(a);
  int target = 8;

  // 使用std::count计算target在vec中出现的次数
  size_t count = std::count(a.begin(), a.end(), target);

  std::cout << "The number " << target << " appears " << count
            << " times in the vector." << std::endl;
  a.push_back(5);
  a.pop_back();
  swap(a[0], a[1]);

  sort(a.begin(), a.end());
  print(a);
  int t1 = a.back();
  t1 = 9;
  print(a);
  reverse(a.begin(), a.begin() + 2); // 遵循左闭右开原则
  a.erase(a.begin());

  a.erase(a.begin(), a.begin() + 2);
  a.insert(a.begin(), 6);
  int tmp = a.at(0);

  a.erase(a.begin());
  a.push_back(8);
  bool flag = a.empty();
  print(a);
  auto tar = std::find(a.begin(), a.end(), 6);
  cout << (*tar) << endl;
  vector<vector<int>> c = {{1, 2, 3}, {4, 5, 6}};
  auto it = c.begin();
  (*it)[0] = 9;
  print(*it);
  print((*c.begin()));

  return;
}

void test_set() {
  set<int> a = {2, 3, 4, 5};
  auto b = a.count(2);
  a.insert(6);
  a.erase(1); // 元素不存在也不会报错
  a.erase(3);
  auto it1 = std::find(a.begin(), a.end(), 5);
  // (*it1) = 10;
  auto it2 = a.find(4);
  auto num = a.count(3);
  auto num2 = std::count(a.begin(), a.end(), 3);
  print(a);

  return;
}
void test_string() {
  string a = "abcde";
  string b(a);
  string c(a.begin(), a.begin() + 4);
  string d(5, 't'); // ""是string，''是char
  // string m = a[2]; // string由char组成
  char m = a[2];
  string n = to_string(m);
  b += m;
  b += c;
  b.append(c);
  b.push_back('t');
  b.insert(3, "q"); // insert针对string
  b.find('m');
  auto e = b.substr(2, 3);

  return;
}
void test_map() { return; }
void test_unordered_map() {
  std::unordered_map<std::string, int> myMap = {
      {"apple", 1}, {"banana", 2}, {"cherry", 3}};
  // myMap.emplace({"k1", 4}); //error
  myMap.emplace("k1", 4);
  myMap.insert({"k2", 5});
  myMap["k3"] = 6;
  myMap.erase("k3");
  auto it = myMap.find("k2");
  myMap.erase(it);

  // 使用迭代器遍历unordered_map并打印所有键
  for (const auto &pair : myMap) {
    std::cout << pair.first << std::endl; // pair.first是键，pair.second是值
  }

  // 或者使用begin()和end()函数
  for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    std::cout << it->first << std::endl; // it->first是键，it->second是值
  }

  return;
}
void test_list() {
  std::list<int> myList = {1, 2, 3, 4, 5};
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::list<int> a(vec.begin(), vec.end());
  // myList.insert(myList.begin(), 7);

  auto middle = myList.begin();
  std::advance(
      middle,
      myList.size() /
          2); // std::advance是一个模板函数，它可以接受一个迭代器和一个整数偏移量，并将迭代器向前或向后移动指定的偏移量。

  // 在中间位置插入一个元素
  myList.insert(middle, 3); // 现在列表是 1, 2, 3, 4, 5

  return;
}

void test_deque() {
  deque<int> a = {1, 2, 3};
  vector<int> vec = {1, 2, 3};
  deque<int> b(a);
  deque<int> c(a.begin(), a.end());

  return;
}

void test_stack() {
  deque<int> org = {1, 2, 3};
  stack<int> a(org);

  // auto it1 = std::find(a.begin(), a.end(), 5);
  // (*it1) = 10;
  // auto it2 = a.find(4);
  // auto num = a.count(3);
  // auto num2 = std::count(a.begin(), a.end(), 3);
  return;
}
void test_queue() {
  deque<int> org = {1, 2, 3};
  queue<int> a(org);
  return;
}

void test_algorithm() { return; }

int main() {
  print_cpp_version();
  // test_vector();
  test_set();
  test_deque();
  test_stack();
  test_queue();
  test_unordered_map();
  test_list();
  test_string();
  return 0;
}
