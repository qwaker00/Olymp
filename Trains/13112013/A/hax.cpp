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

int price[111111];
vector<int> g[111111];
int cnt[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            g[i].clear();
            for (int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                g[i].push_back(x);
            }
            cin >> price[i];
        }
        for (int i = 1; i <= m; ++i) cin >> cnt[i];
        LL ans = 0;
        for (int i = 0; i < n; ++i) {
            int mi = 2e9;
            for (size_t j = 0; j < g[i].size(); ++j) {
                mi = min(cnt[g[i][j]], mi);
            }
            ans += LL(price[i]) * mi;
        }
        cout << ans << endl;
    }
        
    return 0;
}
