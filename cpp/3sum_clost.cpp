#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int indx = 0;
        int clost_sum = numeric_limits<int>::max();
        int min_abs = numeric_limits<int>::max();

        while ((indx + 2) < nums.size()) {
            auto x = nums[indx];

            auto begin = indx + 1;
            auto end = nums.size() - 1;

            do {
                auto sum = x + nums[begin] + nums[end];
                if (sum < target) {
                    ++begin;
                } else if (sum > target) {
                    --end;
                } else {
                    // exactly
                    return target;
                }

                auto this_abs = abs(sum - target);
                if ( this_abs < min_abs) {
                    min_abs = this_abs;
                    clost_sum = sum;
                }

            } while (begin < end);

            // skip redundant ones
            do {
                ++indx;
            } while (indx + 2 < nums.size() && nums[indx-1] == nums[indx]) ;
        }

        return clost_sum;
    }

};


int main () {
    vector<int> input {-1, -1, -1, 0, 1, 1, 1, 2, 2, 2};
    // vector<int> input {-1, 0, 1};

    Solution s;
    auto output = s.threeSumClosest(input, -4);
    cout << "this size of Solution is: " << sizeof(s) << " size of int: " << sizeof(int) << endl;

    cout << output << endl;

    return 0;
}
