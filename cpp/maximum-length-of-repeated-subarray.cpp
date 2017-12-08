/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation:
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/

/* O(m*n)  O(min(m, n))*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.size() < B.size())
            return findLength(B, A);
        vector<vector<int>> dp(2, vector<int>(B.size()+1));
        int res = 0;
        for (int i=0; i < A.size(); ++i) {
            for (int j=0; j < B.size(); ++j) {
                if (A[i] == B[j]) {
                    auto new_cnt = dp[i%2][j] + 1;
                    dp[(i+1)%2][j+1] = new_cnt;
                    res = max(res, new_cnt);
                } else {
                    dp[(i+1)%2][j+1] = 0;
                }
            }
        }

        return res;
    }
};
