cmake_minimum_required(VERSION 3.10) # 指定cmake的最低版本要求
project(MyProject) # 定义项目名称

# add_library(MyLibrary STATIC fn2.cc) # 创建静态库
# 或者
# add_library(MyLibrary SHARED fn2.cc) # 创建动态库

# add_executable(demo main.cc fn.cc) # 添加可执行文件，可以是一个，也可以是多个，指定源文件为main.cpp

# target_link_libraries(demo MyLibrary) # 链接到之前定义的库


# or

# 创建静态库和动态库都可以
# add_library(MyLibrary STATIC fn2.cc) # 创建静态库
# 或者
add_library(MyLibrary SHARED fn.cc fn2.cc) # 创建动态库

add_executable(demo main.cc) # 添加可执行文件，可以是一个，也可以是多个，指定源文件为main.cpp

target_link_libraries(demo MyLibrary) # 链接到之前定义的库
