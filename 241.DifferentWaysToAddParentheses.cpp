/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

思路
递归左右拆分分别计算
有难度不会写。
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> l = diffWaysToCompute(input.substr(0, i));
                vector<int> r = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < l.size(); ++j) {
                    for (int k = 0; k < r.size(); ++k) {
                        if (input[i] == '+') ret.push_back(l[j] + r[k]);
                        else if (input[i] == '-') ret.push_back(l[j] - r[k]);
                        else ret.push_back(l[j] * r[k]);
                    }
                }
            }
        }
        if (ret.empty()) ret.push_back(stoi(input));
        return ret;
    }
};


