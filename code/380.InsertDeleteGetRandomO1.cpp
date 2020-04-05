/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

Example:
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();

思路
若不限制复杂度, 那么用一个set可以搞定，现在要求插入和删除都是O1，
需要用一个vector和一个unordered_map实现，

插入操作：map找到是否存在，不存在则插入到vector的末尾, map记录元素在vector的下标
删除操作：map找是否存在，若存在，为了实现O1复杂度，需要将要删除的数字和数组最后一个数字调换一下位置，然后删除数组中的最后一个数字同时更新map,这样可以实现O1时间复杂度
随机生成：return nums[rand() % nums.size()]
*/

class RandomizedSet {
    public:
        /** Initialize your data structure here. */
        RandomizedSet() {
        }

        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val) {
            if (m.count(val)) return false;
            nums.push_back(val);
            m[val] = nums.size() - 1;
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            if (!m.count(val)) return false;
            int last = nums.back();
            m[last] = m[val]; nums[m[val]] = last;
            nums.pop_back(); m.erase(val);
            return true;
        }

        /** Get a random element from the set. */
        int getRandom() {
            return nums[rand() % nums.size()];
        }
    
    private:
        vector<int> nums;
        unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
