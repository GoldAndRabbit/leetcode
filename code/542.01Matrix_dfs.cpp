/*
 *
 ven a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

 The distance between two adjacent cells is 1.
 Example 1:
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2:
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
*/


/*
 * 思路：答案matrix初始化为INT_MAX,如果为0那么设置为0
 * bfs，将每个位置为0的位置加入队列。对上下左右四个位置搜索
 * if ans[i][j] + 1 < ans[cur.first][cur.second]
 *      ans[cur.first][cur.second] = ans[i][j] + 1
 */

class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
            if (matrix.empty())
                return matrix;
            int nr = matrix.size();
            int nc = matrix[0].size();
            vector<vector<int> > ans(nr, vector<int>(nc, INT_MAX));
            queue<pair<int, int> > q;
            for (int i = 0; i < nr; i++) {
                for (int j = 0; j < nc; j++) {
                    if (matrix[i][j] == 0) {
                        q.push(make_pair(i, j));
                        ans[i][j] = 0;
                    }
                }
            }
            int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int x = cur.first + dir[i][0];
                    int y = cur.second + dir[i][1];
                    if (x >= 0 && y >= 0 && x < nr && y < nc) {
                        if (ans[cur.first][cur.second] + 1 < ans[x][y]) {
                            ans[x][y] = ans[cur.first][cur.second] + 1;
                            q.push(make_pair(x, y));
                        }
                    }
                }
            }
            return ans;
        }
};
