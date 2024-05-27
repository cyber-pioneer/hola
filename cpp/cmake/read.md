## cmake


### 安装
``` shell
wget -q https://cmake.org/files/v3.18/cmake-3.18.0-Linux-x86_64.tar.gz
tar -zxvf cmake-3.18.0-Linux-x86_64.tar.gz
rm cmake-3.18.0-Linux-x86_64.tar.gz
vim ~/.bashrc
PATH=/home/cmake-3.18.0-Linux-x86_64/bin:$PATH
```

### 编写CMakeLists.txt：
在项目的根目录下创建一个名为CMakeLists.txt的文件。这个文件用于定义构建规则，包括项目名称、源文件、依赖的库等。

``` cmake
cmake_minimum_required(VERSION 3.10) # 指定cmake的最低版本要求
project(MyProject) # 定义项目名称
add_executable(my_program main.cpp) # 添加可执行文件，指定源文件为main.cpp
```

### 运行cmake生成构建文件：
打开终端或命令提示符，导航到包含CMakeLists.txt文件的目录，并执行以下命令：

``` shell
cmake . # 生成构建文件
```

这将在当前目录下生成构建文件（如Makefile）。如果需要为生成的文件指定一个单独的构建目录，可以在cmake命令后加上构建目录的路径，例如：

``` shell
cmake -B build . # 生成构建文件到build目录中
```

### 使用生成的构建文件进行构建：
根据生成的构建文件类型，使用相应的命令进行构建。例如，如果生成的是Makefile文件，可以执行以下命令进行构建：

``` shell
make # 构建项目
```

### 运行程序：
构建完成后，可以在构建目录下找到生成的可执行文件，并运行它。例如：
``` shell
./my_program # 运行程序
```
或者
``` shell
my_program.exe # 运行生成的可执行文件（在Windows系统上）
```
