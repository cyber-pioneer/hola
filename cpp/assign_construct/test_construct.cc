#include <iostream>

class Base {
  int *data;

public:
  Base() { std::cout << "init Base obj" << std::endl; }
  Base(const Base &) { std::cout << " copy constructor called" << std::endl; }
  Base(const Base &&) { std::cout << " move constructor called" << std::endl; }

  Base &operator=(Base &other) {
    if (this == &other) //防止自拷贝
      return *this;
    std::cout << " copy assign called" << std::endl;
    this->data = other.data;
    return *this;
  }
  Base &operator=(Base &&other) {
    if (this == &other)
      return *this;
    this->data = other.data;
    other.data = nullptr;
    std::cout << " move assign called" << std::endl;
    return *this;
  }
};

int main() {
  Base b1;
  Base b2(b1);
  Base b3 = std::move(b1);
  b3 = b1;
  Base b5;
  b5 = std::move(b2);
  return 0;
}
