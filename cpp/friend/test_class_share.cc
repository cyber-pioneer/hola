
#include <iostream>
using namespace std;

class Date; //对Date类的提前引用声明
class Time {
public:
  Time(int h, int m, int s) {
    hour = h;
    minute = m;
    sec = s;
  }
  void display(Date &);

private:
  int hour;
  int sec;
  int minute;
};

class Date {
public:
  Date(int m, int d, int y) {
    mouth = m;
    day = d;
    year = y;
  }
  friend void Time::display(Date &);

private:
  int mouth;
  int day;
  int year;
};

void Time::display(Date &d) {
  cout << d.mouth << "/" << d.day << "/" << d.year << endl;
  cout << hour << ":" << minute << ":" << sec << endl;
}

int main(void) {
  Time t1(10, 13, 56);
  Date d1(4, 15, 2019);
  t1.display(d1);
  return 0;
}
