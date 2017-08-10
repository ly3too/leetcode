/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/
#include "header.hpp"

/* O(n), O(k) */
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size() || t.size() ==0) {
            return "";
        }

        unordered_map<char, int> exp_cnt;
        unordered_map<char, int> cur_cnt;

        for (auto &c : t) {
            if (exp_cnt.find(c) == exp_cnt.end()) {
                exp_cnt[c] = 1;
            } else {
                ++exp_cnt[c];
            }
            cur_cnt[c] = 0;
        }

        int start = 0;
        int min_start = 0;
        int min_len = numeric_limits<int>::max();

        int i = 0;
        int cnt = 0;
        for (auto &c : s) {
            auto it = exp_cnt.find(c);
            if (it != exp_cnt.end()) {
                ++ cur_cnt[c];
                if (cur_cnt[c] <= exp_cnt[c]) {
                    ++cnt;
                }
            }

            /* find one match */
            if (cnt == t.size()) {
                /*update start*/
                while (exp_cnt.find(s[start]) == exp_cnt.end() || cur_cnt[s[start]] > exp_cnt[s[start]]) {
                    if (exp_cnt.find(s[start]) != exp_cnt.end())
                        --cur_cnt[s[start]];
                    ++start;
                }

                if (min_len > i-start+1) {
                    min_len = i-start+1;
                    min_start = start;
                }

                --cnt;
                --cur_cnt[s[start]];
                ++start;
            }

            ++i;
        }

        if (min_len == numeric_limits<int>::max()) {
            return "";
        }

        return s.substr(min_start, min_len);

    }
};
