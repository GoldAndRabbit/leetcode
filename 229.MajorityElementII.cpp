/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

个数超过n / 3的最多只有两个 (假若有3个那么总个数超过n)
第一遍遍历用moore voting筛选出两个候选的majority element
第二遍遍历统计这两个元素的出现次数
判断是否大于nums.size() / 3
*/

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int m = 0, n = 0, cntm = 0, cntn = 0;
            for (auto x : nums) {
                if (x == m) ++cntm;
                else if (x == n) ++cntn;
                else if (cntm == 0) {
                    m = x;
                    cntm = 1;
                } else if (cntn == 0) {
                    n = x;
                    cntn = 1;
                } else {
                    --cntm;
                    --cntn;
                }
            }
            cntm = 0, cntn = 0;
            for (auto x : nums) {
                if (x == m) ++cntm;
                else if (x == n) ++cntn;
            }
            vector<int> ans;
            if (cntm > nums.size() / 3) ans.push_back(m);
            if (cntn > nums.size() / 3) ans.push_back(n);
            return ans;
        }
};
