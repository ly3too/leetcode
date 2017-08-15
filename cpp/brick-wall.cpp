/*
here is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.
The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.
If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.
You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
Example:
Input:
[[1,2,2,1],
 [3,1,2],
 [1,3,2],
 [2,4],
 [3,1,2],
 [1,3,1,1]]
Output: 2
*/

/* O(n*m), O(m*n)*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int max_len = 0;
        int N = wall.size();
        unordered_map<int, int> widths;

        for (auto &line : wall) {
            int width = 0;
            for (int i=0; i+1<line.size(); ++i) {
                if (line[i]) {
                    width += line[i];
                    ++widths[width];
                    max_len = max(max_len, widths[width]);
                }
            }
        }

        return N - max_len;
    }
};
