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

const int N = 111111;
int x[N], y[N], ex[N], ey[N];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            ex[i] = u;
            ey[i] = v;
            if (x[u] > y[v] || y[u] > x[v]) {
                swap(y[v], x[v]);
                ans.push_back(v);
            }
        }

        bool good = 1;
        for (int i = 0; i < m; ++i) {
            if (x[ex[i]] > x[ey[i]] || y[ex[i]] > y[ey[i]]) {
                //
            } else {
                good = 0;
                break;
            }
        }
        if (!good) 
            cout << "-1\n";
        else {
            cout << ans.size() << " ";
            for (int i = 0; i < ans.size(); ++i) cout << (ans[i] + 1) << " ";
            cout << "\n";
        }
       
    }
        
    
    return 0;
}
