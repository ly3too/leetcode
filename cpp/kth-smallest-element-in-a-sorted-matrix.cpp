/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
*/


#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
#include <ctime>
#include <ctype.h>
#include <sstream>
#include <map>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <typeinfo>
#include "print_container.hpp"

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const auto M = matrix.size();
        if (M == 0)
            return 0;
        const auto N = matrix[0].size();
        if (N == 0)
            return 0;

        using P = pair<int, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> que;

        que.push(make_pair(matrix[0][0], make_pair(0, 0)));
        int n = 0;
        int val;
        while (!que.empty() && n<k) {
            int i, j;
            val = que.top().first;
            tie(i, j) = que.top().second;
            que.pop();
            ++n;

            if (j+1 < N) {
                que.push(make_pair(matrix[i][j+1], make_pair(i, j+1)));
            }
            if (i+1 < M && j==0) {
                que.push(make_pair(matrix[i+1][j], make_pair(i+1, j)));
            }
        }

        return val;
    }
};
