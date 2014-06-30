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
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a == 0 && b == 0) {
            for (int i = 0; i < n; ++i) cout << "0\n";
        } else
        if (a > 0 && b > 0 && a <= b && b < n) {
            vector< vector<int> > g(n + 1);
            for (int i = 1; i <= a; ++i) {
                g[i + 1].push_back(i);
            }
            for (int j = 0; j < b - a; ++j) {
                g[a + 1].push_back(a + 2 + j);
            }
            for (int i = 1; i <= n; ++i) {
                cout << g[i].size() << " ";
                for (int j = 0; j < g[i].size(); ++j)
                    cout << g[i][j] << " ";
                cout << "\n";
            }
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    
    
    return 0;
}
