// LeetCode 1. 两数之和
// 返回和为 target 的两个下标；保证有唯一解，同元素不能用两次
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // TODO(你来做)：unordered_map 一遍扫描
        // 方向：每到一个数 x，先查 map 里有没有 target-x
        //       有 → 返回两个下标；没有 → 登记 {x: 下标} 继续
        std::unordered_map<int, int>map;
        for(int i = 0; i < nums.size(); ++i){
            if(map.find(target - nums[i]) != map.end()){
                std::vector<int> result = {map[target - nums[i]], i};
                return result;
            }
            map[nums[i]] = i;
        }   
        return {};
}
};

void test(std::vector<int> nums, int target, std::vector<int> expected) {
    auto got = Solution().twoSum(nums, target);
    // 答案下标顺序可能不同，统一排序后比较
    std::sort(got.begin(), got.end());
    std::sort(expected.begin(), expected.end());
    std::cout << (got == expected ? "PASS" : "FAIL") << " -> [";
    for (size_t i = 0; i < nums.size(); ++i)
        std::cout << nums[i] << (i + 1 < nums.size() ? "," : "");
    std::cout << "] target=" << target << '\n';
}

int main() {
    test({2, 7, 11, 15}, 9, {0, 1});
    test({3, 2, 4}, 6, {1, 2});
    test({3, 3}, 6, {0, 1});          // 同值不同位
    test({-1, -2, -3, -4, -5}, -8, {2, 4});  // 负数
    return 0;
}
