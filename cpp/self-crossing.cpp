/*
You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north,
then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words,
after each move your direction changes counter-clockwise.
Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.
*/

/* O(n), O(1) */
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        const int N = x.size();
        if (N < 4) {
            return false;
        }

        if (N >=5 && x[0] + x[4] >= x[2] && x[1] == x[3]) {
            return true;
        }

        for (int i=0; i<N-3; ++i) {
            // case 1, cross after 4 run
            /* ____
              |    |
               ----+->
            */
            // cout << i << endl;
            if (x[i] >= x[i+2] && x[i+1] <= x[i+3]) {
                return true;
            }

            // case 2, cross after 6 run
            /* ____
              |    |
              |  <-+--
              |______|
            */
            if (i+5 < N && x[i+1] <= x[i+3] && x[i+2] >= x[i+4] && x[i] + x[i+4] >= x[i+2] && x[i+1]+x[i+5] >= x[i+3]) {
                return true;
            }
        }

        return false;
    }
};
