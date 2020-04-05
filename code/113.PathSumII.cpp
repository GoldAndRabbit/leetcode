/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void dfs(TreeNode* p, int sum, vector<int>& tmp, vector<vector<int>>& ans) {
        if (sum == p->val && !(p->left) && !(p->right)) {
            tmp.push_back(p->val);
            ans.push_back(tmp);
            return;
        } else {
            tmp.push_back(p->val);
            if (p->left) {
                dfs(p->left, sum - (p->val), tmp, ans);
                tmp.pop_back();
            }
            if (p->right) {
                dfs(p->right, sum - (p->val), tmp, ans);
                tmp.pop_back();
            }
            return;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        if (!root) return ans;
        dfs(root, sum, tmp, ans);
        return ans;
    }
};
