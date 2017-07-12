#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = static_cast<int>(matrix.size());
        --n;
        if (n < 1 || matrix[0].size() < 1)
            return;

        for(int i=0, j=n; i < j; ++i, --j) {

            for (int y=i; y<j; ++y) {
                auto x = n - y;
                auto tmp = matrix[i][y];

                matrix[i][y] = matrix[x][i];
                matrix[x][i] = matrix[j][x];
                matrix[j][x] = matrix[y][j];
                matrix[y][j] = tmp;
            }
        }

    }
};

class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() < 1 || matrix[0].size() < 1)
            return;

        sub_rotate(matrix, 0, static_cast<int>(matrix.size())-1, static_cast<int>(matrix.size())-1);
    }

private:
    void sub_rotate(vector<vector<int>>& matrix, int i, int j, int n) {
        if (i >= j)
            return;

            for (int y=i; y<j; ++y) {
                auto x = n - y;
                auto tmp = matrix[i][y];

                matrix[i][y] = matrix[x][i];
                matrix[x][i] = matrix[j][x];
                matrix[j][x] = matrix[y][j];
                matrix[y][j] = tmp;
            }

        sub_rotate(matrix, i+1, j-1, n);
        return;
    }
};

int main () {
    // vector<int> input {-1, -1, -1, 0, 1, 1, 1, 2, 2, 2};
    vector<vector<int>> input;
    vector<int> list1(4,1);
    input.push_back(list1);
    fill(list1.begin(), list1.end(), 2);
    input.push_back(list1);
    fill(list1.begin(), list1.end(), 3);
    input.push_back(list1);
    fill(list1.begin(), list1.end(), 4);
    input.push_back(list1);

    for (auto x : input) {
        cout << "[ ";
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "] " << endl;
    }

    Solution s;
    s.rotate(input);

    for (auto x : input) {
        cout << "[ ";
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "] " << endl;
    }

    Solution2().rotate(input);

    for (auto x : input) {
        cout << "[ ";
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "] " << endl;
    }

    return 0;
}
