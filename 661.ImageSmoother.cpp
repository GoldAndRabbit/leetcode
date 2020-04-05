/*
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
*/

class Solution {
    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
            int nr = M.size(), nc = M[0].size();
            vector<vector<int> > ans(nr, vector<int>(nc, 0));
            int cnt;
            for (int r = 0; r < nr; ++r) {
                for (int c = 0; c < nc; ++c) {
                    cnt = 0;
                    for (int i = r - 1; i <= r + 1; ++i) {
                        for (int j = c - 1; j <= c + 1; ++j) {
                            if (0 <= i && i < nr && 0 <= j && j < nc) {
                                ans[r][c] += M[i][j];
                                ++cnt;
                            }
                        }
                    }
                    ans[r][c] /= cnt;
                }
            }
            return ans;
        }
};
