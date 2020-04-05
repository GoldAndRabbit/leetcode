/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input:

          1
         /
        3
       / \
      5   3

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input:

          1
         / \
        3   2
       /
      5

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input:

          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
Note: Answer will in the range of 32-bit signed integer.

思路：
层序遍历
queue保存<TreeNode*, idx>
如果节点的位置是i
那么左边孩子的节点是2*i-1
和2*i
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 1});
        int ans = 1;
        while (!q.empty()) {
            int cnt = q.size();
            int left = q.front().second, right = left;
            for (int i = 0; i < cnt; ++i) {
                auto cur = q.front().first;
                right = q.front().second;
                q.pop();
                if (cur->left) q.push({cur->left, right*2});
                if (cur->right) q.push({cur->right, right*2+1});
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
