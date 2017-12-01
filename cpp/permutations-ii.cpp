/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        tmp.clear();
        res.clear();
        sort(nums.begin(), nums.end());
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

            //skip duplicates
            while (i+1 < nums.size() && nums[i] == nums[i+1]) {
                ++i;
            }
        }
    }
};
