/*
Given an array of integers with possible duplicates, randomly output the index of a given target number.
You can assume that the given target number must exist in the array.
Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.
*/

class Solution {
public:
    Solution(vector<int> nums) : nums_{move(nums)} {
        srand(time(0));
    }

    int pick(int target) {
        int n = 0;
        int res = -1;
        int indx = 0;

        for (const auto &x : nums_) {
            if (x == target) {
                ++n;
                if (rand() % n == 0) {
                    res = indx;
                }
            }

            ++indx;
        }

        return res;
    }
private:
    vector<int> nums_;
};
