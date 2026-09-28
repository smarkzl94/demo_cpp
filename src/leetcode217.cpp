// LeetCode 217. 存在重复元素
// 数组中有任意重复值返回 true，否则 false
#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // TODO(你来做)：unordered_set 边遍历边登记
        // 提示：auto [it, inserted] = seen.insert(x);
        //      inserted == false 说明 x 已存在 → 返回 true
        //      扫完都没重复 → 返回 false
        std::unordered_set<int> s{nums.begin(), nums.end()};
        return s.size() != nums.size();
    }
};

void test(std::vector<int> nums, bool expected) {
    bool got = Solution().containsDuplicate(nums);
    std::cout << (got == expected ? "PASS" : "FAIL") << " -> [";
    for (size_t i = 0; i < nums.size(); ++i)
        std::cout << nums[i] << (i + 1 < nums.size() ? "," : "");
    std::cout << "] => " << (got ? "true" : "false") << '\n';
}

int main() {
    test({1, 2, 3, 1}, true);
    test({1, 2, 3, 4}, false);
    test({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true);
    test({}, false);          // 空数组边界
    test({42}, false);        // 单元素边界
    return 0;
}
