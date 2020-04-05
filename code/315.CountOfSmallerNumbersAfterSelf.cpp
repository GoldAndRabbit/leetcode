/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

思路
核心思想就是把小于它的都放在一个数组里

新建一个空数组t
从后往前遍历nums, 用二分搜索t数组找到第一个大于等于它的
然后ans[i] = right; 即在t中的坐标
插入t数组t.insert(t.begin() + right), nums[i]);
t为一个经过排序的数组
 */

class Solution {
    public:
        vector<int> countSmaller(vector<int>& nums) {
            vector<int> t, ans(nums.size());
            for (int i = nums.size() - 1; i >= 0; --i) {
                int left = 0, right = t.size();
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (t[mid] < nums[i]) left = mid + 1;
                    else right = mid;
                }
                ans[i] = right;
                t.insert(t.begin() + right, nums[i]);
            }
            return ans;
        }
};
