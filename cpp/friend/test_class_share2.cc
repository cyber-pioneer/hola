#include <iostream>
using namespace std;

class Car; //向前引用说明
class Boat {
public:
  Boat(double we1 = 0) : weight1(we1){}; //构造函数

  friend double TotalWeight(Boat &B, Car &C);

private:
  double weight1;
};
class Car {
public:
  Car(double we2 = 0) : weight2(we2){}; //构造函数

  friend double TotalWeight(Boat &B, Car &C);

private:
  double weight2;
};
double TotalWeight(Boat &B, Car &C) {
  //友元函数可以定义为其他的类型，视具体情况而定，比如double\int\void\你自己定义的类，都是可以的
  double total = B.weight1 + C.weight2;
  return total;
}
int main() {
  Boat a(100);
  Car b(20);
  cout << "totalweight=" << TotalWeight(a, b) << endl;
  ;
  return 0;
}
