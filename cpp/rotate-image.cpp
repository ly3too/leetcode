#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = static_cast<int>(matrix.size());

        n = n-1;
        int i = 0;
        while (n > 0) {

            auto tmp = matrix[i,i];
            auto y = i + n;
            matrix[i][i] = [y][i];
            matrix[y][i] = matrix[y][y];
            matrix[y][y] = matrix[i][y];
            matrix[i][y] = tmp;

            n - 2;
            ++i;
        }

    }
};

class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {

        sub_rotate(matrix, 0, static_cast<int>(matrix.size()));
    }

private:
    void sub_rotate(ector<vector<int>>& matrix, int i, int n) {
        if (n <= 0)
            return;

        auto tmp = matrix[i,i];
        auto y = i + n;
        matrix[i][i] = [y][i];
        matrix[y][i] = matrix[y][y];
        matrix[y][y] = matrix[i][y];
        matrix[i][y] = tmp;

        sub_rotate(matrix, i+1, n-2);
        return;
    }
};

int main () {
    // vector<int> input {-1, -1, -1, 0, 1, 1, 1, 2, 2, 2};
    vector<vector<int>> input;
    vector<int> list1(3,1);
    input.push_back(list1);
    fill(list1.begin(), list1.end(), 2);
    input.push_back(list1);
    fill(list1.begin(), list1.end(), 3);
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
