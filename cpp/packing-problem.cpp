#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int w1, w2, w3, w4, w5, w6;
    while (cin >> w1 >> w2 >> w3 >> w4 >> w5 >> w6) {
        int leftRegion = 0;
        int res = w6; // every block of size 6 must take 1 pack
        res += w5; // every block of size 5 take 1 pack and left 11 1*1 space for each block

        leftRegion = w5 * 11;
        w1 = max(0,w1 - w5 * 11);

        res += w4; // every block of 4 takes 1 pack, left 5 2*2 space for each block
        leftRegion = 20 * w4;
        if (leftRegion <= w2 * 4){
            w2 -= leftRegion / 4;
            leftRegion = 0;
        } else {
            leftRegion -= w2 * 4;
            w2 = 0;
        }

        if (leftRegion > 0)
            w1 = max(0, w1 - leftRegion);

        res += w3 / 4;
        w3 %= 4;
        if (w3 > 0) {
            ++res;
            leftRegion = (4 - w3) * 9;
            if (leftRegion <= w2 * 4){
                w2 -= leftRegion / 4; leftRegion = 0;
            } else {
                leftRegion -= w2 * 4;
                w2 = 0;
            }

            if (leftRegion > 0)
                w1 = max(0, w1 - leftRegion);
            }

        res += w2 / 9;
        w2 %= 9;
        if (w2 > 0) {
            ++res;
            leftRegion = (9 - w2) * 4;
            w1 = max(0, w1 - leftRegion);
        }

        res += w1 / 36;
        if (w1 % 36 > 0) ++res;

        if (res)
            cout << res << endl;
    }

    return 0;
}
