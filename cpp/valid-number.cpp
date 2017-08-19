/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
*/

class Solution {
public:
    bool isNumber(string s) {
        regex e(R"(^\s*[\+\-]?((\d+(\.\d*)?)|\.\d+)([eE][\+\-]?\d+)?\s*$)");
        return regex_match(s, e);
    }
};
