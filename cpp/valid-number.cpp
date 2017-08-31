/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
*/

/* regular expression very slow */
class Solution {
public:
    bool isNumber(string s) {
        regex e(R"(^\s*[\+\-]?((\d+(\.\d*)?)|\.\d+)([eE][\+\-]?\d+)?\s*$)");
        return regex_match(s, e);
    }
};

/* state machine O(n) */
class Solution {
public:
    bool isNumber(string s) {
        enum State:int {
            invalid = 0,
            space, //1 soace before number
            sign, //2
            digit, //3
            dot, //4
            expon //5
        };
        /*
        state :
        -1 : invalid
        0 : pre_space
        1 : suf_space
        2 : base_sign
        3 : base_int
        4 : pure_dot
        5 : base_frac
        6 : e_sign
        7 : exp
        8 : e_digit
        */
        const vector<vector<int>> state_table {
            {-1, 0, 2, 3, 4, -1}, //state 0, for initial and prespace
            {-1, 1, -1, -1, -1, -1}, //state 1, for suf_space
            {-1, -1, -1, 3, 4, -1}, //state 2, for base_sign
            {-1, 1, -1, 3, 5, 7}, //state 3, for base_int
            {-1, -1, -1, 5, -1, -1}, //state 4, for pure_dot
            {-1, 1, -1, 5, -1, 7}, //state 5, for base_frac
            {-1, -1, -1, 8, -1, -1}, //state 6, for e_sign
            {-1, -1, 6, 8, -1, -1}, //state 7, for exp
            {-1, 1, -1, 8, -1, -1} //state 8, for e_digit
        };

        int state = 0;
        for (auto &ch : s) {
            int input = State::invalid;
            if (ch == ' ') {
                input = State::space;
            } else if (ch == '-' || ch == '+') {
                input = State::sign;
            } else if (ch >= '0' && ch <= '9') {
                input = State::digit;
            } else if (ch == '.') {
                input = State::dot;
            } else if (ch == 'e' || ch == 'E') {
                input = State::expon;
            }

            state = state_table[state][input];
            if (state == -1) {
                return false;
            }
        }

        if (state == 1 || state == 3 || state == 5 || state == 8) {
            return true;
        } else {
            return false;
        }

    }
};

/* simple solution O(n) */
class Solution {
public:
    bool isNumber(string s) {
        bool valid = false;
        int index = 0;

        index = skip_space(s, index);

        tie(valid, index) = find_signed(s, index);

        if (index < s.size() && s[index] == '.') {
            ++index;
            bool found;
            tie(found, index) = find_unsigned(s, index);

            // either signed before '.' or unsigned after '.' should be a valid number
            valid = valid || found;
        }

        if (valid && index < s.size() && (s[index] == 'e' || s[index] == 'E')) {
            ++ index;
            bool found;
            tie(found, index) = find_signed(s, index);
            valid = valid && found;
        }

        index = skip_space(s, index);

        return (index == s.size() && valid);
    }

private:
    int skip_space(const string &s, int idx) {
        while (idx < s.size() && s[idx]==' ') {
            ++idx;
        }

        return idx;
    }

    /* the question testing set sucks */
    tuple<bool, int> find_signed(const string &s, int idx) {
        if (idx >= s.size()) {
            return {false, idx};
        }

        if (s[idx] == '-' || s[idx] == '+') {
            ++idx;
        }

        return find_unsigned(s, idx);
    }

    tuple<bool, int> find_unsigned(const string &s, int idx) {
        bool found = false;
        while (idx < s.size() && (s[idx] >= '0' && s[idx] <= '9')) {
            ++idx;
            found = true;
        }

        return {found, idx};
    }
};
