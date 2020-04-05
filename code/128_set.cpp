
class Solution {
    public:
        int longestConsecutive(vector<int> nums){
            int len = nums.size();
            if (len < 2)
                return len;
            unordered_set<int> record(nums.begin(), nums.end());
            int ans = 1;
            for (int n : nums) {
                if (record.find(n) == record.end())
                continue;
                record.erase(n);
                int next = n + 1;
                while (record.find(prev) != record.end()) record.erase(prev--);
                while (record.find(next) != record.end()) record.erase(next++);
                ans = max(ans, next-prev-1);
            }
            return ans;
        }
};
