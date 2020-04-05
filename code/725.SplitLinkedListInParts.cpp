/*
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
*/
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*

这道题的难点是求出来划分的位置
例如
123 456 78      len = 8, k = 3, width = 3, rema = 2
0   1   2
<2 的index移动width个
>=2的index移动width-1个

123 45 67       len = 7, k = 3, width = 2, rema = 1
0   1  2
<1的index移动width个
>=1的index移动width-1个

1 2 3           len = 3, k = 5, width = 0, rema = 3
0 1 2 3 4
<3的index移动width个
>=3的index移动width-1个

width + (i < rema ? 1: 0)
如果i < rema
需要移动width个长度
如果i >= rema
需要移动width - 1这个长度
移动完了之后自然断开链表
如果不移动了就断开链表、如果cur == nullptr了终止
 */

class Solution {
    public:
       vector<ListNode*> splitListToParts(ListNode* root, int k) {
            int len = 0;
            ListNode* cur = root;
            while (cur) {len++; cur = cur -> next; }
            int width = len / k;
            int rema = len % k;
            vector<ListNode*> ans(k, nullptr);
            cur = root;
            for (int i = 0; i < k && cur; i++) {
                ans[i] = cur;
                for (int j = 0; j < width + (i < rema ? 1 : 0) - 1; j++) {
                    cur = cur -> next;
                }
                ListNode* next = cur -> next;
                cur -> next = nullptr;
                cur = next;
            }
            return ans;
        }
};
