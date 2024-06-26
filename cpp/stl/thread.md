多线程异步怎么实现？
在C++中，实现多线程异步编程通常涉及到使用C++11及其后续版本中的<thread>库，或者使用更高级的并发库如<future>（用于异步任务）和<async>（用于启动异步任务）。下面我将介绍几种常见的C++多线程异步编程的实现方式。

1. 使用 <thread> 库
<thread> 库允许你创建和管理线程。但是，直接使用 <thread> 并不直接支持异步操作，因为你需要显式地等待线程完成（通常使用 join() 或 detach()）。不过，你可以通过创建线程来执行长时间运行的任务，从而实现异步处理。

```c++
#include <iostream>
#include <thread>

void task() {
    std::cout << "Thread task is running...\n";
    // 执行一些耗时的操作
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread task is done!\n";
}

int main() {
    std::thread t(task);
    // 主线程可以继续执行其他任务
    std::cout << "Main thread is running...\n";
    // 如果你希望等待线程结束，可以使用 join()
    t.join();
    std::cout << "Main thread is done!\n";
    return 0;
}
```

2. 使用 <future> 和 <async>
<future> 和 <async> 库提供了更高层次的并发支持，允许你以异步方式启动任务并获取其结果。std::async 函数返回一个 std::future 对象，该对象表示异步操作的结果。

```c++
#include <iostream>
#include <future>

int task(int n) {
    std::cout << "Async task is running...\n";
    // 执行一些耗时的操作
    std::this_thread::sleep_for(std::chrono::seconds(n));
    return n * 2;
}

int main() {
    // 使用 std::async 启动异步任务
    std::future<int> result = std::async(std::launch::async, task, 2);
    // 主线程可以继续执行其他任务
    std::cout << "Main thread is running...\n";
    // 在需要的时候获取异步操作的结果
    int value = result.get(); // 这会阻塞，直到异步任务完成
    std::cout << "Async task result: " << value << "\n";
    std::cout << "Main thread is done!\n";
    return 0;
}
```

在上面的例子中，std::async 启动了一个异步任务，该任务执行 task 函数。主线程可以继续执行其他任务，直到需要使用异步任务的结果时，通过调用 result.get() 来获取。注意，get() 调用会阻塞，直到异步任务完成。
