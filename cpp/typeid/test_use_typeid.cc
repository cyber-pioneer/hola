#include <iostream>
#include <typeinfo>
#include <vector>

int main() {
  std::vector<int> v(4, 1);
  std::cout << "size**** " << v.size() << std::endl;
  auto dd = v.size() - 1;
  std::cout << "type**** " << typeid(v).name() << std::endl;
  std::cout << "type**** " << typeid(dd).name() << std::endl;
}

// g++ test_use_typeid.cc -o main.o && ./main.o
// size**** 4
// type**** St6vectorIiSaIiEE
// type**** m

// g++ test_use_typeid.cc -o main.o && ./main.o |c++filt -t
// size**** 4
// type**** std::vector<int, std::allocator<int> >
// type**** unsigned long

// St6vectorIiSaIiEE 这种字符串通常是在使用 C++ 编译器（特别是 GCC）时，由
// RTTI（运行时类型信息）系统为 std::vector<int> 类型生成的修饰名称。
// 这个字符串是编译器内部用来唯一标识类型的名称，它经过了名称修饰（name
// mangling）或名称改编（name decoration）以处理 C++
// 的重载、模板和命名空间等特性。

// 在这个特定的例子中：

// St 可能是表示标准命名空间 std 的前缀。

// 6vector 表示这是 vector 模板的实例化。

// Ii 很可能表示 int 类型，即 vector 模板中的元素类型。

// Sa 可能是与分配器（allocator）相关的标识。

// Ii 再次出现，可能是作为分配器的一部分或是其他与模板实例化相关的标识。

// EE 是名称修饰字符串的结束部分。

// 总的来说，这个字符串是编译器用来表示 std::vector<int>
// 类型的一个内部编码。如果你在使用 typeid(some_variable).name()
// 时得到了这个字符串， 并且想要得到更人类可读的格式，你可能需要使用一些工具（如
// c++filt，这是 GCC 提供的一个用于解码修饰名称的工具）来将其转换回
// std::vector<int> 这样的形式。

// g++编译器的问题，打印出来的类型需要解码，才能看到真实的类型
// 使用g++的工具 c++filt -t
// c++filt -t St6vectorIiSaIiEE
// std::vector<int, std::allocator<int> >

// https://stackoverflow.com/questions/789402/typeid-returns-extra-characters-in-g
