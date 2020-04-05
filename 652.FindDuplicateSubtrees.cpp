/*
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.
思路，反序列化所有的树, 用一个map记录每个字符串出现的次数
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
    string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& m) {
        if (!node) return "#";
        string s = to_string(node->val) + "," + serialize(node->left, m) + "," + serialize(node->right, m);
        m[s].push_back(node);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, vector<TreeNode*>> m;
        serialize(root, m);
        for (auto it = m.begin(); it != m.end(); ++it)
            if (it->second.size() > 1) ans.push_back(it->second[0]);
        return ans;
    }
};
