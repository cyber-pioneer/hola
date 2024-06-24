CMake中静态库和动态库的区别可以归纳为以下几点：

## 链接方式：

静态库：在编译链接时，静态库中的代码会被直接链接（或说“复制”）到最终的可执行文件中。这意味着，可执行文件包含了静态库中的所有必要代码。
动态库：在编译链接时，动态库的代码并不会被复制到可执行文件中。相反，当程序运行时，它会从系统中动态加载所需的库文件。

## 文件大小：

静态库：由于静态库的代码被直接包含在可执行文件中，因此这通常会导致可执行文件的大小比链接到动态库时的版本要大。
动态库：多个程序可以共享同一个动态库，因此不会增加每个可执行文件的大小。

## 依赖性和可移植性：

静态库：一旦程序链接了静态库，它就不再依赖于外部的库文件，因此更易于移植到没有相应库的系统上运行。
动态库：程序在运行时需要系统中存在相应的动态库文件，如果动态库文件缺失或版本不匹配，程序可能无法正常运行。

## 更新和维护：

静态库：如果静态库需要更新，那么所有链接到这个库的可执行文件都需要重新编译和链接。
动态库：当动态库更新时，通常不需要重新编译链接可执行文件，只要确保新的动态库与原有程序兼容即可。

## 文件后缀：

静态库：在Windows上通常为.lib，在Unix-like系统（如Linux和macOS）上通常为.a。
动态库：在Windows上通常为.dll，在Unix-like系统上可能为.so（Linux）或.dylib（macOS）。

总的来说，静态库和动态库各有优缺点，选择使用哪种库取决于具体的项目需求、目标平台的特性以及对可执行文件大小、依赖性和更新频率的考虑。CMake作为一个跨平台的构建工具，能够灵活地处理这两种类型的库，使得开发者可以根据项目需求轻松地构建和链接静态库或动态库。

## 常见使用

运行case1
```
mkdir build && cd build
cmake ../
make
./demo
```

case1
```
cmake_minimum_required(VERSION 3.10) # 指定cmake的最低版本要求
project(MyProject) # 定义项目名称

# 创建静态库和动态库都可以
# add_library(MyLibrary STATIC fn2.cc) # 创建静态库
# 或者
add_library(MyLibrary SHARED fn.cc fn2.cc) # 创建动态库

add_executable(demo main.cc) # 添加可执行文件，可以是一个，也可以是多个，指定源文件为main.cpp

target_link_libraries(demo MyLibrary) # 链接到之前定义的库
```

case2
```
add_library(gtest STATIC IMPORTED GLOBAL)
set_property(TARGET gtest PROPERTY IMPORTED_LOCATION ${GTEST_LIBRARIES})
add_dependencies(gtest extern_gtest)
```
case2实现了几个关键步骤来集成一个预先构建的静态库（在这个例子中是gtest）到你的项目中。下面是对这几行代码的详细解释：


add_library(gtest STATIC IMPORTED GLOBAL)
这行代码声明了一个名为gtest的静态库目标，并将其标记为IMPORTED和GLOBAL。IMPORTED表示这个库不是在当前CMake项目中构建的，而是已经存在的。GLOBAL表示这个库目标在整个项目中都是可见的。

set_target_property(TARGET gtest PROPERTY IMPORTED_LOCATION ${GTEST_LIBRARIES})
这行代码设置了gtest目标的IMPORTED_LOCATION属性。这个属性告诉CMake静态库文件的确切位置。${GTEST_LIBRARIES}是一个变量，它应该在之前被定义并指向实际的库文件路径。注意，这里使用的是set_target_property而不是set_target_properties（没有末尾的's'），尽管两者在功能上是相似的，但set_target_property是用于设置单个属性的。


add_dependencies(gtest extern_gtest)
这行代码添加了gtest库对extern_gtest目标的依赖。这意味着在构建gtest之前，CMake会先构建extern_gtest。这通常用于确保任何必要的准备工作（如下载、解压或构建外部库）都在尝试使用库之前完成。

需要注意的是，extern_gtest可能是一个自定义目标，用于执行一些准备工作，比如下载和构建gtest库，或者它可能是另一个CMake目标，负责实际的构建工作。

综上所述，这段代码的目的是将预先构建的gtest静态库集成到CMake项目中，并确保在构建任何依赖于gtest的目标之前，先执行必要的准备工作（通过extern_gtest目标）。

另外，需要指出的是，如果${GTEST_LIBRARIES}包含多个库文件路径，你可能需要使用IMPORTED_LINK_INTERFACE_LIBRARIES或其他适当的方式来指定它们，因为IMPORTED_LOCATION通常用于单个库文件。如果你的gtest实际上是由多个库组成的，那么你需要相应地调整你的CMake代码。

此外，如果extern_gtest是负责下载和构建gtest的自定义目标，可能还需要确保它正确地设置了gtest库文件的路径，以便${GTEST_LIBRARIES}变量能够指向正确的位置。
