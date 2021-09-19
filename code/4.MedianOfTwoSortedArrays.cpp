/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int getKth(int k, vector<int> nums1, vector<int> nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) return getKth(k, nums2, nums1);
        if (m == 0) return nums2[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);
        int i = min(m, k >> 1), j = min(n, k >> 1);
        if (nums1[i - 1] > nums2[j - 1]) 
            return getKth(k - j, nums1, vector<int>(nums2.begin() + j, nums2.end()));
        else
            return getKth(k - i, vector<int>(nums1.begin() + i, nums1.end()), nums2);
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        return (getKth((m + n + 1) >> 1, nums1, nums2) + getKth((m + n + 2) >> 1, nums1, nums2)) / 2.0;
    }
};

