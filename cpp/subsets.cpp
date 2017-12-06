/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/* dynamic programing*/
/* O(2^n), O(1) */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);

        for (auto num : nums) {
            auto size = res.size();
            for (int i=0; i<size; ++i) {
                res.emplace_back(res[i]);
                res.back().emplace_back(num);
            }
        }

        return res;
    }
};
