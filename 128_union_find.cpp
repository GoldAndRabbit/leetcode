/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int x){
        if (parent[x] == x) {
           return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_find(int a, int b){
        int pa = find(pa);
        int pb = find(pb);
        if (pa != pb) {
           if (size[pa] < size[pb]) {
               parent[pa] = pb;
               size[pb] += size[pa];
           } else {
               parent[pb] = pa;
               size[pa] += size[pb];
           }
        }
        return;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        size = vector<int>(n, 1);
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
           if (record.find(nums[i]) != record.end()) {
               continue;
           }
           record[nums[i]] = i;
           if (record.find(nums[i] - 1) != record.end()) {
               union_find(i, record[nums[i] - 1]);
           }
           if (record.find(nums[i] + 1) != record.end()) {
               union_find(i, record[nums[i] + 1]);
           }
        }
        int ans = *max_element(size.begin(), size.end());
        return ans;
    }
};
