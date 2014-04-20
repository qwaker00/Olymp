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

struct Tp {
    int t, x, y;

    Tp(int t = 0, int x = 0, int y = 0) : t(t), x(x), y(y) {}
} f[22];
int n, m, kx, ky, fn;
char s[22][22];

typedef bool TMatr[15][15]; 

TMatr can[32777];
int kdx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int kdy[] = {2, 2, 1, -1, -2, -2, -1, 1};
int bdx[] = {1, -1, 1, -1};
int bdy[] = {1, 1, -1, -1};
int rdx[] = {1, -1, 0, 0};
int rdy[] = {0, 0, -1, 1};
int kidx[] = {1, -1, 1, -1, 1, -1, 0, 0};
int kidy[] = {1, 1, -1, -1, 0, 0, -1, 1};


int D[32777][15][15];
int num[15][15];

inline void go(int x, int y, char t, TMatr& a, int msk) {
    if (t == 'K') {
        for (int i = 0; i < 8; ++i) {
            int xx = x + kdx[i];
            int yy = y + kdy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            a[xx][yy] = true;
        }
    } else
    if (t == 'B') {
        for (int i = 0; i < 4; ++i) {
            int xx = x;
            int yy = y;
            do {
                xx += bdx[i];
                yy += bdy[i];
                if (xx < 0 || yy < 0 || xx >= n || yy >= m) break;
                a[xx][yy] = true;
                if (num[xx][yy] != -1 && (msk & (1 << num[xx][yy]))) break;
            } while (true);
        }
    } else
    if (t == 'R') {
        for (int i = 0; i < 4; ++i) {
            int xx = x;
            int yy = y;
            do {
                xx += rdx[i];
                yy += rdy[i];
                if (xx < 0 || yy < 0 || xx >= n || yy >= m) break;
                a[xx][yy] = true;
                if (num[xx][yy] != -1 && (msk & (1 << num[xx][yy]))) break;
            } while (true);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    memset(num, -1, sizeof(num));

    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '*') {
                kx = i;
                ky = j;
            } else
            if (s[i][j] != '.') {
                f[fn].t = s[i][j];
                f[fn].x = i;
                f[fn].y = j;
                num[i][j] = fn;
                ++fn;
            }
        }
    }

    if (fn == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int msk = 1; msk < (1 << fn); ++msk) {
        for (int any = 0; any < fn; ++any) if ((1 << any) & msk) {
            go(f[any].x, f[any].y, f[any].t, can[msk], msk);            
        }
/*        cout << msk << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                putchar('0' + can[msk][i][j]);
            }
            puts("");
        }*/
    }

    memset(D, 63, sizeof(D));
    queue<Tp> q;
    q.push( Tp( (1 << fn) - 1, kx, ky ) );
    D[(1 << fn) - 1][kx][ky] = 0;
    while (!q.empty()) {
        Tp t = q.front(); q.pop();
        TMatr& a = can[t.t];
            
        for (int i = 0; i < 8; ++i) {
            int xx = t.x + kidx[i];
            int yy = t.y + kidy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m || a[xx][yy]) continue;
            int tt = t.t;
            if (num[xx][yy] != -1) tt &= ~(1 << num[xx][yy]);

            if (D[tt][xx][yy] < 1e9) continue;

            if (tt == 0) {
                cout << D[t.t][t.x][t.y] + 1 << endl;
                return 0;
            }
            q.push( Tp(tt, xx, yy) );
            D[tt][xx][yy] = D[t.t][t.x][t.y] + 1;
        }
    }
    cout << -1 << endl;
    
    return 0;
}
