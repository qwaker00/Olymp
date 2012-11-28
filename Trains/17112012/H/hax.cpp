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

int n;
int d[N];

vector<int> g[N];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    memset(d, 63, sizeof(d));
    int n, h, m;
    cin >> n >> h >> m;
    queue<int> q;
    while (h--) {
        int x;
        cin >> x;
        q.push(x);
        d[x] = 0;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < g[x].size(); ++i)
            if (d[ g[x][i] ] > d[x] + 1) {
                d[ g[x][i] ] = d[x] + 1;
                q.push(g[x][i]);
            }
    }

    int best = 0;
    for (int i = 0; i < n; ++i)
        if (d[i] > d[best]) best = i;

    cout << best << endl;
    
    return 0;
}
