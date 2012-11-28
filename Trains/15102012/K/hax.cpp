#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct Tp {
    LL x, y;
} a[5555];

LL Tri(Tp& a ,Tp& b, Tp& c) {
    return llabs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}
LL f[5555][5555];
int nxt[5555], prv[5555];

struct To {
    int i, j, k;
    To(int i = 0, int j = 0, int k = 0):i(i),j(j),k(k){};
} out1, out2, best[5555][5555];

int main() {
    freopen("kids.in", "r", stdin);
    freopen("kids.out", "w", stdout);
    cerr << sizeof(f) << endl;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }
    prv[0] = n - 1;
    nxt[n - 1] = 0;

    for (int i = 0; i < n; i++) f[i][nxt[i]] = LL(1e18);
    for (int l = 2; l < n; l++)
        for (int i = 0; i < n; i++) {
            int j = (i + l) % n;

            LL t1 = Tri(a[i], a[j], a[nxt[i]]);
            LL t2 = Tri(a[i], a[j], a[prv[j]]);

            f[i][j] = f[nxt[i]][j];
            best[i][j] = best[nxt[i]][j];
             
            if (f[i][prv[j]] < f[i][j]) {
                f[i][j] = f[i][prv[j]];
                best[i][j] = best[i][prv[j]];
            }

            if (t1 < f[i][j]) {
                f[i][j] = t1;
                best[i][j] = To(i, j, nxt[i]);
            }

            if (t2 < f[i][j]) {
                f[i][j] = t2;
                best[i][j] = To(i, j, prv[j]);
            }
        }  

    LL ans = 0;
    To out1, out2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (j != i && j != nxt[i]) {
            LL s = Tri(a[i], a[nxt[i]], a[j]) - min(f[nxt[i]][j], f[j][i]);
            if (s > ans) {
                out1 = To(i, nxt[i], j);
                if (f[nxt[i]][j] < f[j][i]) {
                    out2 = best[nxt[i]][j];
                } else {
                    out2 = best[j][i];
                }
                ans = s;  
            }
        }
    }
    if (ans & 1)
        cout << (ans >> 1) << ".5" << endl;
    else
        cout << (ans >> 1) << endl;
    cout << (out1.i + 1) << " " << (out1.j + 1) << " " << (out1.k + 1) << endl;
    cout << (out2.i + 1) << " " << (out2.j + 1) << " " << (out2.k + 1) << endl;
            
    
    return 0;
}
