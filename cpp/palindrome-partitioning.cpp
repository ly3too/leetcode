/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/
/* O(n^2 ~ 2^n), O(n^2)  */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        auto n = s.size();
        is_palindrome = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));

        for (int i=n-1; i>=0; --i) {
            for (int j=i; j<n; ++j) {
                if (s[i] == s[j] && ((j-i < 2) || (i<n-1 && j>0 && is_palindrome[i+1][j-1]))) {
                    is_palindrome[i][j] = true;
                    //cout << i << ", " << j << endl;
                }
            }
        }

        tmp_res.clear();
        partition_recur(s, 0);
        return res;
    }
private:
    vector<vector<bool>> is_palindrome;
    vector<vector<string>> res;
    vector<string> tmp_res;
    void partition_recur(string &s, int indx) {
        if (indx == s.size()) {
            res.emplace_back(tmp_res);
            return;
        }

        for (int i=indx+1; i<=s.size(); ++i) {
            if (is_palindrome[indx][i-1]) {
                tmp_res.emplace_back(s.substr(indx, i-indx));
                partition_recur(s, i);
                tmp_res.pop_back();
            }
        }

    }
};
