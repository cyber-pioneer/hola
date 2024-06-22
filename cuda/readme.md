1. 文件类型
.cu文件：CUDA C/C++源代码文件，包含设备（GPU）相关的代码和核函数（kernel）实现，由CUDA编译器（nvcc）编译。

.cpp文件：标准的C++源代码文件，由C++编译器编译。

.h文件：头文件，包含程序所需的数据结构和函数声明。

.cuh文件：包含CUDA函数声明的头文件，通常与.cu文件一起使用。

2. 关键字和修饰符
global：声明一个kernel函数，这个函数将在GPU上执行。

device：声明一个函数或变量，这个函数或变量只能在GPU上访问。

host：声明一个函数或变量，这个函数或变量只能在主机（CPU）上访问。默认情况下，函数和变量都是__host__的。

<<< >>>：执行配置，用于指定kernel函数的执行配置，包括grid和block的大小。

3. 内存管理
cudaMalloc：在GPU的全局内存上分配内存。

cudaMemcpy：在主机和GPU之间复制数据。例如，cudaMemcpy(d_x, h_x, M, cudaMemcpyHostToDevice);表示将M字节的数据从主机复制到设备。

cudaFree：释放GPU上的内存。

4. 线程同步
__syncthreads()：用于同步一个block内的所有线程。确保block内的所有线程都执行到__syncthreads()之前的代码后，才继续执行后面的代码。
5. 共享内存
shared：声明一个变量为共享内存，该变量在block内的所有线程之间是共享的。可以使用静态或动态方式声明共享内存。
6. 示例
一个简单的CUDA kernel函数示例：


```cu
__global__ void add(int n, float *x, float *y) {
    int index = threadIdx.x;
    int stride = blockDim.x;

    for (int i = index; i < n; i += stride) {
        y[i] = x[i] + y[i];
    }
}
```
在这个示例中，add是一个kernel函数，它接受三个参数：一个整数n和两个指向浮点数的指针x和y。函数内部使用线程索引和块维度来计算每个线程应该处理的数组元素，并将x[i]和y[i]相加后存回y[i]。

7. 注意事项
在执行kernel函数后，可能需要调用cudaDeviceReset()来确保所有CUDA操作都已完成。但请注意，cudaDeviceReset()会重置所有CUDA设备，所以在使用多个设备时需要谨慎。

CUDA编程涉及到GPU和CPU之间的协同工作，因此需要注意内存管理和线程同步等问题。
