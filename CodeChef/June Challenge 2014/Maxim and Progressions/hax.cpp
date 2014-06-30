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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int MOD = 1000000007;
int a[222222], cnt[111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int out = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            out = (out + out) % MOD;
        }
        int ans = 0;
        for (int d = -100; d <= 100; ++d) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; ++i) {                
                int cc = cnt[a[i]];
                if (a[i] - d >= 1 && a[i] - d <= 100) {
                    ans = (ans + cnt[a[i] - d]) % MOD;
                    cc = (cc + cnt[a[i] - d]) % MOD;
                }
                cnt[a[i]] = (cc + 1) % MOD;
            }
        }
        ans = (ans + n + 1) % MOD;
        out = (out - ans + MOD) % MOD;
        cout << out << "\n";
    }

    
    return 0;
}
