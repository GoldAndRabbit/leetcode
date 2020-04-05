/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    void dfs(int pos, int n, int k, vector<int>& t, vector<vector<int>>& ans) {
        if (t.size() == k) ans.push_back(t);
        for (int i = pos; i <= n; ++i) {
            t.push_back(i);
            dfs(i + 1, n, k, t, ans);
            t.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(1, n, k, tmp, ans);
        return ans;
    }
};
