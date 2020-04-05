/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.
*/


class Solution {
    public:
        int dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
                    visited[i][j] || grid[i][j] == 0) return 0;
            visited[i][j] = true;
            return (1 + dfs(i - 1, j, visited, grid) + dfs(i, j - 1, visited, grid)
                      + dfs(i + 1, j, visited, grid) + dfs(i, j + 1, visited, grid));
        }
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int ans = 0;
            int nr = grid.size(), nc = grid[0].size();
            vector<vector<bool> > visited(nr, vector<bool>(nc, false));
            for (int r = 0; r < nr; ++r) {
                for (int c = 0; c < nc; ++c) {
                    ans = max(ans, dfs(r, c, visited, grid));
                }
            }
            return ans;
        }
};

