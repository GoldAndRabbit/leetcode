/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* build(int ps, int pe, int is, int ie, vector<int>& preorder, vector<int>& inorder) {
        if (ps > pe) return NULL;
        TreeNode* node = new TreeNode(preorder[ps]);
        int idx;
        for (int i = is; i <= ie; ++i) {
            if (inorder[i] == node->val) {
                idx = i;
                break;
            }
        }
        int leftLen = idx - is;
        int rightLen = (ie - is + 1) - leftLen - 1;
        node->left = build(ps + 1, ps + leftLen, is, idx - 1, preorder, inorder);
        node->right = build(pe - rightLen + 1, pe, idx + 1, ie, preorder, inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        return build(0, len - 1, 0, len - 1, preorder, inorder);
    }
};
