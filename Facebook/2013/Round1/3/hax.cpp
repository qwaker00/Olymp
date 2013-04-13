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
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


vector< pair<int, int> > add[44444];
vector< pair<int, int> > del[44444];
struct Tp {
    int l, r, add, val, cnt;
} A[444444];

void AddRect(int x, int y, int xx, int yy, int w, int h, int p, int q) {
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (xx > w - p) xx = w - p;
    if (yy > h - q) yy = h - q;
    add[y].push_back(make_pair(x, xx));
    del[yy].push_back(make_pair(x, xx));
//    cerr << "add " << x << " " << xx << endl;
}

void Init(int x, int l, int r) {
    A[x].l = l;
    A[x].r = r;
    A[x].val = 0;
    A[x].add = 0;
    A[x].cnt = r - l + 1;
    if (l < r) {
        Init(x + x, l, (l + r) >> 1);
        Init(x + x + 1, (l + r + 2) >> 1, r);
    }
}

void Add(int x, int l, int r, int y) {
    if (A[x].l > r || A[x].r < l) return;
    if (A[x].l >= l && A[x].r <= r) {
        A[x].add += y;
        return;
    }
    Add(x + x, l, r, y);
    Add(x + x + 1, l, r, y);
    A[x].val = min(A[x + x].val + A[x + x].add, A[x + x + 1].val + A[x + x + 1].add);
    A[x].cnt = ((A[x + x].val + A[x + x].add == A[x].val) ? A[x + x].cnt : 0) + 
               ((A[x + x + 1].val + A[x + x + 1].add == A[x].val) ? A[x + x + 1].cnt : 0);
}

int Zero() {
    if (A[1].val + A[1].add == 0)
        return A[1].cnt;
    return 0;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int it = 1; it <= T; ++it) {
        LL w, h, p, q, n, x, y, a, b, c, d;
        cin >> w >> h >> p >> q >> n >> x >> y >> a >> b >> c >> d;

        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; ++i) {
            AddRect(x - p + 1, y - q + 1, x, y, w, h, p, q);
            
            int nx = (x * a + y * b + 1) % w;
            int ny = (x * c + y * d + 1) % h;
            x = nx;
            y = ny;
        }

        int ans = 0;

        Init(1, 0, w - p);
        for (int i = 0; i <= h - q; ++i) {
            for (int j = 0; j < add[i].size(); ++j) {
                Add(1, add[i][j].first, add[i][j].second, 1);
            }
            add[i].clear();

            ans += Zero();

            for (int j = 0; j < del[i].size(); ++j) {
                Add(1, del[i][j].first, del[i][j].second, -1);
            }
            del[i].clear();
        }
        printf("Case #%d: %d\n", it, ans);
    }
    
    return 0;
}
