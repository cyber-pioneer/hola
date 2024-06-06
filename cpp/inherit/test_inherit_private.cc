#include <iostream>

class Base {
public:
  void set_in_public(const int &x) {
    set_in_private(x);
    // value = x;
  }
  void get_in_public() {
    std::cout << "value******* " << value << " " << &value << std::endl;
  }

private:
  void set_in_private(const int &x) { value = x; }
  int value;

protected:
  void set_in_protect(const int &x) { value = x; }
  int value_protect;
};

class Derive : public Base {
  // public:
  // void set_in_derive_public(const int &x) {
  //     set_in_private(x); // 自定义的方法是无法访问父类的private变量
  //     // value = x;
  // }
public:
  void set_in_derive_public(const int &x) {
    value_protect = x; // 自定义的方法是无法访问父类的private变量
  }
};

int main() {
  Base b;
  b.set_in_public(5);
  b.get_in_public();
  // b.set_in_protect(6); //
  // 父类中的保护成员变量不能被派生类访问，但是可以在派生的public方法内或者自定义的方法内访问和修改
  Derive d;
  d.set_in_public(10);
  d.get_in_public();
  // d.set_in_private(3);
  b.get_in_public();
}

// private 成员变量只能被本类和友元函数访问，派生类里是无法继承的，
// 但可以通过继承的public 方法在内部访问或修改父类私有成员变量或函数
