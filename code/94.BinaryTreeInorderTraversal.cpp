/*

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (!s.empty() || p) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }
};
