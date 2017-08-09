/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
#include "header.hpp"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> words_cnt;
        vector<int> res;
        const auto N = words[0].size();
        const auto cat_N = words.size() * N;

        if (s.size() < cat_N) {
            return res;
        }

        for (auto &s : words) {
            if (words_cnt.find(s) == words_cnt.end())
                words_cnt[s] = 1;
            else
                ++words_cnt[s];
        }

        for (int i=0; i<=(s.size()-cat_N); ++i) {
            auto tmp_cnt = words_cnt;
            for (int j=i; j<i+cat_N; j+=N) {
                auto it = tmp_cnt.find(s.substr(j, N));
                if (it != tmp_cnt.end()) {
                    --(it -> second);
                    if (it -> second <= 0) {
                        tmp_cnt.erase(it);
                    }
                } else {
                    break;
                }
            }

            if (tmp_cnt.empty()) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};
