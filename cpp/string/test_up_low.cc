#include <cctype> // 包含toupper和tolower
#include <iostream>
#include <string>

std::string switchCase(const std::string &str) {
  std::string result = str;
  for (char &c : result) {
    if (std::isalpha(c)) { // 检查字符是否是字母
      if (c >= 'a' && c <= 'z') {
        // c = std::toupper(c); // 转换为大写
        c = c - 'a' + 'A';
      } else {
        // c = std::tolower(c); // 转换为小写
        c = c - 'A' + 'a'; //通过ascii码的偏移实现大小写转换
      }
    }
  }
  return result;
}

int main() {
  std::string str = "Hello, World!";
  std::string upperStr = switchCase(str); // 转换为大写

  std::cout << "Original: " << str << std::endl;
  std::cout << "newcase: " << upperStr << std::endl;

  return 0;
}
