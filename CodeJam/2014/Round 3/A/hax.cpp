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

const int N = 1111111;
LL A[N];
LL S[N];
int n;

inline LL SUM(int i, int j) {
    if (j == 0) return S[i];
    return S[i] - S[j - 1];
}
inline LL MAX(int i, int j) {
    LL res = SUM(i, j);
    if (j > 0) res = max(res, SUM(j - 1, 0));
    if (i < n - 1) res = max(res, SUM(n - 1, i + 1));
    return res;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    cin >> T;
    int it = 0;
    while (T--) {
        LL p, q, r, s;

        cin >> n >> p >> q >> r >> s;
        for (int i = 0; i < n; ++i) {
            A[i] = ((i * p + q) % r + s);
            S[i] = (i == 0) ? A[i] : (S[i - 1] + A[i]);
        }
        LL tot = S[n - 1];
        LL ans =  tot;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j <= i && MAX(i, j + 1) < MAX(i, j)) {
                ans = min(ans, MAX(i, j));
                ++j;
            }
            ans = min(ans, MAX(i, j));
        }

        ++it;
        cout << "Case #" << it << ": ";
        cout.precision(15);
        cout << fixed << (double)(LD(tot - ans) / tot) << endl;
    }     
    
    return 0;
}
