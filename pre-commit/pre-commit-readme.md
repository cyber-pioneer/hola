official url https://pre-commit.com/#hooks-files
other reference
https://segmentfault.com/a/1190000040288064


.pre-commit-config.yaml
本项目使用
.pre-commit-hooks.yaml
给其他项目的pre-commit 使用
https://blog.csdn.net/DoneSpeak/article/details/118469221


##原理
pre-commit 执行 hola/.git/hooks/pre-commit
默认调用仓库根目录下的.pre-commit-config.yaml

.pre-commit-config.yaml里有自定义的钩子，包括本地和远程的钩子
```yaml
# For C++ files
-   repo: local
    hooks:
    -   id: clang-format
        name: clang-format
        description: Format files with ClangFormat.
        entry: bash ./codestyle/clang_format.hook -i
        language: system
        files: \.(c|cc|cxx|cpp|cu|h|hpp|hxx|xpu|kps)$

# For Python files
-   repo: https://github.com/psf/black.git
    rev: 23.3.0
    hooks:
    -   id: black
        files: (.*\.(py|pyi|bzl)|BUILD|.*\.BUILD|WORKSPACE)$
-   repo: https://github.com/PyCQA/flake8
    rev: 5.0.4
    hooks:
    -   id: flake8
        args: ["--config=.flake8"]
```
