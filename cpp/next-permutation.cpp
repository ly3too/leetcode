#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = static_cast<int>(nums.size());

        while ((--n) > 0) {
            if (nums[n] > nums[n-1])
                break;
        }
        --n;
        if (n < 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        auto num1 = nums[n];

        int m = static_cast<int>(nums.size());
        while ((--m) > 0) {
            if (nums[m] > num1)
                break;
        }

        swap(nums[n], nums[m]);
        ++n;
        sort(nums.begin() + n, nums.end());
        return;
    }
};

int main () {
    vector<int> input {1,3,2,3,2};
    // vector<int> input {-1, 0, 1};

    for (auto x : input) {
        cout << x << " ";
    }
    cout << endl;

    Solution s;
    s.nextPermutation(input);

    for (auto x : input) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
