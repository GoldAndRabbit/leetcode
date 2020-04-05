/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/

class Solution {
public:
    int partition(int l, int r, vector<int>& nums) {
        int pivot = nums[l];
        while (l < r) {
            while (l < r && nums[r] >= pivot) --r;
                nums[l] = nums[r];
            while (l < r && nums[l] <= pivot) ++l;
                nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int l = 0, r = len - 1;
        int pos;
        while (l <= r) {
            pos = partition(l, r, nums);
            if (pos == len - k) return nums[pos];
            else if (pos > len - k) r = pos - 1;
            else l = pos + 1;
        }
        return 0;
    }
};
