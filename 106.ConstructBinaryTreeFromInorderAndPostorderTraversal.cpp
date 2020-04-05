/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
    TreeNode* build(int is, int ie, int ps, int pe, vector<int>& inorder, vector<int>& postorder) {
        if (ps > pe) return NULL;
        TreeNode* node = new TreeNode(postorder[pe]);
        int idx;
        for (int i = is; i <= ie; ++i) {
            if (inorder[i] == node->val) {
                idx = i;
                break;
            }
        }
        int leftLen = idx - is;
        int rightLen = (ie - is + 1) - leftLen - 1;
        node->left = build(is, idx - 1, ps, ps + leftLen - 1, inorder, postorder);
        node->right = build(idx + 1, ie, pe - rightLen, pe - 1, inorder, postorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        return build(0, len - 1, 0, len - 1, inorder, postorder);
    }
};
