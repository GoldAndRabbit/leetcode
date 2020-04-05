/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

总共有m + n个元素
倒序遍历两个vector
同时遍历两个数组
从后往前添加元素
如果B中还有剩余元素
*/

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int cur = m + n - 1;
            int i = m - 1, j = n - 1;
            while (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) nums1[cur--] = nums1[i--];
                else nums1[cur--] = nums2[j--];
            }
            while (j >= 0)
                nums1[cur--] = nums2[j--];
        }
};
