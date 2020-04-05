/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

用1代表方块状的小岛，求小岛周长(perimeter)。
考虑每个小方块的所有的边

遍历所有位置如果该位置为1

如果一个方块是最左边的或者左边为0，那么累计左边的一条边
同理统计其余三条边
*/

class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            int nr = grid.size(), nc = grid[0].size();
            int ans = 0;
            for (int i = 0; i < nr; ++i) {
                for (int j = 0; j < nc; ++j) {
                    if (grid[i][j] == 1) {
                        if (i == 0 || grid[i - 1][j] == 0) ++ans;
                        if (i == nr - 1 || grid[i + 1][j] == 0) ++ans;
                        if (j == 0 || grid[i][j - 1] == 0) ++ans;
                        if (j == nc - 1 || grid[i][j + 1] == 0) ++ans;
                    }
                }
            }
            return ans;
        }
};
