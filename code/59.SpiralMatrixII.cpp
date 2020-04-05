/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]

思路：维护rowStart, rowEnd, colStart, colEnd
走完一行或者一列以后相应的row或者col ++或者--
走完以后判断是否大于n*n,随时break;
 */
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            int target = n * n;
            vector<vector<int> > ans(n, vector<int>(n, 0));
            int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1;
            for (int value = 1; value <= n * n; ) {
                for (int i = colStart; i <= colEnd; i++) {
                    ans[rowStart][i] = value++;
                }
                rowStart++;
                if (value > target) break;
                for (int i = rowStart; i <= rowEnd; i++) {
                    ans[i][colEnd] = value++;
                }
                colEnd--;
                if (value > target) break;
                for (int i = colEnd; i >= colStart; i--) {
                    ans[rowEnd][i] = value++;
                }
                rowEnd--;
                if (value > target) break;
                for (int i = rowEnd; i >= rowStart; i--) {
                    ans[i][colStart] = value++;
                }
                colStart++;
                if (value > target) break;
            }
            return ans;
        }
};

