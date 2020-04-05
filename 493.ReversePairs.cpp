/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
*/

class Solution {
    public:
        int mergeSortAndCount(int left, int right, vector<int>& nums) {
            if (left >= right) return 0;
            int mid = left + (right - left) / 2;
            int cnt = mergeSortAndCount(left, mid, nums) + mergeSortAndCount(mid + 1, right, nums);
            for (int i = left, j = mid + 1; i <= mid; ++i) {
                // 注意此处转化成除以2.0
                while (j <= right && nums[i] / 2.0 > nums[j]) ++j;
                cnt += j - (mid + 1);
            }
            sort(nums.begin() + left, nums.begin() + right + 1);
            return cnt;
        }
        int reversePairs(vector<int>& nums) {
            return mergeSortAndCount(0, nums.size() - 1, nums);
        }
};

