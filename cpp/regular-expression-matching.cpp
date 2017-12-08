/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

/* O(m*n) O(n)*/
class Solution {
public:
    bool isMatch(string s, string p) {
        ns = s.size();
        np = p.size();
        s_ = move(s);
        p_ = move(p);
        return isMatch_recur(0, 0);
    }
private:
    int ns;
    int np;
    string s_;
    string p_;
    bool isMatch_recur(int is, int ip) {
        if (ip == np)
            return is == ns;

        // matching . or one ch
        if (np - ip == 1 || p_[ip+1] != '*') {
            if (is < ns && (s_[is] == p_[ip] || p_[ip] == '.')) {
                return isMatch_recur(is+1, ip+1);
            } else {
                return false;
            }
        }

        // matching a* or .*
        while (is != ns && (s_[is] == p_[ip] || p_[ip] == '.')) {
            if (isMatch_recur(is, ip+2))
                return true;
            ++ is;
        }
        return isMatch_recur(is, ip+2);
    }
};
