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

int n, m;
int q;
char s[1111][1111];
int d[111];
int c[111];
char way[111];

typedef short matr[1011][1011][6];
matr cl[4], &up = cl[0], &dw = cl[1], &lf = cl[2], &ri = cl[3];
int code[255], dircode[255], lway;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i) gets(s[i]);

    code['1'] = 1;
    code['2'] = 2;
    code['3'] = 3;
    code['4'] = 4;
    code['5'] = 5;
    code['#'] = 0;

    dircode['U'] = 0;
    dircode['D'] = 1;
    dircode['L'] = 2;
    dircode['R'] = 3;

    memset(cl, 63, sizeof(cl));
    for (int i = 0; i < n; ++i) {        
        for (int j = 0; j < m; ++j) {
            if (i > 0)
                for (int k = 0; k < 6; ++k) up[i][j][k] = up[i - 1][j][k] + 1;
            else
                for (int k = 0; k < 6; ++k) up[i][j][k] = i + 1;

            if (j > 0)
                for (int k = 0; k < 6; ++k) lf[i][j][k] = lf[i][j - 1][k] + 1;
            else
                for (int k = 0; k < 6; ++k) lf[i][j][k] = j + 1;

            if (s[i][j] != '.') {
                up[i][j][ code[s[i][j]] ] = 0;
                lf[i][j][ code[s[i][j]] ] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {        
        for (int j = m - 1; j >= 0; --j) {
            if (i + 1 < n)
                for (int k = 0; k < 6; ++k) dw[i][j][k] = dw[i + 1][j][k] + 1;
            else
                for (int k = 0; k < 6; ++k) dw[i][j][k] = n - i;

            if (j + 1 < m)
                for (int k = 0; k < 6; ++k) ri[i][j][k] = ri[i][j + 1][k] + 1;
            else
                for (int k = 0; k < 6; ++k) ri[i][j][k] = m - j;

            if (s[i][j] != '.') {
                dw[i][j][ code[s[i][j]] ] = 0;
                ri[i][j][ code[s[i][j]] ] = 0;
            }
        }
    }

    scanf("%d\n", &q);
    for (int i = 0; i < q; ++i) {
        char ch;
        scanf("%c %d\n", &ch, &c[i]);
        d[i] = dircode[ch];
    }
    gets(way);
    lway = strlen(way);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = i, y = j, z = 0;
            bool fail = false;
            for (int k = 0; k < q; ++k) {
                if (cl[ d[k] ][x][y][0] <= c[k]) {
                    fail = true;
                    break;
                }

                int cc = c[k], xx = x, yy = y;
                while (z < lway && cl[ d[k] ][xx][yy][ way[z] - 48 ] < cc) {
                    int dc = cl[ d[k] ][xx][yy][ way[z] - 48 ];

                    xx += dx[ d[k] ] * (dc + 1);
                    yy += dy[ d[k] ] * (dc + 1);
                    cc -= dc + 1;
                    ++z;
                }
                x += c[k] * dx[ d[k] ];
                y += c[k] * dy[ d[k] ];
            }
            if (z < lway && s[x][y] == way[z]) ++z;
            if (!fail && z == lway) ++ans;
        }
    }

    printf("%d\n", ans);

    return 0;
}
