/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
*/

/* O(m*n), O(n) */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        auto M = dungeon.size();
        if (M == 0)
            return 1;
        auto N = dungeon[0].size();
        vector<int> dp(N, numeric_limits<int>::max());
        dp[N-1] = 1;

        for (int i = M-1; i >= 0; --i) {
            dp[N-1] = max(1, dp[N-1] - dungeon[i][N-1]);
            for (int j = N-2; j >= 0; --j) {
                dp[j] = max(min(dp[j], dp[j+1]) - dungeon[i][j], 1);
            }
        }
        return dp[0];
    }
};
