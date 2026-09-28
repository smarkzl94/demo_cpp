#include <iostream>
#include <utility>

template <typename F, typename... Args>
decltype(auto) invoke(F &&f, Args &&...args) {
  // TODO: 完美转发 f 和全部参数，再调用
  return f(std::forward<Args>(args)...);
}

int add(int a, int b) { return a + b; }

int main() {
  std::cout << invoke(add, 1, 2) << "\n"; // 期望 3

  int x = 10;
  auto inc = [](int &n) { ++n; };
  invoke(inc, x);
  std::cout << x << "\n"; // 期望 11（需要把 x 转成左值引用）

  // 填完完美转发后再打开：临时量必须绑到右值引用，不转发会编不过
  auto take = [](int &&n) { return n; };
  std::cout << invoke(take, 5) << "\n";
  return 0;
}
