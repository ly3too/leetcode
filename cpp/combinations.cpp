/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        tmp_res = vector<int>(k);
        k_ = k;
        n_ = n;

        combine_recur(0, 1);
        return res;
    }
private:
    vector<int> tmp_res;
    vector<vector<int>> res;
    int k_;
    int n_;
    void combine_recur(int indx, int start) {
        if (indx >= k_) {
            res.emplace_back(tmp_res);
            return;
        }
        for (int i=start; i <= n_; ++i) {
            tmp_res[indx] = i;
            combine_recur(indx+1, i+1);
        }
    }
};
