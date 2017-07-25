/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <list>
#include "print_container.hpp"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int M = matrix.size();
        if (M < 1)
            return 0;
        int N = matrix[0].size();

        //vector<vector<int>> mat2(M, vector<int>(n,0));
        for (auto &x : matrix[0]) {
            x -= '0';
        }

        int max_size = largestRectangleArea(matrix[0]);
        for (int i=1; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (matrix[i][j] == '1') {
                    matrix[i][j] = matrix[i-1][j] + 1;
                } else {
                    matrix[i][j] = 0;
                }
            }
            max_size = max(max_size, largestRectangleArea(matrix[i]));
        }

        return max_size;
    }

private:
    int largestRectangleArea(vector<char>& heights) {
        auto N = heights.size();
        if (N < 1)
            return 0;

        int max_size = 0;
        stack<int> ind;
        int i;
        for (i=0; i<N; ++i) {
            if (ind.empty() || heights[ind.top()] <= heights[i] ) {
                ind.push(i);

            } else {
                while (!ind.empty() && heights[ind.top()] > heights[i]) {
                    auto top = ind.top();
                    ind.pop();

                    max_size = max(max_size, heights[top] * (ind.empty() ? i : i-ind.top()-1));
                }

                ind.push(i);
            }
        }
        while (!ind.empty()) {
            auto top = ind.top();
            ind.pop();

            max_size = max(max_size, heights[top] * (ind.empty()? i : i-ind.top()-1));
        }

        return max_size;
    }
};

int main() {
    vector<vector<vector<char>>> ivv;
    ivv.push_back({{'0','1','1'}});
    ivv.push_back({{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}});

    for (auto &x : ivv) {
        cout << x;
        cout << " -> " << Solution{}.maximalRectangle(x) << endl;
    }

    return 0;
}
