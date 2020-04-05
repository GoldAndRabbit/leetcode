/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
顺时针90度
123
456
789
先reverse(matrix.begin(), matrix.end())
789
456
123
再转置
741
852
963

逆时针转90度
123
456
789
先把每一行翻转
321
654
987
再转置
369
258
147
 */

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            if (matrix.empty() || matrix[0].empty())
                return;
            reverse(matrix.begin(), matrix.end());
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = i + 1; j < matrix[0].size(); j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            return;
        }
};



