// LeetCode 21. 合并两个有序链表
// https://leetcode.cn/problems/merge-two-sorted-lists/
//
// 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
// 示例 1：
//   输入：l1 = [1,2,4], l2 = [1,3,4]
//   输出：[1,1,2,3,4,4]
//
// 示例 2：
//   输入：l1 = [], l2 = []
//   输出：[]
//
// 示例 3：
//   输入：l1 = [], l2 = [0]
//   输出：[0]
//
// 提示：
//   - 两个链表的节点数目范围是 [0, 50]
//   - -100 <= Node.val <= 100
//   - l1 和 l2 均按非递减顺序（升序）排列
//
// 思路提示（先别看）：
//   定义一个哑巴节点（dummy）作为新链表的头，用一个指针 tail
//   始终指向新链表的末尾。 每次比较 l1 和 l2 当前节点的值，把较小的那个接到
//   tail 后面，对应链表前进一步。
//   有一个链表走完后，把另一个链表剩余部分直接接上即可。
//   最后返回 dummy->next。

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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    // 你的代码
    ListNode *result = new ListNode();
    ListNode *tail = result;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        result->next = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        result->next = new ListNode(l2->val);
        l2 = l2->next;
      }
      result = result->next;
    };
    if (l1) {
      result->next = l1;
    } else {
      result->next = l2;
    }
    return tail->next;
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

  ListNode *l1 = makeList({1, 2, 4});
  ListNode *l2 = makeList({1, 3, 4});
  printList(s.mergeTwoLists(l1, l2)); // 期望 [1,1,2,3,4,4]

  printList(s.mergeTwoLists(nullptr, nullptr)); // 期望 []

  ListNode *l3 = makeList({0});
  printList(s.mergeTwoLists(nullptr, l3)); // 期望 [0]

  return 0;
}
