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

const int N = 222;

struct Tp {
    int x, y, i;

    bool operator<(const Tp& t) const {
        return x < t.x || (x == t.x && y < t.y);
    }
} a[N];
int n;
int up[N][N], down[N][N];
bool f[N][N][N];
int p[N][N][N];

int main() {
    freopen("division.in", "r", stdin);
    freopen("division.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].i = i + 1;
    }
    sort(a, a + n);

    memset(up, -1, sizeof(up));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].x != a[j].x) {
                up[i][j] = 0;
                down[i][j] = 0;

                int A = a[i].y - a[j].y;
                int B = a[j].x - a[i].x;
                int C = -a[i].x * A - a[i].y * B;

                for (int k = i + 1; k < j; ++k) {
                    int t = A * a[k].x + B * a[k].y + C;
                    if (t < 0) ++down[i][j];else
                    if (t > 0) ++up[i][j];else {
                        up[i][j] = -1;
                        break;
                    }
                }
            }
        }
    }

    int bestscore = 1e9;
    int besti = 0, bestj = 0, bestk = 0;

    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; ++i) {
        int u = 0, d = 0, good = 1;
        for (int j = 0; j < i; ++j) {
            if (a[i].y == a[j].y) {
                good = 0;
                break;
            }
            if (a[j].y > a[i].y) ++u;else ++d;
        }
        if (good)
            f[i][u][d] = true;

        for (int j = 0; j <= i; ++j)
            for (int k = 0; j + k <= i; ++k) if (f[i][j][k]) {
                for (int l = i + 1; l < n; ++l) if (up[i][l] != -1) {
                    f[l][j + up[i][l]][k + down[i][l]] = true;
                    p[l][j + up[i][l]][k + down[i][l]] = i;
                }
            }

        u = 0, d = 0, good = 1;
        for (int j = i + 1; j < n; ++j) {
            if (a[i].y == a[j].y) {
                good = 0;
                break;
            }
            if (a[j].y > a[i].y) ++u;else ++d;
        }
        if (good) {
            for (int j = 0; j <= i; ++j)
                for (int k = 0; j + k <= i; ++k) if (f[i][j][k]) {
                    int b1 = j + u;
                    int b2 = k + d;
                    int b3 = n - b1 - b2;
                    int score = max(max(b1, b2), b3) - min(min(b1, b2), b3);
                    if (score < bestscore) {
                        bestscore = score;
                        besti = i;
                        bestj = j;
                        bestk = k;
                    }
                }
        }
    }

    vector<int> ans;

    while (p[besti][bestj][bestk] != -1) {
        ans.push_back(besti);
        int previ = p[besti][bestj][bestk];
        bestj -= up[previ][besti];
        bestk -= down[previ][besti];
        besti = previ;
    }
    ans.push_back(besti);
    
    cout << ans.size() << endl;
    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        cout << a[ ans[i] ].i << " ";
    }
    cout << endl;
    
    return 0;
}
