// LeetCode 19. 删除链表的倒数第 N 个结点
// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
//
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//
// 示例 1：
//   输入：head = [1,2,3,4,5], n = 2
//   输出：[1,2,3,5]
//   （删除倒数第 2 个，即 4）
//
// 示例 2：
//   输入：head = [1], n = 1
//   输出：[]
//
// 示例 3：
//   输入：head = [1,2], n = 1
//   输出：[1]
//
// 提示：
//   - 链表中结点的数目为 sz，1 <= sz <= 30
//   - 0 <= Node.val <= 100
//   - 1 <= n <= sz（保证合法，不用考虑 n 超界）
//
// 进阶（本题要求的）：你能尝试使用一趟扫描实现吗？
//
// 思路提示（先别看）：
//   双指针 fast / slow，中间隔开 n 个节点。
//   1. fast 先走 n 步
//   2. fast 和 slow 一起走，每次各一步，直到 fast 走到 nullptr
//      ——此时 slow 正好停在"倒数第 n 个的前一个节点"
//   3. 删除 slow->next
//   为什么要 dummy？考虑删的是头节点的情况（如 head=[1], n=1），
//   有了 dummy，"前一个节点"永远存在，不用写特殊分支。
//   ⚠️ 注意先走 n 步还是 n+1 步，想清楚 slow 最终要停在哪。

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // 你的代码
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *fast = dummy;
    ListNode *slow = dummy;
    for (int i = 0; i < n+1; ++i) {
      fast = fast->next;
    }
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;

    return dummy->next;
  }
};

// ===== 测试工具（不用改）=====
ListNode *makeList(const std::initializer_list<int> &vals) {
  ListNode *dummy = new ListNode();
  ListNode *tail = dummy;
  for (int v : vals) {
    tail->next = new ListNode(v);
    tail = tail->next;
  }
  return dummy->next;
}

void printList(ListNode *head) {
  std::cout << "[";
  while (head) {
    std::cout << head->val;
    if (head->next)
      std::cout << ",";
    head = head->next;
  }
  std::cout << "]" << std::endl;
}

int main() {
  Solution s;

    printList(s.removeNthFromEnd(makeList({1, 2, 3, 4, 5}), 2));  // 期望
  // [1,2,3,5]
  printList(s.removeNthFromEnd(makeList({1}), 1));    // 期望 []
  printList(s.removeNthFromEnd(makeList({1, 2}), 1)); // 期望 [1]
  printList(s.removeNthFromEnd(makeList({1, 2}),
                               2)); // 期望 [2]（删头节点，dummy 的用武之地）

  return 0;
}
