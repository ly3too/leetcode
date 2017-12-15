/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

/* O(n^2), O(n^2) */
class Solution {
public:
    int minCut(string s) {
        auto len = s.size();
        vector<vector<bool>> lookup(len, vector<bool>(len, false));
        vector<int> min_cut(len+1);
        min_cut[len] = -1;
        for (int i = static_cast<int>(len)-1; i >= 0; --i) {
            min_cut[i] = len - i -1;
            for (int j=i; j < len; ++j) {
                if (s[i] == s[j] && (j-i < 2 || lookup[i+1][j-1])) {
                    lookup[i][j] = true;
                    min_cut[i] = min(min_cut[i], min_cut[j+1] + 1);
                }
            }
        }

        return min_cut[0];
    }
};
