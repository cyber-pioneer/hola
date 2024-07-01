#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<typeinfo>


void print_cpp_version() {
#if defined(__GNUC__) && defined(__cplusplus)
    // GCC 和兼容的编译器（如 Clang）
    // __cplusplus 宏通常设置为编译时指定的C++标准的年份值（如 201103L 对于 C++11, 201402L 对于 C++14, 201703L 对于 C++17, 202002L 对于 C++20）
    std::cout << "C++ version supported by the compiler: C++" << __cplusplus<< std::endl;
#elif defined(_MSC_VER)
    // MSVC 编译器
    // MSVC 不提供直接检查C++版本的宏，但你可以根据 _MSC_VER 的值来推测
    // 但是请注意，这不是一个准确的方法，因为_MSC_VER的更新并不总是与C++标准的更新同步
    int cpp_version = 0;
    if (_MSC_VER >= 1920) cpp_version = 20; // 大约对应于 MSVC 2019 和更新版本，支持 C++20
    // ... 可以添加更多条件来检测其他版本
    std::cout << "C++ version supported by the compiler: C++" << cpp_version << std::endl;
#else
    std::cout << "Unknown compiler, unable to detect C++ version." << std::endl;
#endif
}


using namespace std;

template <typename T>
void print(T x) {
    std::cout << "********* test type case " <<typeid(T).name() <<" ********* " << std::endl;
    for (auto item: x) {
        cout<<item<<" ";
    }
    cout<<endl;


}

void test_vector() {
    vector<int> a = {2,3,4};
    vector<int> bb{2,3,4};
    print(a);
    a.push_back(5);
    a.pop_back();
    swap(a[0], a[1]);

    sort(a.begin(), a.end());
    print(a);
    int t1 = a.back();
    t1 = 9;
    print(a);
    reverse(a.begin(), a.begin()+2);// 遵循左闭右开原则
    a.erase(a.begin());

    a.erase(a.begin(), a.begin()+2);
    a.insert(a.begin(), 6);
    int tmp = a.at(0);
    
    a.erase(a.begin());
    bool flag = a.empty();
    auto count = std::find(a.begin(),a.end(), 6);


    return;
}

void test_set() {

    return;
}
void test_string() {

    return;
}
void test_map() {

    return;
}
void test_unordered_nap() {

    return;
}
void test_list() {

    return;
}
void test_stack() {

    return;
}
void test_queue() {

    return;
}
void test_deque() {

    return;
}
void test_algorithm() {

    return;
}

int main() {
    print_cpp_version();
    test_vector();
    return 0;
}