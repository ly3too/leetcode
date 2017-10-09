/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]
*/
/* O(n*(C(2n, n)-C(2n, n-1))), O(n*(C(2n, n)-C(2n, n-1))) */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if (input.empty())
            return {};
        return diffWaysToCompute(input, 0, input.size()-1);
    }
private:
    vector<int> diffWaysToCompute(string &input, int s, int e) {
        vector<int> res;
        for (int i=s; i<=e; ++i) {
            auto ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                auto left_res = diffWaysToCompute(input, s, i-1);
                auto right_res = diffWaysToCompute(input, i+1, e);

                for (auto &left : left_res) {
                    for (auto &right : right_res) {
                        if (ch == '+') {
                            res.emplace_back(left + right);
                        } else if (ch == '-') {
                            res.emplace_back(left - right);
                        } else {
                            res.emplace_back(left * right);
                        }
                    }
                }
            }
        }

        if (res.empty()) {
            res.emplace_back(stoi(input.substr(s, e-s+1)));
        }

        return res;
    }
};
