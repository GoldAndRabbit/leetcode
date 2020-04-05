/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/


/*
 *
 * 思路：维护一个长度k的set
 * 如果当前元素在set中存在则true
 */


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k <= 0)
           return false;
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                window.erase(nums[i - k - 1]);
            if (window.find(nums[i]) != window.end())
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

