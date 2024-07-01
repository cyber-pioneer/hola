在 C++ 的标准模板库 (STL) 中，std::array 和 std::vector 都是用于存储序列数据的容器，但它们之间存在一些重要的区别。

std::array (使用频率低)
std::array **是一个固定大小的容器，它包含固定数量的元素，这些元素在编译时确定**。std::array 提供了与 C 风格数组相似的接口，但它是类型安全的，并且支持 STL 容器的一些特性，如迭代器。

特点：
固定大小：一旦定义，就不能改变大小。

连续存储：元素在内存中连续存储。

类型安全：提供了类型安全的接口。

支持 STL 容器接口：例如迭代器、begin()、end() 等。

#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    for (int i : arr) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
std::vector
std::vector 是一个动态数组，它可以动态地改变大小。std::vector 在内部使用一个连续的内存块来存储元素，但在需要时可以重新分配内存并移动元素。

特点：
动态大小：可以在运行时添加或删除元素，从而改变大小。

连续存储：在大多数情况下，元素在内存中连续存储（尽管在某些情况下可能需要重新分配和移动）。

类型安全：提供了类型安全的接口。

支持 STL 容器接口：例如迭代器、push_back()、pop_back()、insert()、erase() 等。


#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    for (int i : vec) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
区别
大小：std::array 的大小在编译时确定，而 std::vector 的大小可以在运行时改变。

性能：由于 std::array 的大小是固定的，因此它通常比 std::vector 更快（因为没有动态内存分配和重新分配的开销）。但是，如果你需要动态地改变大小，那么 std::vector 是更好的选择。

接口：两者都支持 STL 容器的接口，但 std::array 还提供了 C 风格数组的接口（例如使用下标访问元素）。

初始化：std::array 必须在使用前初始化（可以在定义时直接初始化），而 std::vector 可以在定义后动态地添加元素。

兼容性：std::array 与 C 风格数组在接口上更为相似，因此与某些 C API 或库可能更容易兼容。但是，std::vector 提供了更多的功能和灵活性。
