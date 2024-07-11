#include <stdio.h>

__global__ void cuda_say_hello() {
  int N =
      gridDim.x * gridDim.y * gridDim.z * blockDim.x * blockDim.y * blockDim.z;
  printf("Hello world, CUDA! current thread%d  all thread %d\n", threadIdx.x,
         N);
}

int main() {
  printf("Hello world, CPU\n");
  cuda_say_hello<<<2, 3>>>();

  cudaError_t cudaerr = cudaDeviceSynchronize();
  if (cudaerr != cudaSuccess)
    printf("kernel launch failed with error \"%s\".\n",
           cudaGetErrorString(cudaerr));
  return 0;
}
