/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

这个题允许有重复元素
例如
1 1 3 1
继续应用mid < right则右边有序，否则左边一半有序
此时mid = right
此时可以将right左移
1 1 3
*/

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int len = nums.size();
            if (len == 0) return false;
            int left = 0, right = len - 1;
            int mid;
            while (left <= right) {
                mid = (left + right) >> 1;
                if (target == nums[mid]) return true;
                else if (nums[mid] < nums[right]) {
                    if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                    else right = mid - 1;
                } else if (nums[mid] > nums[right]) {
                    if (target < nums[mid] && target >= nums[left]) right = mid - 1;
                    else left = mid + 1;
                } else
                    --right;
            }
            return false;
        }
};
