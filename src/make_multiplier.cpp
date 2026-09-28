#include <iostream>

auto make_multiplier(int factor) {
  // TODO: 返回一个 Lambda，将输入乘以 factor
  return [factor](int n) { return n * factor; };
}

int main() {
  auto times3 = make_multiplier(3);
  std::cout << times3(10) << "\n"; // 期望 30

  auto times5 = make_multiplier(5);
  std::cout << times5(4) << "\n"; // 期望 20
  return 0;
}
