/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        while (indx < candidates.size() && candidates[indx] <= target) {
            temp.emplace_back(candidates[indx]);
            combinationSum_recur(candidates, target - candidates[indx], indx);
            temp.pop_back();
            ++indx;
        }
    }
};
