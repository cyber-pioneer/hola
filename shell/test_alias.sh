function run_cpp_case() {
    # $1 means 1st arg of function run_cpp_case
    echo "*** g++ $1 -o main.o && ./main.o ***"
    g++ $1 -o main.o && ./main.o
}

# $1 means 1st arg of shell file, when run shell, open below
# run_cpp_case $1

# $1 means 1st arg of command run
alias run='run_cpp_case $1'
