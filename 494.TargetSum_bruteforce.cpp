/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

/*
思路
dfs(i + 1, sum + nums[i])
dfs(i + 1, sum - nums[i]);
 */
class Solution {
    public:
        int cnt = 0;
        void dfs(int i, int sum, vector<int>& nums, int S){
            if (i == nums.size()) {
                if(sum == S)
                    cnt++;
            } else {
                dfs(i + 1, sum + nums[i], nums, S);
                dfs(i + 1, sum - nums[i], nums, S);
            }
            return;
        }
        int findTargetSumWays(vector<int>& nums, int S) {
            dfs(0, 0, nums, S);
            return cnt;
        }
};
