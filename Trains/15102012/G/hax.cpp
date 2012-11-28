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

const int N = 5555;

int n, k, m, color[N];
vector<int> g[N];
int d[N];
vector<pair<int, int> > order;

int mex[22];
bool matrix[22][22];

int cycle[22];

int main() {
    freopen("galaxy.in", "r", stdin);
    freopen("galaxy.out", "w", stdout);
    
    scanf("%d%d%d", &n, &k, &m);
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);

        if (x <= k && y <= k) matrix[x][y] = matrix[y][x] = true;
    }

    for (int i = 0; i < k; ++i) cycle[i] = i + 1;
    do {
        bool cool = true;
        for (int i = 0; i < k; ++i)
            if (!matrix[ cycle[i] ][ cycle[(i + 1) % k] ]) {
                cool = false;
                break;
            }
        if (cool) {
            for (int i = 0; i < k; ++i)
                color[ cycle[i] ] = i + 1;
            break;
        }
    } while (next_permutation(cycle, cycle + k));

    memset(d, 63, sizeof(d));
    queue<int> q;
    for (int i = 1; i <= k; ++i) { 
        d[i] = 0;
        q.push(i);
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < g[x].size(); ++i)
            if (d[ g[x][i] ] > d[x] + 1) {
                d[ g[x][i] ] = d[x] + 1;
                q.push(g[x][i]);
            }
    }
    for (int i = k + 1; i <= n; ++i) {
        pair<int, int> c;
        c.first = d[i];
        c.second = i;
        order.push_back(c);
    }
    sort(order.begin(), order.end());

    for (int j = 0; j < order.size(); ++j) {
        int x = order[j].second;
        memset(mex, 0, sizeof(mex));
        
        for (int i = 0; i < g[x].size(); ++i)
            mex[ color[ g[x][i] ] ] = true;

        mex[0] = mex[k];
        for (int i = 0; i < k; ++i)
            if (!mex[i] && mex[(i + 1) % k]) {
                color[x] = i;
                if (i == 0) color[x] = k;
                break;
            }
    }

    for (int i = 1; i <= n; ++i) 
        printf("%d ", color[i]);
    cout << endl;

    return 0;
}
