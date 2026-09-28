// LeetCode 344. 反转字符串
// 原地修改输入数组，O(1) 额外空间，不能用 std::reverse
#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        // TODO(你来做)：原地反转 s
        // 提示：两个指针，一个从头、一个从尾，往中间边走边交换
        int left = 0;
        int right = s.size()-1;
        while (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

// 本地测试：跑两组用例，对了会输出 PASS
void test(std::vector<char> s, const std::vector<char>& expected) {
    Solution().reverseString(s);
    if (s == expected) {
        std::cout << "PASS";
    } else {
        std::cout << "FAIL";
    }
    std::cout << " -> ";
    for (char c : s) std::cout << c;
    std::cout << '\n';
}

int main() {
    test({'h','e','l','l','o'}, {'o','l','l','e','h'});        // 奇数个
    test({'H','a','n','n','a','h'}, {'h','a','n','n','a','H'}); // 偶数个
    test({'a'}, {'a'});                                          // 单字符边界
    return 0;
}
