/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

/* O(k*C(n, k)), O(k) */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        res.clear();
        temp.clear();
        combinationSum_recur(candidates, target, 0);

        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> temp;
    void combinationSum_recur(vector<int>& candidates, int target, int indx) {
        if (target == 0)
            res.emplace_back(temp);

        auto prev = 0;
        while (indx < candidates.size() && candidates[indx] <= target) {
            if (prev != candidates[indx]) {
                temp.emplace_back(candidates[indx]);
                combinationSum_recur(candidates, target - candidates[indx], indx+1);
                temp.pop_back();
            }
            prev = candidates[indx];
            ++indx;
        }
    }
};
