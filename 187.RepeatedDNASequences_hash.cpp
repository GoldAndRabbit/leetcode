/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/


/*
 * hash，注意条件i + 10 <= s.size() 和 i <= s.size() -10 不一样
size = 100
[0, 99]
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> hash;
        string tmp;
        for (int i = 0; i + 10 <= s.size() ; i++) {
            tmp = s.substr(i, 10);
            if (hash[tmp] == 1)
                ans.push_back(tmp);
            hash[tmp]++;
        }
        return ans;
    }
};
