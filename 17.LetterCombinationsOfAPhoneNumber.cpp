/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

2:abc
3:def
4:ghi
5:jkl
6:mno
7:pqrs
8:tuv
9:wxyz

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

一开始建立一个map
string m[10] = {"0", "1", "abc", "bd", "be", "bf", "cd", "ce", "cf"};

迭代求解
第一轮
ans = ""
第二轮
abc
第三轮
ad ae af bd be bf cd ce cf
每次更新ans
*/

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            if (digits.empty()) return ans;
            string charMap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            ans.push_back("");
            vector<string> next;
            for (int i = 0; i < digits.size(); ++i) {
                next.clear();
                string s = charMap[digits[i] - '0'];
                for (int j = 0; j < ans.size(); ++j) {
                    for (int k = 0; k < s.size(); ++k)
                        next.push_back(ans[j] + s[k]);
                }
                ans = next;
            }
            return ans;
        }
};
