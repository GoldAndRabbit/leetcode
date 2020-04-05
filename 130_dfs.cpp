/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

/*
思路：搜索四周的元素，然后dfs相邻元素, 将边缘的O暂时设置为1
然后将其余剩下的O（就是包围的O)，设置为X
然后将1都还原为O
 */

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        int nr = board.size();
        int nc = board[0].size(); 
        if (board[r][c] == 'O') {
            board[r][c] = '1';
            if (r >= 1) 
                dfs(r - 1, c, board);
            if (c >= 1)
                dfs(r, c - 1, board);
            if (r + 1 < nr)
                dfs(r + 1, c, board);
            if (c + 1 < nc)
                dfs(r, c + 1, board);
        }
        return;
    }
    void solve(vector<vector<char>>& board) { 
        int nr = board.size();
        if (!nr)
            return;
        int nc = board[0].size();
        for (int i = 0; i < nr; i++) {
            dfs(i, 0, board);
            if (nc > 1) 
                dfs(i, nc - 1, board);
        }        
        for (int i = 1; i + 1 < nc; i++) {
            dfs(0, i, board);
            if (nr > 1)
                dfs(nr - 1, i, board);
        } 
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
        return;
    } 
};

