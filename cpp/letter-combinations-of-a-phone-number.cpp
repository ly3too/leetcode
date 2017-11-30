/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

/* O(4^n) */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        return letterCombinations_recur(digits, 0);
    }

private:
    vector<string> letterCombinations_recur(string &digits, int idx) {
        const static vector<string> lookup {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;

        if (idx >= digits.size()) {
            return res;
        }

        vector<string> prefix;
        for (auto ch : lookup[digits[idx]-'0']) {
            prefix.emplace_back(string{""} + ch);
        }

        if (idx+1 < digits.size()) {
            auto sufix = letterCombinations_recur(digits, idx+1);
            for (auto &pref : prefix) {
                for (auto &suf : sufix) {
                    res.emplace_back(pref + suf);
                }
            }
            return res;

        } else {
            return prefix;
        }
    }
};
