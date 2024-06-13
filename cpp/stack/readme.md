在C++标准库中，std::stack是一个容器适配器，它提供了后进先出（LIFO）的数据结构。这意味着最后添加到栈中的元素将是第一个被移除的元素。下面是一些std::stack的常见方法：

构造函数
stack(): 创建一个空的栈。

stack(const stack& other): 创建一个栈，它是另一个栈的副本。

容量方法
empty() const: 检查栈是否为空。如果栈为空，则返回true；否则返回false。

size() const: 返回栈中元素的数量。

修改方法
push(const value_type& val): 将元素添加到栈顶。

pop(): 移除栈顶的元素。如果栈为空，则此操作是未定义的。

emplace(Args&&... args): 在栈顶直接构造一个元素。

访问方法
top() const: 返回栈顶元素的引用。如果栈为空，则此操作是未定义的。
