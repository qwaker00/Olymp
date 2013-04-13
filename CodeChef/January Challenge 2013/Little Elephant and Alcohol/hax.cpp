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

int n, a[22], k, m;
int t;

void rec(int i, int out, int& ans) {
    if (out >= ans) return;
    if (i >= k) {
        int mx = -1, cn = 0;
        for (int j = i - k; j < i; j++) {
            if (a[j] > mx) {
                mx = a[j];
                cn = 1;
            } else
            if (a[j] == mx) cn++;
        }
        if (cn >= m) return;
    }

    if (i == n) {
        if (out < ans) ans = out;
        return;
    }

    rec(i + 1, out, ans);
    ++a[i];
    rec(i + 1, out + 1, ans);
    --a[i];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> t;
    while (t--) {
        cin >> n >> k >> m;
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 1e9;
        rec(0, 0, ans);
        if (ans > n)
            cout << -1 << endl;else
            cout << ans << endl;
    }

    return 0;
}
