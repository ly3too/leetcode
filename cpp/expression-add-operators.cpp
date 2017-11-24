/*
Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

/*O(4^n), O(n)*/
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        res_.clear();
        target_ = target;

        for (int i=1; i<=num.size(); ++i) {
            auto cur_str = num.substr(0, i);
            auto cur_val = stol(cur_str);

            //skip "000"
            if (to_string(cur_val).size() != cur_str.size())
                break;

            addOperators_DFS(num, i, cur_str, cur_val, cur_val, '#');
        }

        return res_;
    }

private:
    vector<string> res_;
    int target_;
    void addOperators_DFS(string &num, int pos, string expr, long cum_val, long prev_val, char prev_op) {
        if (pos == num.size() && cum_val == target_) {
            res_.emplace_back(expr);
        }
        for (int i=pos+1; i<=num.size(); ++i) {
            auto cur_str = num.substr(pos, i-pos);
            auto cur_val = stol(cur_str);

            //skip "000"
            if (to_string(cur_val).size() != cur_str.size())
                break;

            //case *, orev_op can only be +/-/#, no *
            if (prev_op == '+')
                addOperators_DFS(num, i, expr + '*' + cur_str, cum_val-prev_val+prev_val*cur_val, prev_val*cur_val, prev_op);
            else if (prev_op == '-')
                addOperators_DFS(num, i, expr + '*' + cur_str, cum_val+prev_val-prev_val*cur_val, prev_val*cur_val, prev_op);
            else
                addOperators_DFS(num, i, expr + '*' + cur_str, prev_val*cur_val, prev_val*cur_val, prev_op);
            //case +
            addOperators_DFS(num, i, expr + '+' + cur_str, cum_val+cur_val, cur_val, '+');
            //case -
            addOperators_DFS(num, i, expr + '-' + cur_str, cum_val-cur_val, cur_val, '-');
        }
    }
};
