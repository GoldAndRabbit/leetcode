/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.


有环状的N个加油站
每个加油站有gas[i]油
你的车油箱不限量
cost表示从i到i+1个加油站的油耗
刚开始从某个加油站开始没有油

如果能绕一圈那么返回初始加油站的index 否则返回-1

思路：如果能顺利返回有两个条件
1.total Gas >= total Cost
2.任何时间 cur Gas > 0, 若Gas < 0了,起始位置设为下一个点
a到不了b, 那么ab之间任何都到不了b，


有个数学定理：如果一个数组全部的和非负，那么至少找到一个起始位置能绕一圈非负
*/


class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int start = 0, total = 0, cur = 0;
            for (int i = 0; i < gas.size(); ++i) {
                cur += gas[i] - cost[i];
                total += gas[i] - cost[i];
                if (cur < 0) {
                    start = i + 1;
                    cur = 0;
                }
            }
            return total < 0 ? -1 : start;
        }
};
