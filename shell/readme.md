```shell
function run_cpp_case() {

    echo "*** g++ $1 -o main.o && ./main.o ***"
    g++ $1 -o main.o && ./main.o
}

# run_cpp_case $1
alias run='run_cpp_case $1'
```
### usage1
create test_alias.sh
bash test_alias.sh test.cc

### usage2
copy code into ~/.bashrc
run test.cc
