// LeetCode 20. 有效的括号
// 只含 ()[]{} 的字符串，判断是否完全匹配：
//   "()[]{}" true  "(]" false  "([)]" false  "{[]}" true  "" true
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    // TODO(你来做)：stack 解法
    // 思路方向：遇左进栈，遇右看栈顶是否配对，不配对/栈空 → false
    //          全部扫完后栈必须为空
    // 提示：std::stack<char> st;  st.push(c);  st.top();  st.pop(); st.empty();
    std::stack<char> st;
    for (auto c : s) {
      if (c == '(' || c == '[' || c == '{') {
        st.push(c);
        continue;
      }
      if (st.empty()) {
        return false;
      }
      if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') ||
          (c == '}' && st.top() == '{')) {
        st.pop();
        continue;
      }
      return false;
    }
    return st.empty();
  }
};

void test(const std::string &s, bool expected) {
  bool got = Solution().isValid(s);
  std::cout << (got == expected ? "PASS" : "FAIL") << " -> \"" << s << "\" => "
            << (got ? "true" : "false") << '\n';
}

int main() {
  test("()", true);
  test("()[]{}", true);
  test("(]", false);
  test("([)]", false);
  test("{[]}", true);
  test("", true);          // 空串边界
  test("((", false);       // 左括号富余 → 最后栈不为空
  test("))", false);       // 右括号先来 → 栈空时遇右
  return 0;
}
