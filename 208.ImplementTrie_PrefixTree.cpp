/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

trie树
1.根节点为空, 除了根节点之外仅包含一个字符
2.从根节点到某一个节点，路径上的字符连接起来为对应节点的字符串
3.每个节点的所有子节点包含的字符串不相同

实现方法
定义一个TrieNode的类, 成员变量为一个大小为26的数组，然后用一个bool表示到当前位置为止是否为一个单词，初始化的时候26个子节点都赋值为空
*/
class TrieNode {
    public:
    TrieNode* child[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for (auto &x : child) x = NULL;
    }
};
class Trie {
    public:
        /** Initialize your data structure here. */
        Trie() {
            root = new TrieNode();
        }
        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode* p = root;
            for (char x : word) {
                int i = x - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->isWord = true;
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            TrieNode* p = root;
            for (char x : word) {
                int i = x - 'a';
                if (!p->child[i]) return false;
                p = p->child[i];
            }
            return p->isWord;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            TrieNode* p = root;
            for (char x : prefix) {
                int i = x - 'a';
                if (!p->child[i]) return false;
                p = p->child[i];
            }
            return true;
        }
    private:
        TrieNode* root;
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
