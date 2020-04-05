/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/*
思路：
对所有的区间按照start排序
然后遍历vector
对第i个：
   ans.pb(intervals[0])
   if ans.back.end < i.end:
      pb i
   else:
      ans.back.end = max(ans.back.end, i.end)
*/

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        static bool cmp(const Interval& a, const Interval& b) {
            return a.start < b.start;
        }
        vector<Interval> merge(vector<Interval>& intervals) {
            vector<Interval> ans;
            if (intervals.empty())
                return ans;
            sort(intervals.begin(), intervals.end(), cmp);
            ans.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); i++) {
                if (ans.back().end < intervals[i].start) {
                    ans.push_back(intervals[i]);
                } else {
                    ans.back().end = max(ans.back().end, intervals[i].end);
                }
            }
            return ans;
        }
};
