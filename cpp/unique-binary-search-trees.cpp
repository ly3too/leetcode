/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/* math */
/* O(n), O(1) */
class Solution {
public:
    int numTrees(int n) {
        //C(2n,n)/(n+1)
        long long ans =1;
        for(int i=n+1;i<=2*n;i++){
            ans = ans*i/(i-n);
        }
        return ans/(n+1);
    }
};

/* DP */
/* O(n^2), O(n) */
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        vector<int> dp(n+1, 1);
        for (int i=2; i<=n; ++i) {
            auto cnt = 0;
            for (int j=0; j<i; ++j) {
                cnt += dp[j] * dp[i-j-1];
            }
            dp[i] = cnt;
        }
        return dp[n];
    }
};
