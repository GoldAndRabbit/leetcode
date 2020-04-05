/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

class Solution {
public:
    int mx[4] = {0, 0, 1, -1};
    int my[4] = {-1, 1, 0, 0};
    int dfs(int x, int y, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        if (dp[x][y] != 0) return dp[x][y];
        dp[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int dx = x + mx[i];
            int dy = y + my[i];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && matrix[dx][dy] < matrix[x][y])
                dp[x][y] = max(dp[x][y], dfs(dx, dy, m, n, dp, matrix) + 1);
        }
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = max(ans, dfs(i, j, m, n, dp, matrix));
        return ans;
    }
};

