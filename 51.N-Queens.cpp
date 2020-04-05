/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
vector<int> pos(n, -1)存储第i行的Q放置的位置
从0行开始枚举每个列，进行检查，然后回溯
检查的时候, 检查之前的行是否在列上相等, 或者对角线, 这样的好处是不需要检查行了
if c == pos[i] or abc(r - i) == abs(c - pos[i]) return false
*/


class Solution {
public:
    void dfs(int r, vector<int>& pos, vector<vector<string>>& ans) {
        int n = pos.size();
        if (r == n) {
            vector<string> out(n, string(n, '.'));
            for (int i = 0; i < n; ++i)
                out[i][pos[i]] = 'Q';
            ans.push_back(out);
        } else {
            for (int c = 0; c < n; ++c) {
                if (check(r, c, pos)) {
                    pos[r] = c;
                    dfs(r + 1, pos, ans);
                    pos[r] = -1;
                }
            }
        }
    }
    bool check(int r, int c, vector<int>& pos) {
        for (int i = 0; i < r; ++i) {
            if (c == pos[i] || abs(r - i) == abs(c - pos[i]))
                return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos(n, -1);
        dfs(0, pos, ans);
        return ans;
    }
};
