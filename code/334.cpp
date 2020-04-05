/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

/*
 * 维护一个最小值和次小值。如果一个元素大于最小值且小于次小值。那么就存在连续3个递增的子序列
 */


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        for(int n : nums){
            if (n <= firstMin) {
               firstMin = n;
            } else if (n <= secondMin) {
               secondMin = n;
            } else {
               return true;
            }
        }
        return false;
    }
};
