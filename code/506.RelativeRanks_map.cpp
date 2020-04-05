/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.

利用map记录num -> index的映射
由于map是根据key升序排序的，可以根据对map逆序的遍历,
依次增加名次
*/

class Solution {
    public:
        vector<string> findRelativeRanks(vector<int>& nums) {
            int n = nums.size();
            vector<string> (n, "");
            // 利用map为每个数字标记一个index, 并且天然对数字按照key排序
            map<int, int> hash;
            for (int i = 0; i < n; i++) {
                hash[nums[i]] = i;
            }
            int cnt = 1;
            // 反向遍历map
            for (auto it = hash.rbegin(); it != hash.rend(); ++it) {
                if (cnt == 1) ans[it -> second] = "Gold Medal";
                else if (cnt == 2) ans[it -> second] = "Silver Medal";
                else if (cnt == 3) ans[it -> second] = "Bronze Medal";
                else ans[it -> second] = to_string(cnt);
                ++cnt;
            }
            return ans;
        }
};
