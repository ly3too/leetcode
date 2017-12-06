/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        int last_idx = 0;

        for (int i=0; i<nums.size(); ++i) {
            auto size = res.size();

            auto start = 0;
            if (i>0 && nums[i] == nums[i-1])
                start = last_idx;

            for (int j=start; j<size; ++j) {
                res.emplace_back(res[j]);
                res.back().emplace_back(nums[i]);
            }
            
            last_idx = size;
        }

        return res;
    }
};
