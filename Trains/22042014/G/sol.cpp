#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 4004;
int n;
vector< pair<ll, int> > big, small;
int dbig = 0, dsmall = 0;

ll f[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int p, d;
        scanf("%d%d", &p, &d);

        if (d > 1) {
            big.push_back(make_pair(ll(p), d));
            dbig += d;
        } else {
            small.push_back(make_pair(ll(p), d));
            dsmall += d;
        }
    }
    sort(big.begin(), big.end());
    sort(small.begin(), small.end());

    if (n == 2 || small.size() == 0) {
        ll pmin = 1e10, pmax = -1e10;
        for (int i = 0; i < big.size(); ++i) {
            pmin = min(pmin, big[i].first);
            pmax = max(pmax, big[i].first);
        }
        for (int i = 0; i < small.size(); ++i) {
            pmin = min(pmin, small[i].first);
            pmax = max(pmax, small[i].first);
        }
        cout << pmax - pmin << endl;
        return 0;
    }
    if (big.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (dbig - 2 * (big.size() - 1) < dsmall) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = big.back().first - big[0].first;
    memset(f, 63, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i < n;

    return 0;
}
