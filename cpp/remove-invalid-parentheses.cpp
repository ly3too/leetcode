/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

/* remove all invalid ')' first and then remove invalid '(' */
/* O(C(n, k)) O(k)*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        res.clear();
        string pair{"()"};
        removeInvalidParentheses_recur(s, 0, 0, pair);
        return res;
    }
private:
    vector<string> res;
    void removeInvalidParentheses_recur(string &s, int prev_i, int prev_j, string &pair) {
        int i=prev_i, stack = 0;
        for (; i<s.size(); ++i) {
            if (s[i] == pair[0])
                ++ stack;
            else if (s[i] == pair[1])
                -- stack;

            if (stack < 0)
                break;
        }

        // find one invalid pair[1] at i; remove one pair[1] from prev_j to i
        if (stack < 0) {
            for (int j=prev_j; j<=i; ++j) {
                // remove and skipp duplicated pair[1]
                if (s[j] == pair[1] && (j==prev_j || s[j-1] != pair[1])) {
                    auto new_str = s.substr(0,j)+s.substr(j+1, s.size()-j-1);
                    removeInvalidParentheses_recur(new_str, i, j, pair);
                }
            }

        // finished remove invalid pair[1]
        } else {
            auto reversed = s;
            reverse(reversed.begin(), reversed.end());
            if (pair[0] == '(') {
                string new_pair = ")(";
                removeInvalidParentheses_recur(reversed, 0, 0, new_pair);
            } else {
                res.emplace_back(reversed);
            }
        }
    }
};
