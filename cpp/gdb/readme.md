g++ -g -o my_program my_program.cpp

GDB (GNU Debugger) 是一个功能强大的Unix下的程序调试工具，可以用来调试C、C++、Objective-C、Pascal等语言编写的程序。使用GDB，你可以：

设置断点，在程序执行到特定位置时暂停。
```shell
break function_name       # 在函数入口设置断点
break filename:linenum    # 在指定文件的指定行设置断点
delete breakpoint_number  # 删除指定编号的断点
delete breakpoints        # 删除所有断点
```

执行程序，查看每一步的执行结果。

```shell
continue                  # 继续执行，直到遇到下一个断点或程序结束
next                      # 执行下一行代码（如果是函数调用，则执行完整个函数）
step                      # 执行下一行代码（如果是函数调用，则进入函数）
until location            # 执行直到指定位置（例如某个函数的返回）
finish                    # 执行直到当前函数返回
```


查看和修改变量的值。
```shell
print variable_name       # 打印变量的值
set variable=value        # 修改变量的值
```


查看调用堆栈。
```shell
backtrace                 # 查看当前调用堆栈
info locals               # 查看当前栈帧的局部变量
info args                 # 查看当前函数的参数
```

动态地改变程序的执行。

```shell
info breakpoints          # 查看所有断点的信息
info threads              # 查看所有线程的信息
thread thread_number      # 切换到指定的线程
break ... if condition    # 设置条件断点，只在条件为真时停止
```


在使用GDB时，通常你需要对你的代码和编译过程有一定的了解，特别是如果你想要调试优化过的代码或需要更详细的调试信息时。编译你的程序时，使用-g选项可以包含调试信息，这对于使用GDB非常有帮助。例如：

```
g++ -g -o my_program my_program.cpp
```
否则，GDB将无法正确地调试你的程序。

gdb my_program

### error
```shell
(base) pioneer@pc:~/projects/hola/cpp/lc/listnode$ gdb main
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from main...
(No debugging symbols found in main)
(gdb)
```


### normal1
```shell
(base) pioneer@pc:~/projects/hola/cpp/lc/listnode$ gdb ./main
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./main...
(gdb) b test_listnode.cc:15
Breakpoint 1 at 0x1326: file test_listnode.cc, line 15.
(gdb) run
Starting program: /home/pioneer/projects/hola/cpp/lc/listnode/main
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, construct_ln (data=std::vector of length 5, capacity 5 = {...}) at test_listnode.cc:15
15        ListNode *cur = head;
(gdb) l
10      ListNode *construct_ln(std::vector<int> &data) {
11        if (data.empty()) {
12          return nullptr;
13        }
14        ListNode *head = new ListNode(data[0]);
15        ListNode *cur = head;
16        for (size_t i = 1; i < data.size(); i++) {
17          ListNode *tmp = new ListNode(data[i]);
18          cur->next = tmp;
19          cur = cur->next;
(gdb) p data
$1 = std::vector of length 5, capacity 5 = {1, 2, 3, 4, 5}
(gdb) p head
$2 = (ListNode *) 0x55555556bed0
(gdb) c
Continuing.
1 2 3 4 5
1 2 3 4 5
[Inferior 1 (process 28124) exited normally]
(gdb) c
The program is not being run.
(gdb) q
```
### normal2
```shell
(base) pioneer@pc:~/projects/hola/cpp/lc/listnode$ gdb ./main
GNU gdb (Ubuntu 12.1-0ubuntu1~22.04) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./main...
(gdb) b read_ln
Breakpoint 1 at 0x13bb: file test_listnode.cc, line 25.
(gdb) run
Starting program: /home/pioneer/projects/hola/cpp/lc/listnode/main
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, read_ln (head=0x55555556bed0) at test_listnode.cc:25
25        ListNode *cur = head;
(gdb) l
20        }
21        return head;
22      }
23
24      void read_ln(ListNode *head) {
25        ListNode *cur = head;
26        while (cur) {
27          std::cout << cur->val << " ";
28          cur = cur->next;
29        }
(gdb) bt
#0  read_ln (head=0x55555556bed0) at test_listnode.cc:25
#1  0x00005555555554c9 in main () at test_listnode.cc:36
(gdb) bt
#0  read_ln (head=0x55555556bed0) at test_listnode.cc:25
#1  0x00005555555554c9 in main () at test_listnode.cc:36
(gdb) up
#1  0x00005555555554c9 in main () at test_listnode.cc:36
36        read_ln(head);
(gdb) s
26        while (cur) {
```
