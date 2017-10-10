/*

Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        return long_sub_recur(s, 0, s.size(), k);
    }
private:
    int long_sub_recur(string &s, int start, int end, int k) {
        if (start >= end)
            return 0;

        vector<int> count(26, 0);
        for (int i=start; i<end; ++i) {
            ++count[s[i] - 'a'];
        }

        auto max_len = 0;
        for (int i=start, j; i<end; ) {
            while (i<end && count[s[i]-'a'] < k) {
                ++i;
            }
            j = i;
            while (j<end && count[s[j]-'a'] >= k) {
                ++j;
            }

            if (i == start && j == end)
                return j - i;

            max_len = max(max_len, long_sub_recur(s, i, j, k));

            i = j;
        }

        return max_len;
    }
};
