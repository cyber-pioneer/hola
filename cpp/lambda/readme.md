在 C++ 中，lambda 表达式（也称为 lambda 函数或匿名函数）是一种可以定义在代码中任何地方的小型匿名函数对象。Lambda 表达式特别适用于需要一个小函数但又不想费力去定义一个完整的函数或函数对象的情况。它们常用于算法库中的排序、查找等函数，以及需要回调函数的场景。


```
[capture](parameters) -> return_type { body }
```

capture：捕获子句，指定哪些外部变量可以在 lambda 体内使用，以及如何捕获它们（按值或按引用）。

parameters：参数列表，和普通的函数参数列表一样。

return_type：返回类型，如果 lambda 表达式没有返回语句，可以省略。

body：lambda 函数的主体，包含一系列的语句。

**无捕获、无参数、无返回值的 lambda 表达式：**
```cpp
auto lambda = [] { std::cout << "Hello, lambda!" << std::endl; };
lambda(); // 输出 "Hello, lambda!"
```

**有捕获、有参数、有返回值的 lambda 表达式：**
```cpp
int x = 10;
auto add_to_x = [&x](int a) { return a + x; };
int y = add_to_x(5); // y 的值是 15，因为 x 的值被捕获并按引用使用
```
在上面的例子中，[&x] 是捕获子句，它表示以引用的方式捕获变量 x。这样，add_to_x lambda 表达式内部就可以访问并修改 x 的值了。

**使用 const 和 & 来按值或按引用捕获：**
```cpp
int z = 20;
auto by_value = [z](int b) { return b * z; }; // z 被按值捕获
auto by_ref = [&z](int b) { z += b; }; // z 被按引用捕获
```

**Lambda 表达式可以非常方便地用在 std::sort 等算法中，作为自定义的比较函数**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    // 使用 lambda 表达式作为比较函数，对 vector 进行排序
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });

    // 输出排序后的 vector
    for (int num : numbers) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}
```
