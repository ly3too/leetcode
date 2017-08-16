/*
Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
*/

/* try out all set combinations, find if there are 4 subsets without overlape
and all elements are include, each sum equal to lenth of one side. use bit map to represent different combinations
O(2^n * n), O()*/
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        const int N = nums.size();
        const int ALL = (1<<N) - 1;
        int sum = 0;
        for (auto& x : nums) {
            sum += x;
        }

        if (sum % 4 || N < 4) {
            return false;
        }

        const int side_len = sum / 4;
        vector<int> subsets;
        unordered_map<int, bool> valid_half_subsets;

        for (int subset = 1; subset<=ALL; ++subset) {
            int sum = 0;
            for (int i=0; i<N; ++i) {
                if ((1<<i) & subset) {
                    sum += nums[i];
                }
            }

            if (sum == side_len) {
                for (auto &used_subset : subsets) {
                    if ((used_subset & subset) == 0) {
                        int valid_half_subset = used_subset | subset;
                        valid_half_subsets[valid_half_subset] = true;
                        if (valid_half_subsets.find(ALL^valid_half_subset) != valid_half_subsets.end()) {
                            return true;
                        }
                    }
                }

                subsets.emplace_back(subset);
            }
        }

        return false;
    }
};
