/*
Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:
You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
Example 1:
Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.
Example 2:
Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
Example 3:
Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.


思路
unordered_map记录start的位置,start依次放入一个vector并且降序排序,
遍历intervals
    遍历start,
        int i = 0
        如果第i个start < intervals.end:
            break;
        i 如果有变动，那么之前的一个idx就是结果
优化:
map记录start的位置，map按照key天然排序，用upper_bound找第一个大于等于end的位置
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        unordered_map<int, int> m;
        vector<int> s, ans(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); ++i) {
            s.push_back(intervals[i].start);
            m[intervals[i].start] = i;
        }
        sort(s.begin(), s.end(), greater<int>());
        for (int i = 0; i < intervals.size(); ++i) {
            int j = 0;
            for (; j < s.size(); ++j) {
                if (s[j] < intervals[i].end) break;
            }
            if (j > 0) ans[i] = m[s[j - 1]];
        }
        return ans;
    }
};
