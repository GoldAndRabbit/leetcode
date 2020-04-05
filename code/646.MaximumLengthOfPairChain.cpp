/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].

给定n对数字, 第一个数字比第二个小
定义当b < c时, (c, d)可以跟在(a, b) 后面
给出一系列pair, 返回最长的子链长度

根据first排序
然后dp[i]表示以i为结尾的最大长度
dp[i] = max(dp[i], dp[j] + 1),  0 < j < i

也可以贪心做?
*/

class Solution {
    public:
        static bool cmp(vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        }
        int findLongestChain(vector<vector<int>>& pairs) {
            sort(pairs.begin(), pairs.end(), cmp);
            int len = pairs.size();
            vector<int> dp(len, 1);
            for(int i = 1; i < len; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (pairs[j][1] < pairs[i][0]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            int ans = 0;
            for (auto x : dp) {
                ans = max(ans, x);
            }
            return ans;
        }
};
