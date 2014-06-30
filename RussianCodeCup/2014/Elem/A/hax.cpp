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
    
    int T;
    cin >> T;
    while (T--) {
        int n, m, t, c;
        cin >> n >> m >> t >> c;
        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        vector<vector<int> >  f(m + 1, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) f[m][i] = 0;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j)
                if (s[j][i] == '1') {
                    f[i][j] = f[i + 1][j];
                    for (int k = 0; k < n; ++k) f[i][j] = min(f[i][j], f[i + 1][k] + 1);
                    //cerr << i << " " << j << " " << f[i][j] << endl;
                }
        }
        //cerr << endl;
        int ans = 1e9;
        for (int i = 0; i < n; ++i) ans = min(ans, f[0][i]);
        cout << t * m + c * ans << endl;
    }    
    
    return 0;
}
