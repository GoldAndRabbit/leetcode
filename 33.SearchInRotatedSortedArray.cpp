/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

旋转数组的二分法
0 1 2 3 4 5 6 7
7 0 1 2 3 4 5 6
6 7 0 1 2 3 4 5
5 6 7 0 1 2 3 4
4 5 6 7 0 1 2 3

3 4 5 6 7 0 1 2
2 3 4 5 6 7 0 1
1 2 3 4 5 6 7 0

if A[mid] < A[right] 则右侧一半有序
if A[mid] <= A[left] 则左侧一半有序
*/

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            if (n == 0) return -1;
            int left = 0, right = n - 1;
            int mid;
            while (left <= right) {
                mid = (left + right) >> 1;
                if (nums[mid] == target) return mid;
                else if (nums[mid] < nums[right]) {
                    if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                    else right = mid - 1;
                } else {
                    if (nums[left] <= target && target < nums[mid]) right = mid - 1;
                    else left = mid + 1;
                }
            }
            return -1;
        }
};
