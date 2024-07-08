#include <iostream>
#include <random>
#include <thread>

thread_local int tls_counter = 0; // 每个线程都有一个tls_counter的副本

void increment_counter() {
  // 创建一个默认的随机数生成器
  std::random_device rd;
  std::mt19937 gen(rd()); // 使用随机数生成器来初始化一个Mersenne Twister生成器

  // 定义一个分布
  std::uniform_int_distribution<> dis(1,
                                      100); // 定义一个范围在[1, 100]的均匀分布

  // 生成一个随机数
  int random_num = dis(gen);
  tls_counter += random_num; // 修改的是当前线程的tls_counter副本
  std::cout << "Thread " << std::this_thread::get_id()
            << " counter: " << tls_counter << std::endl;
}

int main() {
  std::thread t1(increment_counter);
  std::thread t2(increment_counter);

  increment_counter(); // 主线程也调用increment_counter

  t1.join();
  t2.join();

  // 预期输出类似（但ID不同）：
  // Thread ... counter: 1
  // Thread ... counter: 1
  // Thread ... counter: 1
  // 每个线程输出的都是它自己的tls_counter的值，均为1
  // 线程打印的顺序是随机的
  std::cout << "final tls_counter **** " << tls_counter << std::endl;

  return 0;
}
// : undefined reference to `pthread_create'
// 程序使用了C++标准库中的<thread>头文件，该头文件依赖于pthreads库来在底层实现线程功能，但是你在编译或链接程序时没有告诉编译器链接到pthreads库。
// 要解决这个问题，你需要确保在编译和链接你的程序时包含了pthreads库。这通常可以通过在编译命令中添加-lpthread
// g++ test_thread_local.cc -lpthread -o main.o && ./main.o

// 注意不同线程的操作应该是一致的，否则结果将被最后一个执行的线程覆盖，结果将不可预期
