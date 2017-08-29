/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
*/

/* O(n), O(1) */
class Solution {
public:
    string originalDigits(string s) {
        const vector<string> numbers{"zero", "one", "two", "three",
                                    "four", "five", "six", "seven",
                                    "eight", "nine"};

        vector<vector<int>> dict_cnts(numbers.size(), vector<int>(26));
        int i = 0;
        for (const auto &s1 : numbers) {

            for (const auto &ch : s1) {
                ++dict_cnts[i][ch-'a'];
            }

            ++i;
        }

        vector<int> cnt(26);
        for (const auto &ch : s) {
            ++cnt[ch-'a'];
        }

        string res;

        // greedy algorithm, first pick out unique characters each number has and subtruct cnt with character numbers gotten,
        const vector<pair<char, int>> order{{'z', 0}, {'w', 2}, {'u', 4}, {'x', 6}, {'g', 8}, {'o', 1}, {'t', 3}, {'f', 5}, {'s', 7}, {'n', 9}};
        for (auto &pr : order) {
            while (cnt[pr.first-'a'] > 0) {
                for (int i=0; i<dict_cnts[pr.second].size(); ++i) {
                    cnt[i] -= dict_cnts[pr.second][i];
                }

                res += to_string(pr.second);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};
