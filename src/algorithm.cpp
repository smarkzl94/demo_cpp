#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ostream>
#include <string>
#include <vector>

void PrintVector(const std::vector<int> &vec) {
  for (const auto &v : vec) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  PrintVector(vec);

  // 线性查找 —— O(n)，不要求有序
  auto it = std::find(vec.begin(), vec.end(), 5);
  if (it != vec.end()) {
    std::cout << "找到了，位置: " << std::distance(vec.begin(), it)
              << std::endl;
  }

  auto it2 = std::find_if(vec.begin(), vec.end(), [](int x) { return x > 5; });
  if (it2 != vec.end()) {
    std::cout << "找到了，位置: " << std::distance(vec.begin(), it2)
              << std::endl;
  }

  std::cout << "--------------------------------" << std::endl;
  std::cout << "二分查找：" << std::binary_search(vec.begin(), vec.end(), 8)
            << std::endl;

  // lower_bound / upper_bound —— 同样要求有序

  auto lb = std::lower_bound(vec.begin(), vec.end(), 5);
  auto rb = std::upper_bound(vec.begin(), vec.end(), 5);
  std::cout << "lower_bound: " << std::distance(vec.begin(), lb)
            << "\tupper_bound: " << std::distance(vec.begin(), rb) << std::endl;

  // 计数与判断
  std::cout << "计数与判断：" << std::endl;
  std::cout << "count:\t" << std::count(vec.begin(), vec.end(), 5) << std::endl;
  std::cout << "count_if:\t"
            << std::count_if(vec.begin(), vec.end(),
                             [](int x) { return x % 2 == 0; })
            << std::endl;

  std::cout << "all_of:\t"
            << std::all_of(vec.begin(), vec.end(), [](int x) { return x > 0; })
            << std::endl;
  std::cout << "any_of:\t"
            << std::any_of(vec.begin(), vec.end(), [](int x) { return x < 0; })
            << std::endl;
  std::cout << "none_of:\t"
            << std::none_of(vec.begin(), vec.end(), [](int x) { return x < 0; })
            << std::endl;

  std::cout << "--------------------------------" << std::endl;
  std::vector<int> vec2(15);
  vec2.reserve(15);
  PrintVector(vec2);
  std::copy(vec.begin(), vec.end(), vec2.begin());
  PrintVector(vec2);

  std::cout << "--------------------------------" << std::endl;
  std::vector<int> vec3(15);
  vec3.reserve(15);
  std::copy_if(vec.begin(), vec.end(), vec3.begin(),
               [](const int &x) { return x % 2 == 0; });
  PrintVector(vec3);

  std::cout << "--------------------------------" << std::endl;
  std::vector<int> vec4(10);
  // transform —— 对元素逐个变换，结果写入另一区间
  std::transform(vec.begin(), vec.end(), vec4.begin(),
                 [](int x) { return x * 2; }); // 每个元素翻倍
  PrintVector(vec4);

  std::cout << "--------------------------------" << std::endl;
  std::vector<int> vec5(10);
  // 二元 transform —— 两个输入容器对应元素做运算
  std::transform(vec.begin(), vec.end(), vec4.begin(), vec5.begin(),
                 [](int x, int y) { return x + y; }); // 对应位置相加
  PrintVector(vec5);

  std::cout << "替换与填充" << std::endl;
  std::replace(vec.begin(), vec.end(), 4, 5);
  PrintVector(vec);

  std::replace_if(vec.begin(), vec.end(), [](int x) { return x < 3; }, 4);
  PrintVector(vec);

  std::fill(vec.begin(), vec.end(), 8);
  PrintVector(vec);

  std::generate(vec.begin(), vec.end(), []() { return rand() % 100; });
  PrintVector(vec);

  vec.clear();
  vec.resize(10);
  for (int i = 0; i < 10; ++i) {
    vec[i] = i;
  }
  PrintVector(vec);
  (void)std::remove(vec.begin(), vec.end(), 8); // 仅演示：std::remove 只移动元素，不缩减容器
  PrintVector(vec);
  vec.erase(std::remove(vec.begin(), vec.end(), 9), // 返回"新的逻辑末尾"迭代器
            vec.end()                               // 物理末尾
  );
  PrintVector(vec);

  // 条件删除
  vec.erase(
      std::remove_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; }),
      vec.end());
  PrintVector(vec);

  std::cout << "排序算法" << std::endl;
  std::vector<int> vec6 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  std::sort(vec6.begin(), vec6.end());
  PrintVector(vec6);
  // 快排变种，O(n log n)，不稳定

  std::sort(vec6.begin(), vec6.end(), // 自定义比较（降序）
            [](int a, int b) { return a > b; });
  PrintVector(vec6);

  std::stable_sort(vec6.begin(), vec6.end(),
                   [](int a, int b) { return a > b; });
  PrintVector(vec6); // 稳定排序，保持相等元素原有顺序

  std::cout << "partial_sort" << std::endl;
  std::partial_sort(vec6.begin(), vec6.begin() + 3, vec6.end());
  // 只把前 3 个最小的排到前面，O(n log k)，k=3
  PrintVector(vec6);

  std::cout << "nth_element" << std::endl;
  auto k = 5;
  std::nth_element(vec6.begin(), vec6.begin() + k, vec6.end());
  // 把第 k 小的元素放到正确位置，左边的都小于它，右边都大于它，O(n)
  PrintVector(vec6);

  std::cout << "数值算法 累加" << std::endl;
  auto sum = std::accumulate(vec6.begin(), vec6.end(), 0);
  std::cout << "sum: " << sum << std::endl;

  std::cout << "数值算法 累乘" << std::endl;
  auto product = std::accumulate(vec6.begin(), vec6.end(), 1LL,
                                 std::multiplies<long long>());
  std::cout << "product: " << product << std::endl;

  std::cout << "数值算法 Dot" << std::endl;
  int dot = std::inner_product(vec6.begin(), vec6.end(), vec.begin(), 0);
  std::cout << "dot: " << dot << std::endl;

  std::cout << "数值算法 前缀和" << std::endl;
  std::vector<int> prefix(vec6.size());
  std::partial_sum(vec6.begin(), vec6.end(), prefix.begin());
  PrintVector(prefix);

  std::cout << "数值算法 相邻差分" << std::endl;
  std::vector<int> diff(vec6.size());
  std::adjacent_difference(vec6.begin(), vec6.end(), diff.begin());
  PrintVector(diff);

  std::vector<int> veca = {1, 3, 5, 7};
  std::vector<int> vecb = {2, 3, 5, 8};
  std::vector<int> result;
  std::cout << "集合算法 并集" << std::endl;
  result.reserve(veca.size() + vecb.size());
  std::set_union(veca.begin(), veca.end(), vecb.begin(), vecb.end(),
                 std::back_inserter(result));
  PrintVector(result);

  result.clear();
  std::cout << "集合算法 交集" << std::endl;
  //   result.reserve(veca.size() + vecb.size());
  std::set_intersection(veca.begin(), veca.end(), vecb.begin(), vecb.end(),
                        std::back_inserter(result));
  PrintVector(result);

  result.clear();
  std::cout << "集合算法 差集" << std::endl;
  //   result.reserve(veca.size() + vecb.size());
  std::set_difference(veca.begin(), veca.end(), vecb.begin(), vecb.end(),
                      std::back_inserter(result));
  PrintVector(result);

  result.clear();
  std::cout << "集合算法 对称差集" << std::endl;
  //   result.reserve(veca.size() + vecb.size());
  std::set_symmetric_difference(veca.begin(), veca.end(), vecb.begin(),
                                vecb.end(), std::back_inserter(result));
  PrintVector(result);

  result.clear();
  std::cout << "集合算法 判断是否包含" << std::endl;
  //   result.reserve(veca.size() + vecb.size());
  bool contains =
      std::includes(veca.begin(), veca.end(), vecb.begin(), vecb.end());
  std::cout << "contains:" << contains << std::endl;

  //   练习1：Top K
  std::cout << "练习1：Top K" << std::endl;
  std::vector<int> vecc = {1, 3, 5, 7, 2, 4, 6, 8};
  auto kk = 3;

  std::sort(vecc.begin(), vecc.end(), [](int a, int b) { return a>b;});
  PrintVector(vecc);

  vecc = {1, 3, 5, 7, 2, 4, 6, 8};
  std::partial_sort(vecc.begin(), vecc.begin() + kk, vecc.end(),[](int a, int b) { return a>b;});
  PrintVector(vecc);

  vecc = {1, 3, 5, 7, 2, 4, 6, 8};
  std::nth_element(vecc.begin(), vecc.begin() + kk, vecc.end(),[](int a, int b) { return a>b;});
  PrintVector(vecc);

  // 练习2：学生成绩处理
  std::cout << "练习2：学生成绩处理" << std::endl;
  struct Student {
    std::string name;
    int score;
  };
  std::vector<Student> students = {
      {"Alice", 85}, {"Bob", 92},   {"Charlie", 58},
      {"David", 76}, {"Eve", 95},  {"Frank", 45},
      {"Grace", 88}, {"Henry", 61}, {"Ivy", 73},
  };

  // 1. 按成绩降序排序
  // TODO: 使用 std::sort + 自定义比较器
  std::sort(
      students.begin(), students.end(),
      [](const Student &a, const Student &b) { return a.score > b.score; });
  for (const auto &student : students) {
    std::cout << student.name << " " << student.score << std::endl;
  }
  // 2. 找出第一个不及格的学生（score < 60）
  // TODO: 使用 std::find_if
  auto itt =
      std::find_if(students.begin(), students.end(),
                   [](const Student &student) { return student.score < 60; });
  if (itt != students.end()) {
    std::cout << "不及格的学生：" << itt->name << std::endl;
  }

  // 3. 统计 90 分以上的人数
  // TODO: 使用 std::count_if
  auto count = std::count_if(students.begin(), students.end(), [](const Student &student) { return student.score > 90;});
  std::cout << "90 分以上的人数：" << count << std::endl;

  // 4. 计算平均分
  // TODO: 使用 std::accumulate
  auto average = std::accumulate(students.begin(), students.end(), 0,
                                [](int sum, const Student &s) { return sum + s.score; }) /
                 students.size();
  return 0;
}