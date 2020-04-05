/*

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.


A sudoku puzzle...


...and its solution numbers marked in red.
*/

class Solution {
    public:
        bool dfs(int r, int c, vector<vector<char>>& board) {
            if (r == 9) return true;
            if (c == 9) return dfs(r + 1, 0, board);
            if (board[r][c] == '.') {
                for (int i = 1; i <= 9; ++i) {
                    board[r][c] = (char) (i + '0');
                    if (check(r, c, board)) {
                        if (dfs(r, c + 1, board))
                            return true;
                    }
                    board[r][c] = '.';
                }
            } else {
                return dfs(r, c + 1, board);
            }
            return false;
        }
        bool check(int i, int j, vector<vector<char>>& board) {
            for (int c = 0; c < 9; ++c) {
                if (c != j && board[i][c] == board[i][j]) return false;
            }
            for (int r = 0; r < 9; ++r) {
                if (r != i && board[r][j] == board[i][j]) return false;
            }
            for (int r = i / 3 * 3; r < i / 3 * 3 + 3; ++r) {
                for (int c = j / 3 * 3; c < j / 3 * 3 + 3; ++c) {
                    if ((r != i || c != j) && board[r][c] == board[i][j]) return false;
                }
            }
            return true;
        }
        void solveSudoku(vector<vector<char>>& board) {
            if (board.empty() || board[0].empty()) return;
            dfs(0, 0, board);
            return;
        }
};



