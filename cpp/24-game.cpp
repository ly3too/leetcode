/*
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator.
For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
*/

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> nums_d (nums.begin(), nums.end());
        return judgePoint24_recur(nums_d);
    }
private:
    bool judgePoint24_recur(vector<double>& nums) {
        if (nums.size() == 1 ) {
            return abs(nums[0] - 24) < 1e-6;
        }

        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                vector<double> next_nums;
                for (int k=0; k<nums.size(); ++k) {
                    if (k != i && k != j)
                        next_nums.emplace_back(nums[k]);
                }

                for (int k=0; k<6; ++k) {
                    bool skip = false;
                    switch (k) {
                    case 0: //'+'
                        next_nums.emplace_back(nums[i] + nums[j]);
                        break;
                    case 1: // i-j
                        next_nums.emplace_back(nums[i] - nums[j]);
                        break;
                    case 2: // j-i
                        next_nums.emplace_back(nums[j] - nums[i]);
                        break;
                    case 3: // i*j
                        next_nums.emplace_back(nums[j] * nums[i]);
                        break;
                    case 4: // i/j
                        if (nums[j] == 0)
                            skip = true;
                        else
                            next_nums.emplace_back(nums[i] / nums[j]);
                        break;
                    case 5: // j/i
                        if (nums[i] == 0)
                            skip = true;
                        else
                            next_nums.emplace_back(nums[j] / nums[i]);
                        break;
                    default:
                        break;
                    }
                    if (skip)
                        continue;

                    if (judgePoint24_recur(next_nums))
                        return true;

                    next_nums.pop_back();
                }
            }
        }

        return false;
    }
};
