/*
In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
*/

/* O(n!), O(n) */
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;

        lookup.clear();
        return canIWin_DFS(maxChoosableInteger, desiredTotal, 0);
    }
private:
    unordered_map<int, bool> lookup;
    bool canIWin_DFS(int maxChoosableInteger, int desiredTotal, int visited) {
        if (lookup.find(visited) != lookup.end()) {
            return lookup[visited];
        }

        int mask = 1;
        for (int i=1; i <= maxChoosableInteger; ++i) {
            if (! (visited & mask)) {
                if (i >= desiredTotal || !canIWin_DFS(maxChoosableInteger, desiredTotal-i, visited | mask)) {
                    lookup[visited] = true;
                    return true;
                }
            }
            mask <<= 1;
        }

        lookup[visited] = false;
        return false;
    }
};
