/*
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

假设有N个整数从1到N，定美丽排列.如果每个位置满足以下任意一个条件
第i个位置上的数字可以被i整除
i可以被第i个位置上的数整除
请问满足排列的个数

Example 1:
Input: 2
Output: 2
Explanation:

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.

思路：回溯求每个位置
用visit数组表示是否已经访问过
*/

class Solution {
    public:
        void helper(int pos, int N, vector<bool>& visited, int& ans) {
            if (pos > N) {
                ++ans;
                return;
            }
            for (int i = 1; i <= N; ++i) {
                if (visited[i] == false && ((pos % i == 0) || (i % pos == 0))) {
                    visited[i] = true;
                    helper(pos + 1, N, visited, ans);
                    visited[i] = false;
                }
            }
        }
        int countArrangement(int N) {
            int ans = 0;
            vector<bool> visited(N + 1, false);
            helper(1, N, visited, ans);
            return ans;
        }
};
