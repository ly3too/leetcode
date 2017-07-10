/* Given an array S of n integers, are there elements a, b, c
 in S such that a + b + c = 0? Find all unique triplets in the
 array which gives the sum of zero.
*/
/*
 * time O(N^2), space O(1)
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // first sort nums
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int indx = 0;
        while ((indx + 2) < nums.size()) {
            if (nums[indx] > 0)
                break;

            int begin = indx + 1;
            int end = nums.size() - 1;
            int temp = -nums[indx];

            do {
                int x = nums[begin];
                int y = nums[end];
                if (x + y < temp) {
                    ++begin;
                } else if (x + y > temp) {
                    --end;
                } else {
                    // find one !
                    vector<int> arr {nums[indx], x, y};
                    result.push_back(arr);

                    // skip redundant ones
                    while (x == nums[begin] && begin < end)
                        ++begin;
                }

            } while (begin < end);

            // skip redundant ones
            do {
                ++indx;
            } while (indx + 2 < nums.size() && nums[indx-1] == nums[indx]) ;
        }

        return result;
    }
};

int main () {
    // vector<int> input {-1, -1, -1, 0, 1, 1, 1, 2, 2, 2};
    vector<int> input {-1, 0, 1};

    Solution s;
    auto output = s.threeSum(input);

    for (auto x : output) {
        cout << "[ ";
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "] " << endl;
    }

    return 0;
}
