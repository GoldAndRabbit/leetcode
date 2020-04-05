/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

1.Each row must have the numbers 1-9 occuring just once.
2.Each column must have the numbers 1-9 occuring just once.
3.And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.


The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

验证一个数独的是否有效，这里的数独可以是无解的数独
用3个标记矩阵表示row、flag、cell元素是否重新出现过，对cell类的
可以用3 * (i / 3) + (j / 3) 来标记
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> row(m, vector<bool>(n, false));
        vector<vector<bool>> col(m, vector<bool>(n, false));
        vector<vector<bool>> cell(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    int d = board[i][j] - '1';
                    if (row[i][d] || col[d][j] || cell[3 * (i / 3) + (j / 3)][d])
                        return false;
                    row[i][d] = true;
                    col[d][j] = true;
                    cell[3 * (i / 3) + (j / 3)][d] = true;
                }
            }
        }
        return true;
    }
};
