#include <vector>
#include <iostream>

int main() {
    std::vector<int*> vec;

    // 动态分配内存并将指针存储在容器中
    auto a = new int(10);
    auto b= new int(20);
    vec.push_back(a);
    vec.push_back(b);

    // 删除容器中的第二个元素（指针）
    vec.erase(vec.end());

    // 注意：此时，尽管我们从容器中删除了指向值为20的int的指针，
    // 但那块内存仍然被分配着，并且我们需要手动释放它。

    // 访问并打印第一个元素（仍然有效）
    std::cout << "size**** "<<vec.size()<<" First element: " << *a << std::endl;

    // 手动释放内存（这是很重要的！）
    for (int* ptr : vec) {
        delete ptr;
    }

    return 0;
}

// int main() {
//     std::vector<int> vec;

//     // 动态分配内存并将指针存储在容器中
//     auto a = 10;
//     auto b= 20;
//     vec.push_back(a);
//     vec.push_back(b);

//     // 删除容器中的第二个元素（指针）
//     vec.erase(vec.begin() + 1);

//     // 注意：此时，尽管我们从容器中删除了指向值为20的int的指针，
//     // 但那块内存仍然被分配着，并且我们需要手动释放它。

//     // 访问并打印第一个元素（仍然有效）
//     std::cout << "First element: " << b << std::endl;

//     // 手动释放内存（这是很重要的！）
//     // for (int* ptr : vec) {
//     //     delete ptr;
//     // }

//     return 0;
// }