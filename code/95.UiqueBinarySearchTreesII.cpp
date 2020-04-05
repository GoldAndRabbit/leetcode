/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> helper(int s, int e) {
        if (s > e) return vector<TreeNode*>(1, NULL);
        vector<TreeNode*> ret;
        for (int i = s; i <= e; ++i) {
            vector<TreeNode*> l, r;
            l = helper(s, i - 1); r = helper(i + 1, e);
            for (int j = 0; j < l.size(); ++j) {
                for (int k = 0; k < r.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> emp;
        if (n < 1) return emp;
        return helper(1, n);
    }
};
