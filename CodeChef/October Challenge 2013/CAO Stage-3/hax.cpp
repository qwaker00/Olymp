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

char s[22][22];
char mon[22][22];
int res[21][21][21][21];

int cnt = 0, step = 100000, nxt = step;

int solve(int r1, int c1, int r2, int c2) {
    int ans = res[r1][c1][r2][c2];
    if (ans != -1) return ans;

    cerr << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    if (++cnt == nxt) {
        cerr << cnt << endl;
        nxt += step;
    }

    vector<int> v;
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            if (mon[i][j]) {
                 v.push_back( solve(r1, c1, i - 1, j - 1) ^
                              solve(r1, j + 1 , i - 1, c2) ^
                              solve(i + 1, c1, r2, j - 1) ^
                              solve(i + 1, j + 1, r2, c2)
                            );
            }
        }
    }

    ans = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size();)
        if (ans == v[i])
            ++ans;
        else
        if (ans > v[i])
            ++i;
        else
            break;

    return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);        
    while (T--) {
        int n, m;
        scanf("%d%d\n", &n, &m);
        for (int i = 0; i < n; ++i) {
            gets(s[i]);
        }
        memset(mon, 0, sizeof(mon));
        memset(res, -1, sizeof(res));
        for (int i = 2; i < n - 2; ++i) {
            for (int j = 2; j < m - 2; ++j) {
                if (s[i][j] == '^' && 
                    s[i + 1][j] == '^' && s[i + 2][j] == '^' &&
                    s[i - 1][j] == '^' && s[i - 2][j] == '^' &&
                    s[i][j + 1] == '^' && s[i][j + 2] == '^' &&
                    s[i][j - 1] == '^' && s[i][j - 2] == '^'
                )
                {
                    mon[i][j] = true;
                }
            }
        }

        cout << (solve(0, 0, n - 1, m - 1) ? "Asuna": "Kirito") << endl;
    }
    
    return 0;
}
