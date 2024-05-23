#include <iostream>
// #include "aa.h"
#include "bb.h"

int main() {
  // f1();
  f2();
  return 0;
}

// g++ main.cc bb.cc -o main.o && ./main.o
// output

//  call f1*****
//  call f2*****

// 将f1用static修饰后，以下报错即不再出现
// static修饰表示该函数仅被定义的目标文件可见（.h文件是特殊的宏，会被展开，不是编译的目标，因此不属于，而include该文件的.cc文件才算）
// /usr/local/bin/ld: /tmp/cckINsKI.o: in function `f1()':
// bb.cc:(.text+0x0): multiple definition of `f1()';
// /tmp/ccA6dbNv.o:main.cc:(.text+0x0): first defined here collect2: error: ld
// returned 1 exit status

// 解析：
// f1()在aa.h里定义
// 第一次发现定义：main.cc include bb.h, bb.h include aa.h,
// 发现aa.h里已经定义了f1() 第二次发现定义：编译 bb.cc, bb.cc include bb.h, bb.h
// include aa.h, 发现aa.h里已经定义了f1() 这两次定义冲突
