/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

只能从不直接连接的两个节点上偷钱，请问能偷到的最多的钱.

从根节点开始遍历，有两种选择偷该节点还是不偷
用一个vector<int> (2)来keep该节点偷和不偷对应的最大收益
vector<int> dfs(TreeNode* root) {
    if (!root) return vector<int>(2);
    vector<int> left = dfs(root->left);
    vector<int> right = dfs(root->right);
    vector<int> ret(2);
    ret[0] = root->val + left[1] + right[1];
    ret[1] = max(left[0], left[1]) + max(right[0], right[1]);
    return ret;
}
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
    vector<int> dfs(TreeNode* root) {
        if (!root) return vector<int>(2);
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        vector<int> ret(2);
        ret[0] = root->val + left[1] + right[1];
        ret[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return ret;
    }
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};
