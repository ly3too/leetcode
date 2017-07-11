/* Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = 0;
        int size = static_cast<int>(nums.size());
        if (size == 0)
            return 1;

        while (nums[n] < 0 && n < size)
            ++n;

        if (n == size)
            return 1;

        int last_num = 0;
        while (n < size) {
            if (nums[n] - last_num > 1) {
                return last_num + 1;
            }
            last_num = nums[n];
            ++n;
        }

        return last_num + 1;
    }
};

int main () {
    vector<int> input {3,4,-1,1};
    // vector<int> input {-1, 0, 1};

    for (auto x : input) {
        cout << x << " ";
    }
    cout << endl;

    Solution s;
    auto n = s.firstMissingPositive(input);

    cout << n << endl;

    return 0;
}
