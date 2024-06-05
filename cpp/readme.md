## explicit
用于修饰只有一个参数的类构造函数，以表明该构造函数不应当被用于隐式类型转换。当一个构造函数被声明为explicit时，它不能作为隐式转换操作符来转换类型；相反，为了调用这个构造函数，必须显式地创建一个对象。
注：only declarations of constructors and conversion operators can be ‘explicit’

为了解决单参数构造函数的隐式转换问题，私以为单参数构造函数的隐式转换不应该存在，但是为了兼容，搞出explicit关键字
```C++
class Foo {
public:
    explicit Foo(int x) { // 使用 explicit 修饰构造函数
        // ...
    }
};

void someFunction(Foo fooObject) {
    // ...
}

int main() {
    // Foo foo = 42; // 这行代码会导致编译错误，因为构造函数是显式的
    Foo foo(42); // 正确的调用方式，显式构造
    someFunction(Foo(42)); // 在函数调用中也需要显式构造
    // someFunction(42); // 这会导致编译错误，因为不能隐式转换为 Foo 类型
    return 0;
}
```

## std::move
创建右值引用，用于移动构造和移动赋值

## 移动构造和移动赋值
为了解决拷贝构造和拷贝赋值带来的性能问题，C++11引入了移动构造和移动赋值
