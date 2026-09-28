#include <iostream>
#include <vector>

int removeEvensAndSum(std::vector<int> &nums) {
  auto sum = 0;
  for (std::vector<int>::iterator it = nums.begin(); it != nums.end();) {
    if (*it % 2 == 0) {
      nums.erase(it);
    } else {
      sum += *it;
      ++it;
    }
  }
  return sum;
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};
  int sum = removeEvensAndSum(v);

  std::cout << "sum=" << sum << " (expected 9)\n";
  std::cout << "v=";
  for (int n : v) {
    std::cout << n << " ";
  }
  std::cout << "(expected 1 3 5)\n";
  return 0;
}
