#include <iostream>
#include <string>

bool endsWith(const std::string &str, const std::string &suffix) {
  if (str.size() >= suffix.size()) {
    return (str.compare(str.size() - suffix.size(), suffix.size(), suffix) ==
            false);
  }
  return false;
}

int main() {
  std::string myString = "example.txt";
  if (endsWith(myString, ".txt")) {
    std::cout << "The string ends with '.txt'" << std::endl;
  } else {
    std::cout << "The string does not end with '.txt'" << std::endl;
  }
  return 0;
}
