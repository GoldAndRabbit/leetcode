/*
 *Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
 */


/*
 * 思路：同样是维护一个长度为K的无重复滑动窗口
 * |x - nums[i]| <= t, so -t <= x-nums[i] <= t
 * so x - nums[i] >= -t, so x >= nums[i] - t
 * 用lower_bound可以判断 x >= nums[i] - t
 * auto pos = lower_bound(nums[i] - t) 存在
 * 然后判断*pos - nums[i] <= t
 */


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0)
           return false;
        set<long long> window;
        set<long long>::iterator pos;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
               window.erase(nums[i - k - 1]);
            pos = window.lower_bound((long long)nums[i] - t);
            if (pos != window.end() && *pos - nums[i] <= t)
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
