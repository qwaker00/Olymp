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

const int N = 205;

const int MOD = 1000000007;

int c[N*3][N*3];
int f[N][N * 2][N * 2];

int myabs(int x) {
    if (x < 0) return -x;
    return x;
}

int dist(int x1, int y1, int x2, int y2) {
    return myabs(x1 - x2) + myabs(y1 - y2);
}

int n, m;

vector<int> g[N][N * 4];
int d[N][N];
int cdist[N][N], ndist[N*N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};


int main() {
    freopen("kitten.in", "r", stdin);
    freopen("kitten.out", "w", stdout);
    
    for (int i = 0; i <= 202; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }

    int x1, x2, x3, y1, y2, y3;
    cin >> n >> m;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    
    if (x1 == x2 && x2 == x3 && !((y1 < y2 && y2 < y3) || (y1 > y2 && y2 > y3))) {
        int ans = 0;
        if (x1 > 1) ++ans;
        if (x1 + 1 <= n) ++ans;
        cout << ans * dist(x1, y1, x3, y3) << endl;
        return 0;   
    }
    if (y1 == y2 && y2 == y3 && !((x1 < x2 && x2 < x3) || (x1 > x2 && x2 > x3))) {
        int ans = 0;
        if (y1 > 1) ++ans;
        if (y1 + 1 <= m) ++ans;
        cout << ans * dist(x1, y1, x3, y3) << endl;
        return 0;    
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cdist[i][j] = ndist[dist(i, j, x2, y2)]++;
            //cerr << dist(i, j, x2, y2) << " ";    
        }
        //cerr << endl;
    }

    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) {
            int curdist = dist(x2, y2, i, j);
            for (int q = 0; q < 4; ++q)
                if (i + dx[q] <= n && i + dx[q] >= 1 && j + dy[q] <= m && j + dy[q] >= 1 && dist(i + dx[q], j + dy[q], x2, y2) > curdist) {
                    g[curdist][ cdist[i][j] ].push_back(cdist[i + dx[q]][j + dy[q]]);
                    //cerr << i << " " << j << " --> " << i + dx[q] << " " << j + dy[q] << endl;
                }
        }

    if (dist(x2, y2, x1, y1) > dist(x2, y2, x3, y3)) {
        swap(x1, x3);
        swap(y1, y3);
    }
    int lim = min(dist(x2, y2, x1, y1), dist(x2, y2, x3, y3));
    f[0][0][0] = 1;
    for (int level = 0; level < lim; ++level) {
        for (int i = 0; i < ndist[level]; ++i)
            for (int j = 0; j < ndist[level]; ++j)
                if (f[level][i][j])
                    for (int to1 = 0; to1 < g[level][i].size(); ++to1)
                        for (int to2 = 0; to2 < g[level][j].size(); ++to2) {
                            if (g[level][i][to1] != g[level][j][to2]) {
                                int& cf = f[level + 1][ g[level][i][to1] ][ g[level][j][to2] ];  
                                cf = (cf + f[level][i][j]) % MOD;
                            }    
                        }
    }

    //for (int level = 0; level < lim; ++level)
        //for (int i = 0; i < ndist[level]; ++i)
           // for (int j = 0; j < ndist[level]; ++j)
              //  cerr << level << " " << i << " " << j << ": " << f[level][i][j] << endl;

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (dist(i, j, x2, y2) == lim && lim + dist(i, j, x3, y3) == dist(x2, y2, x3, y3)) {
                ans = (LL(ans) + LL(f[lim][ cdist[x1][y1] ][ cdist[i][j] ]) * LL(c[dist(x3, y3, i, j)][myabs(x3 - i)])) % MOD;
            }
    cout << ans << endl;




    return 0;
}
