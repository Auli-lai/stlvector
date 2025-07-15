# myvector

自定义 C++ 动态数组模板类，功能类似于 `std::vector`，用于学习和演示 C++ 容器的底层实现。

## 特性

- 支持动态扩容
- 支持拷贝构造、赋值运算符
- 提供常用接口：`push_back`、`pop_back`、`operator[]`、`at`、`empty`、`get_size`、`get_cap`、`reserve`
- 兼容 C++14

## 文件结构

- `vector.h`：`myvector` 模板类的实现
- `VECTOR.cpp`：测试代码（示例用法）
- `text.h`：其他头文件（如有）

## 编译方法

以 Visual Studio 2022 为例：

1. 打开解决方案或项目文件（`.sln` 或 `.vcxproj`）
2. 选择合适的配置（Debug/Release）和平台（x86/x64）
3. 编译并运行

或使用命令行（假设已安装 g++）：

