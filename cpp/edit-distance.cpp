/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

/* dp[i][j] represent steps conver word1[0:i-1] to word2[0:j-1], dp[0][j] means to convert empty string to word2[j-1],
1. do nothing with word1[i - 1]: dp[i][j] = dp[i - 1][j - 1];
2. Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
3. Delete word1[i - 1] and word1[0..i - 2] = word2[0..j - 1] (dp[i][j] = dp[i - 1][j] + 1 (for deletion));
4. Insert word2[j - 1] to word1[0..i - 1] and word1[0..i - 1] + word2[j - 1] = word2[0..j - 1] (dp[i][j] = dp[i][j - 1] + 1 (for insertion)).
 */

/* O(m*n), O(m*n) */
 class Solution {
 public:
     int minDistance(string word1, string word2) {
         auto m = word1.size();
         auto n = word2.size();
         vector<vector<int>> dp(m+1, vector<int>(n+1));
         for (int i=1; i <= m; ++i) {
             dp[i][0] = i;
         }
         for (int j=1; j <= n; ++j) {
             dp[0][j] = j;
         }

         for (int i=1; i <= m; ++i) {
             for (int j=1; j <= n; ++j) {
                 if (word1[i-1] == word2[j-1]) {
                     dp[i][j] = dp[i-1][j-1];
                 } else {
                     dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                 }
             }
         }

         return dp[m][n];
     }
 };

/* O(m*n), O(min(n,m)) */
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size())
            return minDistance_help(word2, word1);
        else
            return minDistance_help(word1, word2);
    }

private:
    int minDistance_help(string word1, string word2) {
        auto m = word1.size();
        auto n = word2.size();

        vector<int> dp(n+1);
        for (int j=1; j <= n; ++j)
            dp[j] = j;

        for (int i=1; i <= m; ++i) {
            auto prev = dp[0]; // prev = dp[i-1][j-1]
            dp[0] = i;
            for (int j=1; j <= n; ++j) {
                auto tmp = dp[j];  // before update dp[j], tmp is dp[i-1][j-1]
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(prev + 1, min(dp[j] + 1, dp[j - 1] + 1));
                }
                prev = tmp;
            }
        }

        return dp[n];
    }
};
