/* test if a int number is prime */
#include "header.hpp"

using namespace std;

/* O(n) */
bool is_prime(int n) {
    if (n <= 0)
        return false;
    if (n <= 3)
        return true;
    if (n%2 == 0 || n%3 == 0) {
        return false;
    }

    int i = 5;
    while (i*i <= n) {
        if (n%i == 0 || n%(i+2) == 0)
            return false;
        i += 6;
    }

    return true;
}

int main() {
    for (int i=0; i<10000000; ++i) {
        if (is_prime(i))
            cout << i << " ";
    }
    cout << endl;
}
