/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

/* recursion solution */
/* O(n^3), O(n) */
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        return isScramble_recur(s1, s2);
    }
private:
    bool isScramble_recur(string &s1, string &s2) {
        if (s1 == s2)
            return true;
        auto len = s1.size();

        int cnt[26] = {0};
        for (int i=0; i<len; ++i) {
            ++cnt[s1[i] - 'a'];
            --cnt[s2[i] - 'a'];
        }
        for (int i=0; i<26; ++i) {
            if (cnt[i])
                return false;
        }

        for (int i = 1; i < len; ++i) {
            if (isScramble_recur(s1.substr(0, i), s2.substr(0, i)) && isScramble_recur(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble_recur(s1.substr(0, i), s2.substr(len - i)) && isScramble_recur(s1.substr(i), s2.substr(0, len - i)))
                return true;
        }
        return false;
    }
    bool isScramble_recur(string &&s1, string &&s2) {
        return isScramble_recur(s1, s2);
    }
};

/* dp solution:
dp[i][j][k] = s1.substr(i, k) and s2.substr(j, k) is scramble
dp[i][j][1] = s1[i] == s2[j];
dp[i][j][k] = for 1 <= q < k: dp[i][j][q] && dp[i+q][j+q][k-q] || dp[i][j+k-q][q] && dp[i+q][j][k-q]
*/
/* O(n^4), O(n^3) */
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        if (s1.size() != s2.size())
            return false;

        auto len = s1.size();
        int cnt[26] = {0};
        for (int i=0; i<len; ++i) {
            ++cnt[s1[i] - 'a'];
            --cnt[s2[i] - 'a'];
        }
        for (int i=0; i<26; ++i) {
            if (cnt[i])
                return false;
        }

        vector<vector<vector<bool>>> dp(len, vector<vector<bool>>(len, vector<bool>(len+1)));
        for (int i=0; i < len; ++i) {
            for (int j=0; j < len; ++j) {
                    dp[i][j][1] = s1[i] == s2[j];
            }
        }
        for (int k=2; k <= len; ++k) {
            for (int i=0; i+k <= len; ++i) {
                for (int j=0; j+k <= len; ++j) {
                    for (int q=1; q < k && !dp[i][j][k]; ++q) {
                        dp[i][j][k] = (dp[i][j][q] && dp[i+q][j+q][k-q] || dp[i][j+k-q][q] && dp[i+q][j][k-q]);
                    }
                }
            }
        }

        return dp[0][0][len];
    }
};
