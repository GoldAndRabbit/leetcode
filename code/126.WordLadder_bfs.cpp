/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

/*
思路:
bfs
用map记录当前单词和当前的步长
用队列保存这一层需要搜索单词
每层单词枚举每个位置上改变了字母后的结果，检查改变字母后的单词是否在set里面
用一个set来记录所有的word
*/
class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string> wordList) {
            unordered_set<string> s(wordList.begin(), wordList.end());
            unordered_map<string, int> m;
            queue<string> q;
            q.push(beginWord);
            m[beginWord] = 1;
            string curWord;
            string newWord;
            while (!q.empty()) {
                curWord = q.front();
                q.pop();
                for (int i = 0; i < curWord.size(); i++) {
                    newWord = curWord;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        newWord[i] = ch;
                        if (s.count(newWord) > 0 && newWord == endWord)
                            return m[curWord] + 1;
                        if (s.count(newWord) > 0 && m.count(newWord) == 0) {
                            m[newWord] = m[curWord] + 1;
                            q.push(newWord);
                        }
                    }
                }
            }
            return 0;
        }
};
