/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input:
nums =
[[1,2],
 [3,4]]
 r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input:
nums =
[[1,2],
 [3,4]]
 r = 2, c = 4
Output:
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.

用r,c记录当前遍历到的位置
直接遍历直接填充元素

第i个元素在矩阵里面的下标 [i / nc][i % nc]
3*4的矩阵
123
456
789
101112
*/


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int nr = nums.size(), nc = nums[0].size();
        if (nr * nc != r * c) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        int k; // k 记录第几个元素
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                k = i * c + j;
                ans[i][j] = nums[k / nc][k % nc];
            }
        }
        return ans;
    }
};
