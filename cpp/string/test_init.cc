#include <iostream>

int main() {
  std::string multiLineString = R"(#This is line 1.
This is line 2.
#include
This is line 3.)";
  std::cout << "**** " << multiLineString;
}
