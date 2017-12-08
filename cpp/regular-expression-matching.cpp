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

/* DP solution */
/* O(m*n) O(n)*/
class Solution {
public:
    bool isMatch(string s, string p) {
        auto ns = s.size();
        auto np = p.size();

        /* dp[i][j] == true meas s[i-1] matchs p[j-1] */
        vector<vector<bool>> dp(ns + 1, vector<bool>(np+1));
        dp[0][0] = true; // empty matchs empty;

        /* empty s matches p[j-1] iff p[j-1] == '*' && matchs p[j-2] */
        for (int j=2; j <= np; ++j) {
            dp[0][j] = dp[0][j-2] && p[j-1] == '*';
        }

        for (int i=1; i<=ns; ++i) {
            for (int j=1; j<=np; ++j) {
                // matches one ch
                if (p[j-1] != '*') {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');

                } else {
                    if (j >= 2) {
                        dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (p[j-2] == s[i-1] || p[j-2] == '.'));
                    }
                }
            }
        }

        return dp[ns][np];
    }
};
