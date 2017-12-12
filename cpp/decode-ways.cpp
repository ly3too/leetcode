/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

/* O(n), O(n) */
class Solution {
public:
    int numDecodings(string s) {
        auto len = s.size();
        if (len == 0)
            return 0;

        vector<int> dp(len, 0);
        dp[0] = (s[0] == '0' ? 0 : 1);
        for (int i=1; i<len; ++i) {
            dp[i] = (s[i] == '0' ? 0 : dp[i-1]);
            if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6') {
                if (i >= 2)
                    dp[i] += dp[i-2];
                else
                    dp[i] += 1;
            }
        }
        return dp[len-1];
    }
};

/* O(n), O(1) */
class Solution {
public:
    int numDecodings(string s) {
        auto len = s.size();
        if (len == 0 || s[0] == '0')
            return 0;

        auto prev = 1;
        auto prev_prev = 1;

        for (int i=1; i<len; ++i) {
            auto cur = 0;
            if (s[i] != '0')
                cur += prev;
            if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6') {
                cur += prev_prev;
            }
            prev_prev = prev;
            prev = cur;
        }
        return prev;
    }
};
