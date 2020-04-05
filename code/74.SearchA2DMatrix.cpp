/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.


使用二分搜索来做，不要把它当作一个2D矩阵，把它当作一个数组来做
m * n的矩阵转化成array matrix[x][y] => a[x * m + y]
数组转化为m * n的矩阵 a[x] => matrix[x / m][x % n]
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        if (target < matrix[0][0] || target > matrix.back().back()) return false;
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (matrix[mid / n][mid % n] == target) return true;
            else if (matrix[mid / n][mid % n] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};