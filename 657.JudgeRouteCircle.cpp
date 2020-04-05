/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false

思路
模拟
一开始是00，然后最后看末尾坐标是否是00
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'U') y += 1;
            else if (c == 'D') y -= 1;
            else if (c == 'L') x -= 1;
            else if (c == 'R') x += 1;
        }
        return x == 0 && y == 0;
    }
};
