/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. */
#include "header.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out;
        unordered_map<int, int> map;
        int i = 0;
        for (auto &x : nums) {
            if (map.find(target-x) != map.end()) {
                out.emplace_back(map[target-x]);
                out.emplace_back(i);
                break;
            }
            map[x] = i;
            ++i;
        }

        return out;
    }
};
