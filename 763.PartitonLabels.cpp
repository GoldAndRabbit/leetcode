/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
将一个字符串找到一个分割
使得每个字母都唯一属于一个分割
返回每个部分的长度vector
要求分割数目最大

思路：
用一个数组存储每个字母最后一次出现的位置
设[start, end]为当前的一个part
遍历字符:
假设当前字符为c
贪心地将当前区间扩展为该字母出现的最后一个字符j = last[c]
若i == end:
那么累加一个区间长度并且start = i + 1
*/



class Solution {
    public:
        vector<int> partitionLabels(string S) {
            vector<int> hash(26, 0);
            vector<int> ans;
            for (int i = 0; i < S.size(); ++i) hash[S[i] - 'a'] = i;
            int start = 0, end = 0;
            for (int i = 0 ; i < S.size(); ++i) {
                end = max(end, hash[S[i] - 'a']);
                if (i == end) {
                    ans.push_back(end - start + 1);
                    start = i + 1;
                }
            }
            return ans;
        }
};