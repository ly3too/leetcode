/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

/* O(n*l^2), O(n) */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        auto n = s.size();
        vector<bool> can_break(n+1, false);
        can_break[0] = true;
        auto max_len = 0;
        for (auto &word : wordDict) {
            max_len = max(max_len, static_cast<int>(word.size()));
        }

        for (int i=1; i <= n; ++i) {
            for (int l=1; l <= max_len && i >= l; ++l) {
                if (can_break[i-l] && dict.count(s.substr(i-l, l))) {
                    can_break[i] = true;
                }
            }
        }

        return can_break[n];
    }
};
