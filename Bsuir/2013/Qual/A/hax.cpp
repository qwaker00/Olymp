#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int k, n, m, x;
    cin >> k >> n >> m >> x;
    int mx = 1 << k;
    int ans = 0;

    if (m > n) swap(n, m);
    if (k <= 20) {
        for (int a = 0; a < mx; a += n)
            ans += ((a ^ x) % m == 0);
    } else {
        int k1 = (k + 1) >> 1;
        int k2 = k - k1;

        vector< pair<int, int> > all;
        int m2 = (1 << k2) - 1;
        for (int i = 0; i <= m2; ++i) {
            all.push_back(
                make_pair(
                    (n - (i & m2) % n) % n,
                    (m - ((i ^ x) & m2) % m) % m
                )
            );
        }
        sort(all.begin(), all.end());

        for (int i = 0; i < (1 << k1); ++i) {
            int dn = (i << k2) % n;
            int dm = (((x >> k2) ^ i) << k2) % m;
            pair<vector< pair<int, int> >::iterator, vector< pair<int, int> >::iterator> r = equal_range(all.begin(), all.end(), make_pair(dn, dm));
            ans += r.second - r.first;
        }
    }
    
    cout << ans << endl;
//    cerr << clock() << endl;
    return 0;
}
