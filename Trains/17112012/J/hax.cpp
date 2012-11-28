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

const int N = 1111;
const int M = 111;

int n;
int f[N][M];
int rn[N];

vector<int> g[N];
int cap[N];
int need[N];
int ans = 0;

void doit(int x) {
    for (int i = 0; i < g[x].size(); ++i) doit(g[x][i]);

    if (x == 0) {
        for (int i = 0; i < g[x].size(); ++i) {
            ans += rn[ g[x][i] ];
        }
    } else {
        f[x][ need[x] ] = 1;
        for (int q = 0; q < g[x].size(); ++q) {
            int y = g[x][q];
            for (int i = cap[x]; i >= 0; --i)
                for (int j = 0; j <= cap[y]; ++j)
                    if (i >= j && f[x][i] < f[x][i - j] + f[y][j]) {
                        f[x][i] = f[x][i - j] + f[y][j];
                    }
        }
        rn[x] = f[x][0];
        for (int i = 1; i <= cap[x]; ++i) rn[x] = max(rn[x], f[x][i]);

        //cout << "vertex " << x << endl;
        //for (int i = 0; i <= cap[x]; ++i)
          //  if (f[x][i] != 0) cout << "\tcan feed " << f[x][i] << " for " << i << endl;
    }
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int fath;
        cin >> fath >> need[i] >> cap[i];
        g[fath].push_back(i);
    }

    doit(0);
    cout << ans << endl;

    return 0;
}
