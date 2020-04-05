/*
You need to find the largest value in each row of a binary tree.

Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int rowMax;
        int qsize;
        while (!q.empty()) {
            qsize = q.size();
            rowMax = INT_MIN;
            for (int i = 0; i < qsize; i++) {
                TreeNode* curNode = q.front();
                rowMax = max(rowMax, curNode -> val);
                q.pop();
                if (curNode -> left != NULL)
                    q.push(curNode -> left);
                if (curNode -> right != NULL)
                    q.push(curNode -> right);
            }
            ans.push_back(rowMax);
        }
        return ans;
    }
};
