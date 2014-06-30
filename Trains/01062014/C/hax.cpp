#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cassert>

using namespace std;
typedef long double LD;

int a[111];
int was[111];
int wass[111][111], ans[111][111];
int n, k;
const int MOD = 1000000007;

int solve(int k, int mx) {
    if (k == n) return 1;
    if (wass[k][mx]) return ans[k][mx];
    wass[k][mx] = 1;

    int& res = ans[k][mx] = 0;

    for (int i = mx + 1; i <= n; ++i)
        res = (res + solve(k + 1, i)) % MOD;

    if (mx > k)
        res = ( res + solve(k + 1, mx) ) % MOD;

    return res;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);


    int T;
    cin >> T;
    int it = 0;
    while(T--) {
        ++it;

        cin >> n >> k;
        bool ok = 1;
        int mi = 1;
        int mx = 0;
        memset(was, 0, sizeof(was));
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            if (ok)
                for (int j = 0; j < i; ++j) if (a[j] > a[i]) {
                    if (a[i] != mi) {
                        ok = 0;
                        break;
                    }
                }
            if (a[i] > mx) mx = a[i];
            was[a[i]] = 1;
            while (was[mi]) ++mi;
        }
        cout << "Case #" << it << ": ";

        if (!ok) {
            puts("0");
            continue;
        }

        memset(wass, 0, sizeof(wass));
        cout << solve(k, mx) << endl;
    }

    return 0;
}
