/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

中序遍历二叉树
维护上一个节点, 和它节点出现的次数，如果当前节点
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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> s;
        int cnt = 1, mx = 1;
        TreeNode* p = root;
        TreeNode* pre = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            if (pre)
               cnt = (pre->val == p->val) ? cnt + 1 : 1;
            if (cnt >= mx) {
                if (cnt > mx) ans.clear();
                ans.push_back(p->val);
                mx = cnt;
            }
            pre = p;
            p = p->right;
        }
        return ans;
    }
};
