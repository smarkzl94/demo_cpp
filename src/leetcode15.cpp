// ============================================================================
// LeetCode 15. 三数之和（3Sum）
// https://leetcode.cn/problems/3sum/
// ============================================================================
// 题目描述：
//
//   给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]]
//   满足 i != j、i != k 且 j != k ，同时还满足
//   nums[i] + nums[j] + nums[k] == 0 。
//   请你返回所有和为 0 且不重复的三元组。
//
//   注意：答案中不可以包含重复的三元组。
//
// ----------------------------------------------------------------------------
// 示例 1：
//   输入：nums = [-1,0,1,2,-1,-4]
//   输出：[[-1,-1,2],[-1,0,1]]
//   解释：
//   nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0
//   nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0
//   nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0
//   不同的三元组是 [-1,0,1] 和 [-1,-1,2]。
//   注意，输出的顺序和三组元的顺序并不重要。
//
// 示例 2：
//   输入：nums = [0,1,1]
//   输出：[]
//   解释：唯一可能的三元组和不为 0。
//
// 示例 3：
//   输入：nums = [0,0,0]
//   输出：[[0,0,0]]
//   解释：唯一可能的三元组和为 0。
//
// ----------------------------------------------------------------------------
// 提示（数据范围）：
//   3 <= nums.length <= 3000
//   -10^5 <= nums[i] <= 10^5
//
// ----------------------------------------------------------------------------
// 思路提示（Medium 的第一道大关，两步走）：
//
//   第 1 步：排序。O(n log n)，换来的是后续双指针的可能。
//
//   第 2 步：固定一个数 nums[i]，问题降级成"在 i 后面的区间里
//           找两数之和 = -nums[i]"——正是你两数之和学过的，
//           但这次用双指针（一头一尾向中间收），不用 map：
//             和太小 → 左指针右移（变大）
//             和太大 → 右指针左移（变小）
//
//   去重（本题的坑）：
//     - 固定的数：i 往后移时，跳过和 nums[i-1] 相同的
//     - 找到一组答案后：左右指针各自跳过相同的值再继续
//
//   复杂度：排序 O(n log n) + 外层 n × 内层双指针 O(n) = O(n²)
// ============================================================================

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    // TODO(你来做)：排序 + 固定一数 + 双指针 + 去重
    std::vector<std::vector<int>> result;
    if(nums.size() < 3){
        return result;
    }
    std::sort(nums.begin(), nums.end());
    int left, right;
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      left = i + 1;
      right = nums.size() - 1;
      while (left < right) {
        if (nums[i] + nums[left] + nums[right] == 0) {
          result.push_back({nums[i], nums[left], nums[right]});
        //   std::cout << "result: " << nums[i] << ", " << nums[left] << ", "
        //             << nums[right] << std::endl;
          ++left;
          --right;
        } else if (nums[i] + nums[left] + nums[right] < 0) {
          ++left;
        } else {
          --right;
        }
      }
    }
    std::set<std::vector<int>> result_set(result.begin(), result.end());
    return std::vector<std::vector<int>>(result_set.begin(), result_set.end());
  }
};

// ---- 测试辅助：排序后比较（答案顺序不重要）----
void normalize(std::vector<std::vector<int>> &v) {
  for (auto &t : v)
    std::sort(t.begin(), t.end());
  std::sort(v.begin(), v.end());
}

void test(std::vector<int> nums, std::vector<std::vector<int>> expected) {
  auto got = Solution().threeSum(nums);
  normalize(got);
  normalize(expected);
  std::cout << (got == expected ? "PASS" : "FAIL") << " -> size=" << got.size()
            << '\n';
}

int main() {
  test({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}); // 示例 1
  test({0, 1, 1}, {});                                    // 示例 2
  test({0, 0, 0}, {{0, 0, 0}});                           // 示例 3
  test({}, {});                                           // 空数组边界
  test({-2, 0, 0, 2, 2}, {{-2, 0, 2}});                   // 重复值去重
  return 0;
}
