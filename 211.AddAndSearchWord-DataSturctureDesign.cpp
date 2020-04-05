/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.

You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/


class TrieNode {
    public:
        bool isWord;
        TrieNode* child[26];
        TrieNode() : isWord(false) {
            for (auto &x : child) x = NULL;
        }
};

class WordDictionary {
    public:
        /** Initialize your data structure here. */
        WordDictionary() {
            root = new TrieNode();
        }
        /** Adds a word into the data structure. */
        void addWord(string word) {
            TrieNode* p = root;
            for (char x : word) {
                int i = x - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->isWord = true;
        }
        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
        bool search(string word) {
            return searchWord(word, root, 0);
        }

        bool searchWord(string& word, TrieNode* p, int pos) {
            if (pos == word.size()) return p->isWord;
            if (word[pos] != '.') {
                return p->child[word[pos] - 'a'] && searchWord(word, p->child[word[pos] - 'a'], pos + 1);
            } else {
                for (auto x : p->child) {
                    if (x && searchWord(word, x, pos + 1)) return true;
                }
                return false;
            }
        }
    private:
        TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
