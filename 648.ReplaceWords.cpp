/*
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000

思路：
set存放所有的dict
遇到了空格, 直接加上词语
如果遇到的不是空格, 而且是第一个且描出来的词是dict里面的，那么加入。
*/


class Solution {
    public:
        string replaceWords(vector<string>& dict, string sentence) {
            string ans;
            string cur;
            unordered_set<string> s(dict.begin(), dict.end());
            int flag = 1; // 用flag标记否当前在一个合法单词上
            for (int i = 0; i < sentence.size(); i++) {
                if (sentence[i] == ' ') {
                    ans += cur;
                    ans += ' ';
                    cur.clear();
                    flag = 1;
                } else if (flag) {
                    cur += sentence[i];
                    if (s.count(cur) > 0) {
                        ans += cur;
                        cur.clear();
                        flag = 0;
                    }
                }
            }
            ans += cur;
            return ans;
        }
};
