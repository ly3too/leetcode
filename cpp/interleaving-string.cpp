/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.


*/

/* O(m*n), O(m*n) */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.size();
        n2 = s2.size();
        n3 = s3.size();
        if (n1 + n2 != n3)
            return false;
        if (n3 == 0)
            return true;

        invalid = vector<vector<bool>>(n1+1, vector<bool>(n2+1));
        return isInterleave_dfs(s1, s2, s3, 0, 0, 0);
    }
private:
    int n1;
    int n2;
    int n3;
    vector<vector<bool>> invalid;
    bool isInterleave_dfs(string& s1, string& s2, string& s3, int i, int j, int k) {
        if (invalid[i][j])
            return false;
        if (k == n3)
            return true;
        bool valid = i < n1 && s1[i] == s3[k] && isInterleave_dfs(s1, s2, s3, i+1, j, k+1) || \
            j < n2 && s2[j] == s3[k] && isInterleave_dfs(s1, s2, s3, i, j+1, k+1);
        if (!valid)
            invalid[i][j] = true;
        return valid;
    }
};

/* DF solution */
