#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    assert(n>=0 && m>0);

    vector<int> arr(m);
    for (int i=0; i<m; ++i) {
        cin >> arr[i];
        assert(arr[i] > 0);
    }

    vector<int> res;
    int idx = 0; // index for arr, < m
    int i=0; // i-th res

    while(i < n) {
        int times = res.size()>idx ? res[idx] : arr[idx%m];
        for (int j=0; j<times; ++j) {
            res.emplace_back(arr[idx%m]);
            cout << res[i] << endl;

            ++i;
            if (i >= n)
                break;
        }

        ++idx;
    }
}
