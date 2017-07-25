/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <list>
#include "print_container.hpp"

using namespace std;

/* using Ascending stack O(n), O(n) */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        auto N = heights.size();
        if (N < 1)
            return 0;

        int max_size = 0;
        stack<int> ind;
        int i;
        for (i=0; i<N; ++i) {
            if (ind.empty() || heights[ind.top()] <= heights[i] ) {
                ind.push(i);
                // cout << "top: " << ind.top() << endl;
            } else {
                while (!ind.empty() && heights[ind.top()] > heights[i]) {
                    // cout << "top: " << ind.top() << endl;
                    auto top = ind.top();
                    ind.pop();

                    max_size = max(max_size, heights[top] * (ind.empty() ? i : i-ind.top()-1));
                }
                ind.push(i);
            }
            // cout << "i=" << i << " max_size:" << max_size << endl;
        }
        while (!ind.empty()) {
            // cout << "top: " << ind.top() << endl;
            auto top = ind.top();
            ind.pop();

            max_size = max(max_size, heights[top] * (ind.empty()? i : i-ind.top()-1));
        }

        return max_size;
    }
};

int main() {
    vector<vector<int>> iv;
    iv.push_back({0,1,2,3,4});
    iv.push_back({6, 2, 5, 4, 5, 1, 6});
    iv.push_back({});

    for (auto &x : iv) {
        cout << x;
        cout << " -> " << Solution{}.largestRectangleArea(x) << endl;
    }

    return 0;
}
