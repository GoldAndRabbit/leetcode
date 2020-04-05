/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

/*
 *
 *
 */


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int qsize;
        int mostRight;
        while (!q.empty()) {
            qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                if (curNode -> left)
                    q.push(curNode -> left);
                if (curNode -> right)
                    q.push(curNode -> right);
                if (i == qsize - 1)
                    mostRight = curNode -> val;
            }
            ans.push_back(mostRight);
        }
        return ans;
    }
};
