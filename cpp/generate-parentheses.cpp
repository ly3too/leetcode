/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        max = n;
        generateParenthesis_recur("", 0, 0);
        return move(res);
    }
private:
    vector<string> res;
    int max;
    void generateParenthesis_recur(string str, int open, int close) {
        if (open == max && close == max) {
            res.emplace_back(str);
            return;
        }

        if (open < max) {
            generateParenthesis_recur(str+'(', open+1, close);
        }
        if (close < open) {
            generateParenthesis_recur(str+')', open, close+1);
        }
    }
};
