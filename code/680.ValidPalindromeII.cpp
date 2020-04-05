/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

用贪心的方法实现
if s[l] == s[r]那么整个字符串是否回文只是取决于
s[l+1:r-1]是否回文
else
    return check(s[l : r - 1]) || check(s[l + 1 : r])
*/

class Solution {
    public:
        bool check(string s, int l, int r) {
            for (int i = l; i <= (r + l) / 2; ++i)
                if (s[i] != s[r - i + l]) return false;
            return true;
        }
        bool validPalindrome(string s) {
            for (int i = 0; i < s.size() / 2; ++i) {
                if (s[i] != s[s.size() - i - 1]) {
                    int j = s.size() - i - 1;
                    return (check(s, i + 1, j) || check(s, i, j - 1));
                }
            }
            return true;
};