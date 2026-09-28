// ============================================================================
// LeetCode 141. 环形链表（Linked List Cycle）
// https://leetcode.cn/problems/linked-list-cycle/
// ============================================================================
// 题目描述：
//
//   给你一个链表的头节点 head ，判断链表中是否有环。
//   如果链表中存在环，则返回 true；否则，返回 false。
//
//   （评测系统用整数 pos 表示环的位置：尾节点连到第 pos 个节点；
//     pos = -1 表示无环。注意 pos 不作为参数传递。）
//
// ----------------------------------------------------------------------------
// 示例 1：
//   输入：head = [3,2,0,-4], pos = 1
//   输出：true
//   解释：链表中有一个环，其尾部连接到第二个节点。
//
// 示例 2：
//   输入：head = [1,2], pos = 0
//   输出：true
//   解释：链表中有一个环，其尾部连接到第一个节点。
//
// 示例 3：
//   输入：head = [1], pos = -1
//   输出：false
//   解释：链表中没有环。
//
// ----------------------------------------------------------------------------
// 提示（数据范围）：
//   链表中节点的数目范围是 [0, 10^4]
//   -10^5 <= Node.val <= 10^5
//   pos 为 -1 或者链表中的一个有效索引
//
//   进阶：你能用 O(1)（即，常量）内存解决此问题吗？
//
// ----------------------------------------------------------------------------
// 思路提示（经典的"快慢指针"登场）：
//
//   方法一：哈希表（unordered_set 存走过的节点地址）
//     走到重复节点 = 有环。好理解，但 O(n) 额外空间。
//
//   方法二：快慢指针（Floyd 判圈法，进阶要求的正解，推荐）
//     想像两个人在环形操场跑步：
//       慢指针 slow 每次走 1 步，快指针 fast 每次走 2 步
//       - 如果无环：fast 会先走到 nullptr，直接返回 false
//       - 如果有环：fast 会"套圈"追上 slow，两者相遇 = 有环
//
//     为什么有环一定会相遇？（思考题）
//     每走一步，fast 相对 slow 靠近 1 步，环内距离只会缩小不会增大。
//
//   边界：head 为空、单节点无环，都要能直接处理。
//
//   复杂度：O(n) 时间，O(1) 空间（快慢指针）。
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
  bool hasCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr){return false;}
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast != slow){
        if(fast == nullptr || fast->next == nullptr){return false;}
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    // TODO(你来做)：快慢指针
    //   slow 每次 1 步，fast 每次 2 步
    //   循环条件怎么写？（要防 fast->next 为空时的解引用）
    //   相遇返回 true，fast 到尽头返回 false
  }
};

// ---- 测试辅助：建链表；pos >= 0 时尾巴接到第 pos 个节点形成环 ----
ListNode *build(const std::vector<int> &v, int pos, ListNode *&tail) {
  ListNode dummy;
  ListNode *p = &dummy;
  ListNode *cycleEntry = nullptr;
  for (int i = 0; i < (int)v.size(); ++i) {
    p->next = new ListNode(v[i]);
    p = p->next;
    if (i == pos)
      cycleEntry = p;
  }
  tail = p;
  if (cycleEntry)
    tail->next = cycleEntry; // 接环
  return dummy.next;
}

void test(std::vector<int> v, int pos, bool expected) {
  ListNode *tail = nullptr;
  ListNode *head = build(v, pos, tail);
  bool got = Solution().hasCycle(head);
  std::cout << (got == expected ? "PASS" : "FAIL") << " -> "
            << (got ? "true" : "false") << '\n';
  if (tail)
    tail->next = nullptr; // 先断环，否则下面的释放会死循环！
  while (head) {
    ListNode *nxt = head->next;
    delete head;
    head = nxt;
  }
}

int main() {
  test({3, 2, 0, -4}, 1, true);  // 示例 1：环在索引 1
  test({1, 2}, 0, true);         // 示例 2：自己成环
  test({1}, -1, false);          // 示例 3：单节点无环
  test({}, -1, false);           // 空链表
  test({1, 2, 3}, -1, false);    // 多个节点但无环
  test({1, 2, 3}, 2, true);      // 尾巴接最后一个节点
  return 0;
}
