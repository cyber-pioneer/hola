# hola

## prepare for development
```shell
pip install pre-commit==2.17.0
pre-commit install
# pre-commit installed at .git/hooks/pre-commit
```
注意：.git/hooks/pre-commit 是一个文件，不是目录。可以自定义内容，但是不建议，因为这个文件的改动只在本地生效，不会提交到远程仓库。原理解释可以参考pre-commit目录的文档。

接下來，每次执行git commit时，pre-commit都会检查代码格式，并自动修复。

如果不想自动修复，可以执行：
```shell
pre-commit uninstall
```
