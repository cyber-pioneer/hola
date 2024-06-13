### queue

void 方法

pop()
push(T x)

非void方法

front(): 返回队首元素的值，但不移除它。

back(): 返回队尾元素的值，但不移除它。

size()

### stack 常见方法
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
top() const: 返回栈顶元素的引用。**如果栈为空**，则此操作是未定义的。


介绍列表构造

https://blog.csdn.net/qq_44228301/article/details/129629897
