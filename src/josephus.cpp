#include <iostream>
#include <list>
#include <vector>


// 练习 2：约瑟夫环（经典）
// 题目：n 个人围成一圈（编号 1~n），从第 1 个人开始报数，
// 数到 m 的人出列，下一个人从 1 重新报数，直到所有人出列。
// 返回出列顺序。

// TODO: 实现约瑟夫环求解函数。
// 参数：n 为人数，m 为报数间隔。
// 返回：一个 vector<int>，按出列顺序保存每个人的编号。
std::vector<int> josephus(int n, int m) {

  // std::vector<int> result;
  // std::vector<int> alive(n);
  // for (int i = 0; i < n; ++i) {
  //   alive[i] = i + 1;
  // }
  // auto current = 0;
  // while(result.size()<n) {
  //   auto index = (current+m-1)%alive.size();
  //   result.push_back(alive[index]);
  //   current = index;
  //   alive.erase(alive.begin()+index);
  // }
  // 框架提示：可以用环形链表、队列或数学递推三种思路实现。
  // 思路 A（模拟）：用 std::vector<int> 存活着的人，
  //   每次计算下一个出列位置 index = (current + m - 1) % alive.size()，
  //   将 alive[index] 加入 result，并从 alive 中 erase。

  std::list<int> alive;
  for (int i = 0; i < n; ++i) {
    alive.push_back(i + 1);
  }
  std::vector<int> result;
  auto it = alive.begin();
  while (alive.size()) {
    for (int i = 1; i < m; ++i) {
      ++it;
      if (it == alive.end()) {
        it = alive.begin(); // 循环回到开头
      }
    }
    result.emplace_back(*it);
    it = alive.erase(it);
    if (it == alive.end()) {
      it = alive.begin(); // 循环回到开头
    }
  }

  // 思路 B（队列）：用 std::queue<int>，循环 m-1 次把队首移到队尾，
  //   第 m 个人出队并加入 result。
  // 思路 C（数学递推）：f(1)=0, f(i)=(f(i-1)+m)%i，最后结果 +1。
  //   适用于只求“最后幸存者”编号，若需要完整顺序需额外记录。
  //
  // 请任选一种思路，在下面填写实现：

  return result;
}

// 辅助函数：打印 vector<int>
void printVector(const std::vector<int> &v) {
  for (int x : v) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

int main() {
  // 测试用例 1：n=7, m=3，经典约瑟夫环
  // 出列顺序应为：3 6 2 7 5 1 4
  std::vector<int> case1 = josephus(7, 3);
  std::cout << "n=7, m=3: ";
  printVector(case1);
  std::cout << "expected: 3 6 2 7 5 1 4\n\n";

  // 测试用例 2：n=5, m=1，每轮淘汰当前报数者
  // 出列顺序应为：1 2 3 4 5
  std::vector<int> case2 = josephus(5, 1);
  std::cout << "n=5, m=1: ";
  printVector(case2);
  std::cout << "expected: 1 2 3 4 5\n\n";

  // 测试用例 3：n=6, m=5
  // 出列顺序应为：5 4 3 6 2 1
  std::vector<int> case3 = josephus(6, 5);
  std::cout << "n=6, m=5: ";
  printVector(case3);
  std::cout << "expected: 5 4 3 6 2 1\n\n";

  return 0;
}
