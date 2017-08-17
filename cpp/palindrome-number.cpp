/*
Determine whether an integer is a palindrome. Do this without extra space.
*/


class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        int y = 0;
        int xs = x;
        while (xs != 0) {
            y = y*10 + xs%10;
            xs /= 10;
        }

        return x == y;
    }
};
