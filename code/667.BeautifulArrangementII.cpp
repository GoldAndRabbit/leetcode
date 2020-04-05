/*
Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement:
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Example 1:
Input: n = 3, k = 1
Output: [1, 2, 3]
Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
Example 2:
Input: n = 3, k = 2
Output: [1, 3, 2]
Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
Note:
The n and k are in the range 1 <= k < n <= 104.

给定数字n和k 构造一个包括n个值的数组从1到n，满足以下要求
相邻两个数字的绝对值之差恰好有k个不同的值

举例当n == 8的时候
k最小等于1       1,2,3,4,5,6,7,8
k最大等于7       1,8,2,7,3,6,4,5
因此产生一个为特定k的数组的方法是,先依次按照最小最大的方法往下排,同时--k,当k减到1的时候，再按照自然顺序排列
*/

class Solution {
    public:
        vector<int> constructArray(int n, int k) {
            vector<int> ans;
            int low = 1, high = n;
            while (low <= high) {
                if (k > 1) ans.push_back(k-- % 2 == 1 ? low++ : high--);
                else ans.push_back(low++);
            }
            return ans;
        }
};

