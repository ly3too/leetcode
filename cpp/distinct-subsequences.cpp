/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

/* dp solution
dp[i][j] means the count of T[0:i-1] matchs S[0:j-1];
dp[0][j] = 1; empty T matches once of S[0:j-1]
dp[i][j] = dp[i][j-1] + (T[i-1] == S[j-1] ? dp[i-1][j-1] : 0);
*/
/* O(m*n), O(m) */
class Solution {
public:
    int numDistinct(string s, string t) {
        auto ns = s.size();
        auto nt = t.size();
        if (nt > ns)
            return 0;
        vector<int> dp(ns+1, 1);
        for (int i=1; i <= nt; ++i) {
            auto prev = dp[0]; // prev = d[i-1][j-1]
            dp[0] = 0;
            for (int j=1; j <= ns; ++j) {
                auto cur = dp[j-1];
                if (s[j-1] == t[i-1]) {
                    cur += prev;
                }
                prev = dp[j];
                dp[j] = cur;
            }
        }

        return dp[ns];
    }
};
