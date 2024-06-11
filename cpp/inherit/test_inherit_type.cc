class Base {
public:
  int public_member;

protected:
  int protected_member;

private:
  int private_member;
};

class Derived : public Base {
public:
  // 可以直接访问基类的public和protected成员
  void access_members() {
    public_member = 10;    // 正确：直接访问基类的public成员
    protected_member = 20; // 正确：直接访问基类的protected成员
    // private_member = 30;      // 错误：不能访问基类的private成员
  }
};

int main() {
  Derived d;
  d.public_member = 5; // 正确：通过派生类对象直接访问基类的public成员
  // d.protected_member = 15; // 错误：protected成员不能在类外部直接访问
  // d.private_member = 25;   // 错误：private成员不能在类外部直接访问
  d.access_members(); // 正确：通过派生类的成员函数访问基类的成员
  return 0;
}
