/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
思路map<string, vector<int>>保存
由同一种字母构成的字符串，
这里不需要对字符串进行排序
只需要对每个字符串个数进行统计，然后遍历生成唯一字符串
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.empty()) return ans;
        unordered_map<string, vector<string>> m;
        for (string s : strs) {
            vector<int> cnt(26, 0);
            for (char c : s) ++cnt[c - 'a'];
            string tmp = "";
            for (int d : cnt) tmp += to_string(d) + "#";
            m[tmp].push_back(s);
        }
        for (auto x : m)
            ans.push_back(x.second);
        return ans;
    }
};
