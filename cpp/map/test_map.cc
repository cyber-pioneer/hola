#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param s string字符串
   * @return bool布尔型
   */
  bool isValid(string s) {
    // write code here
    unordered_map<char, char> check = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    int len = s.length();
    if (len < 1 || len % 2 == 1)
      return false;
    // cout<<s.length()%2;
    std::stack<char> tmp;
    tmp.push(s[0]);

    for (size_t i = 1; i < s.length(); i++) {
      cout << " i " << i << endl;
      cout << s.at(i) << endl;
      // cout<<" map: "<<check[tmp.top()]<<endl;
      if (tmp.size() != 0 && check.find(tmp.top()) != check.end() &&
          check[tmp.top()] == s.at(i)) {
        tmp.pop();
      } else {
        tmp.push(s.at(i));
      }
    }

    return tmp.size() == 0 ? true : false;
  }
};

int main() {
  Solution obj;
  cout << obj.isValid("(){}[]");
  return 0;
}
