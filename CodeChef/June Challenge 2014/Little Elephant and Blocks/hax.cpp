#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>
#include <assert.h>

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

    ULL fact[22];
    fact[0] = 1;
    for (int i = 1; i < 21; ++i) fact[i] = fact[i - 1] * i;

    cout.precision(12);
    cout << fixed;

    int T;
    cin >> T;
    while (T--) {
        int n, a[22], c[22], K, s = 0;
        int colormask[22];
        ULL cnt[22][222];
        memset(colormask, 0, sizeof(colormask));
        memset(cnt, 0, sizeof(cnt));

        int preans = 0;
        cin >> n >> K;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> c[i];
            --c[i];
            s += a[i];
            colormask[ c[i] ] |= (1 << i);
            if (a[i] > K)
                preans += a[i] - K;
        }
        for (int i = 0; i < (1 << n); ++i) {
            int l = 0, c = 0;
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & i) { 
                    l += a[j];
                    ++c;
                 }
            }
            for (int j = 0; j < n; ++j) if (colormask[j] && (colormask[j] & (colormask[j] - 1)) && !(i & colormask[j])) {
                cnt[j][l] += fact[n - c - 1] * fact[c];
            }
        }
        ++K;
        LD ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) if (c[i] == c[j]) {
                for (int k = 0; k <= s; ++k) {
                    if (cnt[c[i]][k]) {
                        int start = max(0, k + a[i] + 1 - K);
                        int finish = min(a[i] + a[j] + k - 1, a[i] + K - 2);
                        int cc = 0;
                        if (finish - start - K + 2 > 0)
                            cc += (finish - start - K + 2);

                        start = max(0, k + a[j] + 1 - K);
                        finish = min(a[j] + a[i] + k - 1, a[j] + K - 2);
                        if (finish - start - K + 2 > 0)
                            cc += (finish - start - K + 2);

                        ans += LD(cc) * cnt[c[i]][k];
                    }
                }    
            }
        }
        cout << preans + (double)(ans / fact[n]) << endl;
    }    
    return 0;
}
