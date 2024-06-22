当使用 nvcc 编译多个文件时，通常这些文件会包含主机代码（在CPU上运行的代码）和设备代码（在GPU上运行的CUDA内核）。以下是一个基本的步骤和示例，说明如何使用 nvcc 编译多个文件。

1. 文件结构
假设您有以下文件：

main.cpp：包含主函数和调用CUDA内核的代码。

cuda_kernels.cu：包含CUDA内核的定义。

utils.h 和 utils.cpp：包含主机代码中使用的辅助函数和类型定义。

2. 编译步骤
编译CUDA文件
首先，您需要编译CUDA文件（.cu）以生成对象文件。使用 -c 选项来告诉 nvcc 只编译而不链接。


nvcc -c cuda_kernels.cu -o cuda_kernels.o
编译主机代码文件
然后，您可以使用标准的C++编译器（如 g++ 或 clang++）来编译主机代码文件。


g++ -c main.cpp utils.cpp -o main.o utils.o
注意：在这个步骤中，您不需要包含CUDA相关的头文件或库，因为主机代码不包含CUDA内核的调用。但是，如果主机代码使用了CUDA运行时API（如 cudaMalloc、cudaMemcpy 等），那么您需要包含CUDA运行时库。

链接对象文件
最后，使用 nvcc 或C++编译器将所有对象文件链接成一个可执行文件。由于您正在链接CUDA代码，因此最好使用 nvcc。


nvcc -o my_program cuda_kernels.o main.o utils.o -lcuda
这里，-lcuda 选项告诉链接器包含CUDA运行时库。如果您的程序还使用了其他库，您需要添加相应的库和链接选项。

3. 简化编译过程
为了简化编译过程，您可以使用Makefile或CMake等构建系统来自动化这些步骤。这些系统允许您定义编译和链接规则，并轻松地在不同的构建配置之间切换。

例如，使用CMake，您可以创建一个 CMakeLists.txt 文件来定义您的项目结构、源文件、编译选项和链接库，然后运行 cmake 和 make 命令来构建您的项目。
