/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
#include "header.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_cnt = 0;
        int last = 0;
        int i = 0;
        unordered_map<char, int> map;
        for (auto &c : s) {
            auto it = map.find(c);
            if (it != map.end()) {
                if (it->second >= last) {
                    max_cnt = max(max_cnt, i-last);
                    last = it->second + 1;
                }

                it -> second = i;

            } else {
                map.emplace(c, i);

            }

            ++i;
        }
        max_cnt = max(max_cnt, i-last);

        return max_cnt;
    }
};
