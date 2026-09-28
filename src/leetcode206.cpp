// ============================================================================
// LeetCode 206. 反转链表（Reverse Linked List）
// https://leetcode.cn/problems/reverse-linked-list/
// ============================================================================
// 题目描述：
//
//   给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//
// ----------------------------------------------------------------------------
// 示例 1：
//   输入：head = [1,2,3,4,5]
//   输出：[5,4,3,2,1]
//
// 示例 2：
//   输入：head = [1,2]
//   输出：[2,1]
//
// 示例 3：
//   输入：head = []
//   输出：[]
//
// ----------------------------------------------------------------------------
// 提示（数据范围）：
//   链表中节点的数目范围是 [0, 5000]
//   -5000 <= Node.val <= 5000
//
// ----------------------------------------------------------------------------
// 思路提示（链表的入门必考，两种做法）：
//
//   方法一：迭代（三指针法，先掌握这个）
//     准备三个指针 prev / curr / next：
//       1. next 先记住 curr 的下一个节点（防止断链后找不到）
//       2. curr->next 掉头指向 prev（反转箭头）
//       3. prev 和 curr 一起向后挪一位
//     循环结束时 curr 变成 nullptr，prev 就是新的头节点。
//     记忆口诀：先存 next，再掉头，后挪步。
//
//   方法二：递归（进阶）
//     递归到链表尾部，回溯时逐层反转箭头。
//     关键问题想清楚：递归函数返回的是什么？每层要修改哪个指针？
//
//   边界：head 为空或只有一个节点时直接返回 head。
//
//   复杂度：两种方法都是 O(n) 时间，O(1)（迭代）/ O(n)（递归栈空间）。
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
  ListNode *reverseList(ListNode *head) {
    // TODO(你来做)：三指针迭代版
    //   prev = 已反转部分的头，curr = 当前节点，next = 存后路
    //   循环四步：next = curr->next → curr->next = prev → prev = curr → curr = next
    //   循环条件想清楚：curr 为空时结束，返回 prev
    //   别忘了：空链表 / 单节点也能直接过
    return head;
  }

  // ---- 你之前写对的递归版，留作参考 ----
  // ListNode *reverseListRecursive(ListNode *head) {
  //   if (head == nullptr || head->next == nullptr) {
  //     return head;
  //   }
  //   ListNode *newHead = reverseListRecursive(head->next);
  //   head->next->next = head;
  //   head->next = nullptr;
  //   return newHead;
  // }
};

// ---- 测试辅助：vector 建链表 / 链表转 vector 比较 ----
ListNode *build(const std::vector<int> &v) {
  ListNode dummy; // 哑节点：简化头插
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
  ListNode *got = Solution().reverseList(build(input));
  std::vector<int> v = toVec(got);
  std::cout << (v == expected ? "PASS" : "FAIL") << " -> ";
  for (int x : v)
    std::cout << x << ' ';
  std::cout << '\n';
  // 释放内存（练习阶段先不管泄漏细节）
  while (got) {
    ListNode *nxt = got->next;
    delete got;
    got = nxt;
  }
}

int main() {
  test({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}); // 示例 1
  test({1, 2}, {2, 1});                   // 示例 2
  test({}, {});                           // 空链表边界
  test({7}, {7});                         // 单节点边界
  test({1, 1, 2, 2}, {2, 2, 1, 1});       // 重复值
  return 0;
}
