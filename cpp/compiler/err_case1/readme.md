```
g++ source.cc fn.cc -o main
```

```
/usr/local/bin/ld: /tmp/ccAUdPPt.o: in function `main':
source.cc:(.text+0xa): undefined reference to `fn(int)'
collect2: error: ld returned 1 exit status
```
