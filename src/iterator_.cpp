#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <vector>

void PrintVector(const std::vector<int> &vec) {
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PrintList(const std::list<int> &lst) {
  for (auto it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::cout << "反向遍历" << std::endl;
  std::vector<int> v = {1, 2, 3, 4, 5};
  // 反向遍历
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << " "; // 5 4 3 2 1
  }
  std::cout << std::endl;
  // 注意：reverse_iterator 的 base() 指向不同位置
  auto rbegin = v.rbegin();  // 指向 5
  auto rend = rbegin.base(); // 指向 5 之后（即 4 之前）
  std::cout << "rbegin:" << *rbegin << std::endl;
  std::cout << "rend:" << *rend << std::endl;

  std::cout << "插入迭代器" << std::endl;
  std::vector<int> insert_vec = {1, 2, 3};
  std::vector<int> insert_src = {4, 5, 6};
  std::cout << "尾部插入(调用push_back)" << std::endl;
  std::copy(insert_src.begin(), insert_src.end(),
            std::back_inserter(insert_vec));
  PrintVector(insert_vec);

  std::list<int> lst = {3, 4, 5};
  std::cout << "头部插入(调用push_front)" << std::endl;
  std::copy(insert_src.begin(), insert_src.end(), std::front_inserter(lst));
  PrintList(lst);

  std::cout << "插入迭代器插入到指定位置" << std::endl;
  auto pos = insert_vec.begin() + 2;
  std::copy(insert_src.begin(), insert_src.end(),
            std::inserter(insert_vec, pos));
  PrintVector(insert_vec);

  std::cout << "流迭代器" << std::endl;
  std::istringstream iss("10 20 30 40 50");
  // 用两个 istream_iterator 构造 vector
  std::vector<int> nums{std::istream_iterator<int>(iss),
                        std::istream_iterator<int>()};
  // nums = {10, 20, 30, 40, 50}

  std::copy(nums.begin(), nums.end(),
            std::ostream_iterator<int>(std::cout, " "));

  std::ofstream file("data.csv");
  std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(file, ","));
  
  
  
  // 从 cin 读入所有整数，排序后输出
  // std::istream_iterator<int> in(std::cin), eof;
  // std::vector<int> nums2(in, eof);

  // std::sort(nums2.begin(), nums2.end());
  // std::copy(nums2.begin(), nums2.end(),
  //     std::ostream_iterator<int>(std::cout, "\n"));
  

  std::cout<<"迭代器辅助函数"<<std::endl;
  std::vector<int> vec = {1, 2, 3, 4, 5};
  auto itt = vec.begin();
  std::cout<<"*itt:"<<*itt<<std::endl;
  std::advance(itt, 2);
  std::cout<<"*After Advance, itt:"<<*itt<<std::endl;

  auto dis =  distance(itt, vec.end());
    std::cout<<"Distance:"<<dis<<std::endl;

  std::cout<< "Next:"<<*std::next(itt)<< "\tPrev:"<<*std::prev(itt)<<std::endl;

  std::vector<int> vec2 = {1, 2, 3, 4, 5};
  std::cout<<"Begin:"<<*std::begin(vec2)<< "\t End:"<< *std::end(vec2)<<std::endl;
  return 0;
}