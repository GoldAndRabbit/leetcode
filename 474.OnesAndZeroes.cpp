/*
In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.

Note:
The given numbers of 0s and 1s will both not exceed 100
The size of given string array won't exceed 600.
Example 1:
Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
Output: 4

Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
Example 2:
Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2

Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".

题意:
给定一个数组，数组里面的元素都是由0和1组成的字符串
现在需要构成一个含有m个0和n个1的字符串
求最大使用几个数组中的元素

0-1背包
dp[i][j]表示i个0，j个1的时， 最大的字符串数目
遍历数组
然后状态更新
for (int i = m; i >= zeros; --i) {
    for (int j = n; j >= ones; --j) {
        dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
    }
}
return dp[m][n]
*/
class Solution {
    public:
        int countZeros(string s) {
            int cnt = 0;
            for (auto c : s)
                if (c == '0')
                    ++cnt;
            return cnt;
        }
        int findMaxForm(vector<string>& strs, int m, int n) {
            vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
            int zeros, ones;
            for (int i = 0; i < strs.size(); ++i) {
                zeros = countZeros(strs[i]);
                ones = strs[i].size() - zeros;
                for (int i = m; i >= zeros; --i) {
                    for (int j = n; j >= ones; --j) {
                        dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                    }
                }
            }
            return dp[m][n];
        }
};