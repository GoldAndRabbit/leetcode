/*
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
给定一对区间，删除其中几个使得区间区间没有重叠，求删除区间最少的数目
先对区间排序，
然后维护一个上一个区间的指针
如果当前区间和上一个区间有重叠
那么需要删除其中的一个
为了使得删除的最少，要删除end更大一些的区间
做法是将指针指向end较小的区间的end
*/

/*
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
*};
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
        static bool cmp(Interval& a, Interval& b) {
            return a.start == b.start ? a.end < b.end : a.start < b.start;
        }
        int eraseOverlapIntervals(vector<Interval>& intervals) {
            int len = intervals.size();
            int last = 0;
            int ans = 0;
            sort(intervals.begin(), intervals.end(), cmp);
            for (int i = 1; i < len; ++i) {
                if (intervals[i].start < intervals[last].end) {
                    ++ans;
                    if (intervals[i].end < intervals[last].end) {
                        last = i;
                    }
                } else {
                    last = i;
                }
            }
            return ans;
        }
};
