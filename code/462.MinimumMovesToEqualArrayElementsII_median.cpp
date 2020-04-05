/*
 *
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 */

/*
 *
 * Suppose we have a set S of real numbers. Show that
 * ∑s∈ S|s−x|
 * ∑s∈ S|s−x|
 * is minimal if xx is equal to the median.
 */

class Solution {
    public:
        int minMoves2(vector<int>& nums) {
            int ans = 0;
            sort(nums.begin(), nums.end());
            int len = nums.size();
            int mid = ((len & 1) == 1) ? nums[len >> 1] : (nums[len >> 1] + nums[(len >> 1) - 1]) >> 1;
            for (int i = 0; i < len; i++) {
                ans += abs(mid - nums[i]);
            }
            return ans;
        }
};