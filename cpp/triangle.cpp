/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

/* O(n^2), O(n) */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto m = triangle.size();
        if (m == 0)
            return 0;
        auto n = triangle[m-1].size();
        if (n == 0)
            return 0;

        vector<int> dp (n);
        dp[0] = triangle[0][0];
        auto min_sum = dp[0];
        for (int i=1; i<m; ++i) {
            auto last = dp[0] + triangle[i][0];
            for (int j=1; j < i; ++j) {
                auto cur = min(dp[j-1], dp[j]) + triangle[i][j];
                dp[j-1] = last;
                last = cur;
            }
            auto cur = dp[i-1] + triangle[i][i];
            dp[i-1] = last;
            dp[i] = cur;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
