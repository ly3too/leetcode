/*
You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:
Input:
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
Example 2:
Input:
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
Example 3:
Input:
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
*/

/* O(t*(log(t) + (m*n))), O(t + m*n)*/
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.size() == 0 || forest[0].size() == 0)
            return 0;

        auto m = forest.size();
        auto n = forest[0].size();

        using node_t = pair<int, pair<int, int>>;
        priority_queue<node_t, vector<node_t>, greater<node_t>> min_heap;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (forest[i][j] > 1) {
                    min_heap.emplace(forest[i][j], make_pair(i, j));
                }
            }
        }

        int steps = 0;
        pair<int, int> cur_indx{0, 0};
        while (!min_heap.empty()) {
            auto next_node = min_heap.top();
            min_heap.pop();

            auto cur_step = min_step(forest, cur_indx, next_node.second);
            if (cur_step < 0)
                return -1;

            steps += cur_step;
            cur_indx = move(next_node.second);
        }

        return steps;
    }

private:

    int min_step(vector<vector<int>> &forest, pair<int, int> &start_indx, pair<int, int> &stop_indx) {
        auto m = forest.size();
        auto n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        auto step = 0;
        queue<pair<int, int>> que;
        que.emplace(start_indx);
        visited[start_indx.first][start_indx.second] = true;
        while (!que.empty()) {
            auto size = que.size();
            while (size--) {
                auto cur_indx = que.front();
                que.pop();

                if (cur_indx == stop_indx)
                    return step;

                const vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

                for (auto &dir : dirs) {
                    auto i = cur_indx.first + dir.first;
                    auto j = cur_indx.second + dir.second;

                    if (i>=0 && i<m && j>=0 && j<n && visited[i][j] == false && forest[i][j] > 0) {
                        que.emplace(i, j);
                        visited[i][j] = true;
                    }
                }
            }

            ++ step;
        }

        return -1;
    }
};
