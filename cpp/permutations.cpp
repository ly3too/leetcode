/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        tmp.clear();
        res.clear();
        permute_recur(nums);
        return res;
    }

private:
    vector<bool> visited;
    vector<int> tmp;
    vector<vector<int>> res;

    void permute_recur(vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            res.emplace_back(tmp);
        }

        for (int i=0; i < nums.size(); ++i) {
            if (visited[i])
                continue;
            tmp.emplace_back(nums[i]);
            visited[i] = true;
            permute_recur(nums);
            visited[i] = false;
            tmp.pop_back();
        }
    }
};
