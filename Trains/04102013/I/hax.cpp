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
    
int lg[133];
int a[4][133][133];
int f[4][133][133][9][9];

#define M 1000000007

int n, m;

LL request(int r1, int c1, int r2, int c2) {
    int t1 = lg[r2 - r1 + 1];
    int t2 = lg[c2 - c1 + 1];

    int x1  = max(max(f[0][r1][c1][t1][t2], f[0][r2 - (1 << t1) + 1][c2 - (1 << t2) + 1][t1][t2]), max(f[0][r1][c2 - (1 << t2) + 1][t1][t2], f[0][r2 - (1 << t1) + 1][c1][t1][t2]));
    int y1  = max(max(f[1][r1][c1][t1][t2], f[1][r2 - (1 << t1) + 1][c2 - (1 << t2) + 1][t1][t2]), max(f[1][r1][c2 - (1 << t2) + 1][t1][t2], f[1][r2 - (1 << t1) + 1][c1][t1][t2]));

    int x2  = min(min(f[2][r1][c1][t1][t2], f[2][r2 - (1 << t1) + 1][c2 - (1 << t2) + 1][t1][t2]), min(f[2][r1][c2 - (1 << t2) + 1][t1][t2], f[2][r2 - (1 << t1) + 1][c1][t1][t2]));
    int y2  = min(min(f[3][r1][c1][t1][t2], f[3][r2 - (1 << t1) + 1][c2 - (1 << t2) + 1][t1][t2]), min(f[3][r1][c2 - (1 << t2) + 1][t1][t2], f[3][r2 - (1 << t1) + 1][c1][t1][t2]));

    if (x1 >= x2 || y1 >= y2) return 0;
    return LL(y2 - y1) * (x2 - x1);
}

int main() {
    freopen("pail.in", "r", stdin);
    freopen("pail.out", "w", stdout);

    lg[1] = 0;
    for (int i = 2; i < 133; ++i) {
        lg[i] = lg[i >> 1] + 1;
    }

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                scanf("%d", &a[k][i][j]);
            }
            if (a[2][i][j] < a[0][i][j]) {
                swap(a[2][i][j], a[0][i][j]);
            }
            if (a[3][i][j] < a[1][i][j]) {
                swap(a[3][i][j], a[1][i][j]);
            }
        }
    }

    for (int k = 0; k < 2; ++k) {
        for (int ii = 0; (1 << ii) <= n; ++ii)
        for (int jj = 0; (1 << jj) <= m; ++jj)
            for (int i = 0; i + (1 << ii) <= n; ++i) {
                for (int j = 0; j + (1 << jj) <= m; ++j) {
                    if (jj == 0) {
                        if (ii == 0) f[k][i][j][ii][jj] = a[k][i][j];else
                                     f[k][i][j][ii][jj] = max(f[k][i][j][ii - 1][jj], f[k][i + (1 << (ii - 1))][j][ii - 1][jj]);
                    } else
                        f[k][i][j][ii][jj] = max(f[k][i][j][ii][jj - 1], f[k][i][j + (1 << (jj - 1))][ii][jj - 1]);
                }
            }
    }
    for (int k = 2; k < 4; ++k) {
        for (int ii = 0; (1 << ii) <= n; ++ii)
        for (int jj = 0; (1 << jj) <= m; ++jj)
            for (int i = 0; i + (1 << ii) <= n; ++i) {
                for (int j = 0; j + (1 << jj) <= m; ++j) {
                    if (jj == 0) {
                        if (ii == 0) f[k][i][j][ii][jj] = a[k][i][j];else
                                     f[k][i][j][ii][jj] = min(f[k][i][j][ii - 1][jj], f[k][i + (1 << (ii - 1))][j][ii - 1][jj]);
                    } else
                        f[k][i][j][ii][jj] = min(f[k][i][j][ii][jj - 1], f[k][i][j + (1 << (jj - 1))][ii][jj - 1]);
                }
            }
    }

    LL ans = 0;
    int q, A, B, v0;
    scanf("%d%d%d%d", &q, &A, &B, &v0);
    for (int i = 0; i < q; ++i) {
        int v1 = (LL(A) * v0 + B) % M;
        int v2 = (LL(A) * v1 + B) % M;
        int v3 = (LL(A) * v2 + B) % M;
        int v4 = (LL(A) * v3 + B) % M;
        v0 = v4;
        ans = (ans + request(min(v1 % n, v3 % n), min(v2 % m, v4 % m), max(v1 % n, v3 % n), max(v2 % m, v4 % m))) % M;
    }    
    cout << ans << endl;

    return 0;
}
