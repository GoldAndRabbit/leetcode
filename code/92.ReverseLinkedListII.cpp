/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.


用dummy来记录第一个节点
首先要找到待逆转的链表中的第一个节点之前的节点保存起来，记录为pre

2 3 4
第一步变成
3 2 4
第二步变成
4 3 2

这个思路很厉害在草稿纸上画图

然后当前节点记录为cur, 下一个要提前的节点记录为then
cur->next = then->next;
then->next = pre->next;
pre->next = then;
then = cur->next
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *    int val;
 *    ListNode *next;
 *    ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if (!head) return NULL;
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;
            ListNode* pre = dummy;
            for (int i = 0; i < m - 1; ++i) pre = pre->next;
            ListNode* cur = pre->next;
            ListNode* then = cur->next;
            for (int i = m; i < n; ++i) {
                cur->next = then->next;
                then->next = pre->next;
                pre->next = then;
                then = cur->next;
            }
            return dummy->next;
        }
};
