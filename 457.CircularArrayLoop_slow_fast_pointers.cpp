/*
You are given an array of positive and negative integers. If a number n at an index is positive, then move forward n steps. Conversely, if it's negative (-n), move backward n steps. Assume the first element of the array is forward next to the last element, and the last element is backward next to the first element. Determine if there is a loop in this array. A loop starts and ends at a particular index with more than 1 element along the loop. The loop must be "forward" or "backward'.

Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.

Example 2: Given the array [-1, 2], there is no loop.

Note: The given array is guaranteed to contain no element "0".

Can you do it in O(n) time complexity and O(1) space complexity?
 */

/*
这个题思路是模拟快慢指针来判断是否存在环。
如果不存在环，则必然是false
如果不存在环，那么把沿途的点都加上标记（因为肯定不可能满足题意)
如果存在环，需要判断是否是那种自循环的情况。
为了模拟快慢指针，需要写一个getNextIndex函数。
如果超出了nums的大小那么对n求模。
如果是负数那么加上n
 */
class Solution {
    public:
        int getNextIndex(int i, vector<int> nums) {
            int n = nums.size();
            if (i + nums[i] >= 0)
                return (i + nums[i]) % n;
            else
                return n + (i + nums[i]) % n;
        }

        bool circularArrayLoop(vector<int>& nums) {
            if (nums.empty() || nums.size() < 2)
                return false;
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                // if nums[i] == 0, we're not in a loop path
                if (nums[i] == 0)
                   continue;
                int slow = i;
                int fast = getNextIndex(slow, nums);
                while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[getNextIndex(fast, nums)] > 0) {
                    if (slow == fast) {
                        if (slow == getNextIndex(slow, nums))
                           break;
                        else
                           return true;
                    }
                    slow = getNextIndex(slow, nums);
                    fast = getNextIndex(getNextIndex(fast, nums), nums);
                }
                int sgn = nums[i];
                slow = nums[i];
                while (sgn * nums[slow] > 0) {
                    int tmp = getNextIndex(slow, nums);
                    nums[slow] = 0;
                    slow = tmp;
                }
            }
            return false;
        }
};
