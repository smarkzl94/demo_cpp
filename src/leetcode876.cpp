// ============================================================================
// LeetCode 876. 链表的中间结点（Middle of the Linked List）
// https://leetcode.cn/problems/middle-of-the-linked-list/
// ============================================================================
// 题目描述：
//
//   给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//   如果有两个中间结点，则返回第二个中间结点。
//
// ----------------------------------------------------------------------------
// 示例 1：
//   输入：head = [1,2,3,4,5]
//   输出：[3,4,5]
//   解释：链表只有一个中间结点，值为 3。
//
// 示例 2：
//   输入：head = [1,2,3,4,5,6]
//   输出：[4,5,6]
//   解释：该链表有两个中间结点，值分别为 3 和 4，返回第二个结点。
//
// ----------------------------------------------------------------------------
// 提示（数据范围）：
//   链表的结点数范围是 [1, 100]
//   1 <= Node.val <= 100
//
// ----------------------------------------------------------------------------
// 思路提示（快慢指针的第二次登场，几乎白送）：
//
//   还是 slow 走 1 步、fast 走 2 步：
//     当 fast 走到尽头时，slow 正好走到中间。
//     想像操场 100 米：你跑 50 米时，快的人已经跑完 100 米了。
//
//   唯一的坑：偶数个数时要返回"第二个"中间结点。
//     循环条件用 while (fast && fast->next) 自然得到第二个，
//     自己拿 [1,2,3,4,5,6] 推演一遍就明白了。
//
//   边界：题目保证至少 1 个节点，空链表不用考虑（但想了也不亏）。
//
//   复杂度：O(n) 时间，O(1) 空间。
// ============================================================================

#include <iostream>
#include <vector>

// LeetCode 官方单链表定义
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    if (fast == nullptr) {
      return slow;
    } else {
      return slow->next;
    }
  }
};

// ---- 测试辅助：vector 建链表 / 从某节点转 vector ----
ListNode *build(const std::vector<int> &v) {
  ListNode dummy;
  ListNode *tail = &dummy;
  for (int x : v) {
    tail->next = new ListNode(x);
    tail = tail->next;
  }
  return dummy.next;
}

std::vector<int> toVec(ListNode *head) {
  std::vector<int> v;
  for (ListNode *p = head; p; p = p->next)
    v.push_back(p->val);
  return v;
}

void test(std::vector<int> input, std::vector<int> expected) {
  ListNode *head = build(input);
  std::vector<int> got = toVec(Solution().middleNode(head));
  std::cout << (got == expected ? "PASS" : "FAIL") << " -> ";
  for (int x : got)
    std::cout << x << ' ';
  std::cout << '\n';
  while (head) {
    ListNode *nxt = head->next;
    delete head;
    head = nxt;
  }
}

int main() {
  test({1, 2, 3, 4, 5}, {3, 4, 5});     // 示例 1：奇数
  test({1, 2, 3, 4, 5, 6}, {4, 5, 6});  // 示例 2：偶数，取第二个中间
  test({1}, {1});                       // 单节点
  test({1, 2}, {2});                    // 两个节点
  return 0;
}
