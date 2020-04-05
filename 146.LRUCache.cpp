/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(2);

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

想要达到O(1)复杂度，必须用unorderd_map记录key对应的位置
采用双端队列实现
front可以用来加入新的页面
而back可以出去
由于cpp里面list只能用迭代器来指向,因此
unordered_map<int, list<pair<int, int> >::iterator> 这种定义
*/

class LRUCache {
    public:
        int cap;
        list<pair<int, int> > l;
        unordered_map<int, list<pair<int, int> >::iterator> m;
        LRUCache(int capacity) {
            cap = capacity;
        }
        int get(int key) {
            auto it = m.find(key);
            if (it == m.end()) return -1;
            l.splice(l.begin(), l, it -> second);
            return it -> second -> second;
        }
        void put(int key, int value) {
            auto it = m.find(key);
            if (it != m.end()) l.erase(it -> second);
            l.push_front(make_pair(key, value));
            m[key] = l.begin();
            if (m.size() > cap) {
                int outkey = l.rbegin() -> first;
                l.pop_back();
                m.erase(outkey);
            }
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
/**
 ** Your LRUCache object will be instantiated and called as such:
 ** LRUCache obj = new LRUCache(capacity);
 ** int param_1 = obj.get(key);
 ** obj.put(key,value);
 **/
