/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
*/

#include "header.hpp"

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> lookup;
        vector<vector<int>> res;
        int i = 0;
        for (auto &word : words) {
            lookup[word] = i;
            ++i;
        }

        for (i=0; i<words.size(); ++i) {
            for (int j=0; j<=words[i].size(); ++j) {

                if (is_palindrome(words[i], j, words[i].size()-1)) {
                    auto prefix = words[i].substr(0, j);
                    reverse(prefix.begin(), prefix.end());
                    if (lookup.find(prefix) != lookup.end() && lookup[prefix] != i) {
                        res.push_back({i, lookup[prefix]});
                    }
                }

                if (j>0 && is_palindrome(words[i], 0, j-1)) {
                    auto sufix = words[i].substr(j);
                    reverse(sufix.begin(), sufix.end());
                    if (lookup.find(sufix) != lookup.end() && lookup[sufix] != i) {
                        res.push_back({lookup[sufix], i});
                    }
                }
            }
        }

        return res;
    }

private:
    bool is_palindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }
};
