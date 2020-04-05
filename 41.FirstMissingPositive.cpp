/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

找到第一个缺失的正数
题目要求了O(1)空间复杂度，因此不能hash
数组中的元素又有正数也有负数

如果找到5，那么放在A[4]
将1放在A[0], 2放在A[1], 3放在A[2], A[i]放在A[A[i] - 1] 因为要O(1)空间，该操作通过多次交换实现
*/

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int len = nums.size();
            for (int i = 0; i < len; ++i) {
                while (nums[i] > 0 && nums[i] != nums[nums[i] - 1] && nums[i] <= len)
                   swap(nums[i], nums[nums[i] - 1]);
            }
            for (int i = 0; i < len; ++i)
                if (nums[i] != i + 1) return i + 1;
            return len + 1;
        }
};

