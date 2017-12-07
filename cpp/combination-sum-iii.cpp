/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/

/* O(C(n,k)), O(k) */
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        tmp_res.clear();
        combinationSum_recur(1, k, n);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> tmp_res;
    void combinationSum_recur(int start, int k, int n) {
        if (k==0 && n==0) {
            res.emplace_back(tmp_res);
            return;
        }
        else if (k==0) {
            return;
        }

        for (int i=start; i<10; ++i) {
            if (k>0 && n-i >= 0) {
                tmp_res.emplace_back(i);
                combinationSum_recur(i+1, k-1, n-i);
                tmp_res.pop_back();
            }
        }
    }
};
