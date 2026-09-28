# C++ 基础运行框架

这是一个最小可运行的 C++ 示例工程，包含：

- `CMakeLists.txt`：构建配置
- `src/main.cpp`：Demo 程序入口

## 目录结构

```text
cursor_cpp/
├─ CMakeLists.txt
├─ README.md
└─ src/
   └─ main.cpp
```

## 编译条件

### 1) 使用 CMake（推荐）

需要安装：

- CMake >= 3.16
- 支持 C++17 的编译器（任一）
  - GCC >= 8
  - Clang >= 7
  - MSVC（Visual Studio 2019 16.7+）

构建命令：

```bash
cmake -S . -B build
cmake --build build
```

运行（Windows）：

```bash
.\build\cpp_demo.exe
```

### 2) 直接使用 g++

需要安装：

- MinGW-w64（包含 g++，建议 GCC 8+）

编译命令：

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o demo src/main.cpp
```

运行（Windows）：

```bash
.\demo.exe
```

## 预期输出

```text
Hello, C++ demo!
3 + 5 = 8
Welcome, Cursor!
```
