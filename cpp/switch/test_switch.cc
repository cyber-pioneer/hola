#include <iostream>

static void check(const int &x) {
  switch (x) {
  case 1:
    std::cout << "one" << std::endl;
  case 2:
    std::cout << "two" << std::endl;
  case 3:
    std::cout << "three" << std::endl;
  default:
    std::cout << "other" << std::endl;
  }
}

int main() {
  // check(1);
  check(2);
  // check(3);
  return 0;
}

// output:
// two
// three
// other

// switch 语句在匹配到第一个case时，会将当前case后后续所有case
// 包括default后的语句都执行， 如果case 2 和 case 3 之间没有break，则执行完case
// 2 后，会继续执行case 3 和default 的语句。 因此，一般在case
// 后面加上break，避免出现这种问题。
