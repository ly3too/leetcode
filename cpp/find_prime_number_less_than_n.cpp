/* Sieve of Sundaram algorithm */

#include "header.hpp"

void sieve_of_sundaram(int n) {
    if (n <= 1)
        return;

    const int n2 = (n-2)/2;
    vector<bool> mask(n2+1, false);

    for (int i=1; i<= n2; ++i) {
        int j=i;
        for (int idx2=(i+j+2*i*j); idx2 <= n2; ++j, idx2=(i+j+2*i*j)) {
            mask[idx2] = true;
        }
    }

    int cnt = 0;
    if (n >= 2) {
        cout << 2 << " ";
        ++cnt;
    }

    for (int i=1; i<=n2; ++i) {
        if (!mask[i]) {
            cout << 2*i+1 << " ";
            ++ cnt;
        }
    }
    cout << endl << "total: " << cnt << endl;
}

int main() {
    sieve_of_sundaram(1000);

    return 0;
}
