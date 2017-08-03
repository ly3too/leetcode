/*
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.
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
#include <typeinfo>
#include <tuple>
#include <queue>
#include "print_container.hpp"

using namespace std;
/* use a min-heap, return the min hight of outmost side, from the min-hight pace step into the matrix (add elements from four direction),
then the outside still form a closed loop, for each added elements, calculate the taped water  */
/*O(m*n*log(m*n)), O(m*n)*/
class Solution {
    using T = tuple<int, int, int>;
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        auto const M = heightMap.size();
        if (M <= 2) {
            return 0;
        }
        auto const N = heightMap[0].size();
        if (N <= 2 ) {
            return 0;
        }
        vector<vector<bool>> visited(M, vector<bool>(N, false));

        priority_queue<T, vector<T>, greater<T>> que;

        // cout << M << "x" << N << endl;
        for (int i=0; i<N; ++i) {
            // cout << i << ", " << 0 << endl;
            que.push(make_tuple(heightMap[0][i], 0, i));
            que.push(make_tuple(heightMap[M-1][i], M-1, i));
            visited[0][i] = true;
            visited[M-1][i] = true;
        }
        for (int i=1; i<M-1; ++i) {
            // cout << i << ", " << 0 << endl;
            que.push(make_tuple(heightMap[i][0], i, 0));
            que.push(make_tuple(heightMap[i][N-1], i, N-1));
            visited[i][0] = true;
            visited[i][N-1] = true;
        }

        int sum = 0;
        while (!que.empty()) {
            auto min_h = get<0>(que.top());
            auto i = get<1>(que.top());
            auto j = get<2>(que.top());
            que.pop();
             cout << i << ", " << j << endl;
            // add cell from 4 side of the min height cell;
            if (i+1 < M-1) {
                sum += add_cell(heightMap, que, visited, min_h, i+1, j);
            }
            if (j+1 < N-1) {
                sum += add_cell(heightMap, que, visited, min_h, i, j+1);
            }
            if (i-1 > 0) {
                sum += add_cell(heightMap, que, visited, min_h, i-1, j);
            }
            if (j-1 > 0) {
                sum += add_cell(heightMap, que, visited, min_h, i, j-1);
            }
        }

        return sum;
    }
private:
    /* add cell return traped volume of the cell*/
    int add_cell(vector<vector<int>>& heightMap,
    priority_queue<T, vector<T>, greater<T>>& que,
    vector<vector<bool>>& visited, int& min_h, int i, int j) {
        if (! visited[i][j]) {
            que.push(make_tuple(heightMap[i][j], i, j));
            visited[i][j] = true;
            return max(0, min_h - heightMap[i][j]);
        } else {
            return 0;
        }
    }
};

int main() {
    vector<vector<int>> heightMap {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    cout << Solution{}.trapRainWater(heightMap) << endl;
}
