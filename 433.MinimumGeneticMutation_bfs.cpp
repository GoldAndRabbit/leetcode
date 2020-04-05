/*
A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Note:

Starting point is assumed to be valid, so it might not be included in the bank.
If multiple mutations are needed, all mutations during in the sequence must be valid.
You may assume start and end string is not the same.
Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1
Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2
Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3
 */

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.empty())
            return -1;
        unordered_set<string> s(bank.begin(), bank.end());
        unordered_set<string> visited;
        vector<char> gen{'A', 'T', 'C', 'G'};
        int ans = 0;
        queue<string> q;
        q.push(start);
        string cur;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                cur = q.front();
                q.pop();
                if (cur == end)
                    return ans;
                for (int i = 0; i < cur.size(); i++) {
                    char preChar = cur[i];
                    for(auto x: gen){
                        cur[i] = x;
                        if (s.count(cur) && !visited.count(cur)) {
                            visited.insert(cur);
                            q.push(cur);
                        }
                        cur[i] = preChar;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};