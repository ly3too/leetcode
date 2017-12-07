/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/
/* O(2^(n/l)), O(n*l) */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        res.clear();
        n = s.size();
        if (n < 1)
            return res;

        unordered_set<string> dict;
        max_len = 0;
        for (auto &str : wordDict) {
            max_len = max(max_len, static_cast<int>(str.size()));
            dict.insert(str);
        }

        is_valid = vector<vector<bool>>(n, vector<bool>(max_len, false));
        vector<bool> can_break(n+1, false);
        can_break[0] = true;
        for (int i=0; i<n; ++i) {
            for (int l=1; l<=max_len; ++l) {
                if (i+l <= n && dict.find(s.substr(i,l)) != dict.end() && can_break[i]) {
                    is_valid[i][l-1] = true;
                    can_break[i+l] = true;
                }
            }
        }

        path.clear();
        if (can_break[n])
            wordBreak_recur(s, 0);

        return res;
    }
private:
    int max_len;
    int n;
    vector<vector<bool>> is_valid;
    vector<string> res;
    vector<string> path;
    void wordBreak_recur(string &s, int indx) {
        if (indx == n) {
            string tmp;
            for (int i=0; i+1<path.size(); ++i) {
                tmp += path[i];
                tmp += " ";
            }
            tmp += path.back();
            res.emplace_back(move(tmp));
        }

        for (int l = 1; l <= max_len; ++l) {
            if (indx + l <= n && is_valid[indx][l-1]) {
                path.emplace_back(s.substr(indx, l));
                wordBreak_recur(s, indx+l);
                path.pop_back();
            }
        }
    }
};
