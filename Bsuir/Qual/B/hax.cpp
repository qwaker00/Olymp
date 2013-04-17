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

int ma1[333][333];//, mi1[333][333];
int ma2[333][333];//, mi2[333][333];
int ma3[333][333];//, mi3[333][333];
int ma4[333][333];//, mi4[333][333];

int ma[333][333];//, mi[333][333];
int a[333][333], s[333][333];
int n, m, k;
int xx[333], yy[333], mx[333], my[333];

#define GetS(x,y,w,h) (s[x + w - 1][y + h - 1] - s[x - 1][y + h - 1] - s[x + w - 1][y - 1] + s[x - 1][y - 1])

int mstyle;

void BuildMax(int dx, int dy) {
    if (dx * dy <= 16) {
        mstyle = 1;        
        memcpy(ma1, ma, sizeof(ma));
    } else {
    mstyle = 0;

    for (int i = 1; i <= n + 1; ++i) mx[i] = (i - 1) % dx;
    for (int i = 1; i <= m + 1; ++i) my[i] = (i - 1) % dy;
    mx[0] = my[0] = mx[n + 1] = my[m + 1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            ma1[i][j] = ma[i][j];
            if (mx[i] && ma1[i - 1][j] > ma1[i][j]) ma1[i][j] = ma1[i - 1][j];
            if (my[j] && ma1[i][j - 1] > ma1[i][j]) ma1[i][j] = ma1[i][j - 1];
        }
        for (int j = m; j > 0; --j) {
            ma2[i][j] = ma[i][j];
            if (mx[i] && ma2[i - 1][j] > ma2[i][j]) ma2[i][j] = ma2[i - 1][j];
            if (my[j + 1] && ma2[i][j + 1] > ma2[i][j]) ma2[i][j] = ma2[i][j + 1];
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; ++j) {
            ma3[i][j] = ma[i][j];
            if (mx[i + 1] && ma3[i + 1][j] > ma3[i][j]) ma3[i][j] = ma3[i + 1][j];
            if (my[j] && ma3[i][j - 1] > ma3[i][j]) ma3[i][j] = ma3[i][j - 1];
        }
        for (int j = m; j > 0; --j) {
            ma4[i][j] = ma[i][j];
            if (mx[i + 1] && ma4[i + 1][j] > ma4[i][j]) ma4[i][j] = ma4[i + 1][j];
            if (my[j + 1] && ma4[i][j + 1] > ma4[i][j]) ma4[i][j] = ma4[i][j + 1];
        }
    }
    }
}

void BuildMin(int dx, int dy) {
    if (dx * dy <= 16) {
        mstyle = 1;        
        memcpy(ma1, ma, sizeof(ma));
    } else {
    mstyle = 0;

    for (int i = 1; i <= n + 1; ++i) mx[i] = (i - 1) % dx;
    for (int i = 1; i <= m + 1; ++i) my[i] = (i - 1) % dy;
    mx[0] = my[0] = mx[n + 1] = my[m + 1] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; ++j) {
            ma1[i][j] = ma[i][j];
            if (mx[i] && ma1[i - 1][j] < ma1[i][j]) ma1[i][j] = ma1[i - 1][j];
            if (my[j] && ma1[i][j - 1] < ma1[i][j]) ma1[i][j] = ma1[i][j - 1];
        }
        for (int j = m; j > 0; --j) {
            ma2[i][j] = ma[i][j];
            if (mx[i] && ma2[i - 1][j] < ma2[i][j]) ma2[i][j] = ma2[i - 1][j];
            if (my[j + 1] && ma2[i][j + 1] < ma2[i][j]) ma2[i][j] = ma2[i][j + 1];
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= m; ++j) {
            ma3[i][j] = ma[i][j];
            if (mx[i + 1] && ma3[i + 1][j] < ma3[i][j]) ma3[i][j] = ma3[i + 1][j];
            if (my[j] && ma3[i][j - 1] < ma3[i][j]) ma3[i][j] = ma3[i][j - 1];
        }
        for (int j = m; j > 0; --j) {
            ma4[i][j] = ma[i][j];
            if (mx[i + 1] && ma4[i + 1][j] < ma4[i][j]) ma4[i][j] = ma4[i + 1][j];
            if (my[j + 1] && ma4[i][j + 1] < ma4[i][j]) ma4[i][j] = ma4[i][j + 1];
        }
    }
    }
}

int GetMax(int x, int y, int lx, int ly) {
    if (mstyle) {
        int ans = -2e9;
        for (int i = 0; i < lx; ++i)
            for (int j = 0; j < ly; ++j)
                ans = max(ans, ma1[i + x][j + y]);
        return ans;
    }
    return max(max(ma1[x + lx - 1][y + ly - 1], ma4[x][y]), max(ma2[x + lx - 1][y], ma3[x][y + ly - 1]));
}
int GetMin(int x, int y, int lx, int ly) {
    if (mstyle) {
        int ans = 2e9;
        for (int i = 0; i < lx; ++i)
            for (int j = 0; j < ly; ++j)
                ans = min(ans, ma1[i + x][j + y]);
        return ans;
    }
    return min(min(ma1[x + lx - 1][y + ly - 1], ma4[x][y]), min(ma2[x + lx - 1][y], ma3[x][y + ly - 1]));
//    int ans = 2e9;
//    for (int i = 0; i < lx; ++i)
//        for (int j = 0; j < ly; ++j)
//            ans = min(ans, mi2[i + x][j + y]);
//    return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);    

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    cin >> k;
    xx[0] = n;
    yy[0] = m;
    for (int i = 1; i <= k; ++i) {
        cin >> xx[i] >> yy[i];        
    }

    for (int i = 1; i + xx[k] <= n + 1; ++i) 
        for (int j = 1; j + yy[k] <= m + 1; ++j)
            ma[i][j] = /*mi[i][j] = */GetS(i, j, xx[k], yy[k]);
             
    for (int it = k - 1; it >= 0; it--) {
        int dx = xx[it] - xx[it + 1] + 1;
        int dy = yy[it] - yy[it + 1] + 1;
        if (it & 1) {
            BuildMin(dx, dy);
            for (int i = 1; i + xx[it] <= n + 1; ++i)
                for (int j = 1; j + yy[it] <= m + 1; ++j)
                   ma[i][j]  = GetS(i, j, xx[it], yy[it]) - GetMin(i, j, dx, dy);
        } else {
            BuildMax(dx, dy);
            for (int i = 1; i + xx[it] <= n + 1; ++i)
                for (int j = 1; j + yy[it] <= m + 1; ++j)
                    ma[i][j]  = GetS(i, j, xx[it], yy[it]) - GetMax(i, j, dx, dy);
        }
    }
    cout << GetS(1, 1, n, m) - ma[1][1] << endl;

//    cerr << clock() << endl;  
    return 0;
}
