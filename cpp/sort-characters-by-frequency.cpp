/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"
*/

/* O(nlog(n)), O(k)*/
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> cnts(256, make_pair(0, 0));
        for (auto &c : s) {
            cnts[c].first = c;
            ++cnts[c].second;
        }

        auto cmp = [](const pair<char, int> &a, const pair<char, int> &b) {
            return b.second < a.second;
        };

        sort(cnts.begin(), cnts.end(), cmp);

        string res;
        for (auto &p : cnts) {
            if (p.second) {
                res += string(p.second, p.first);
            }
        }

        return res;
    }
};
