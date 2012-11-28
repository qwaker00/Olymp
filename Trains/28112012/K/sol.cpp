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

const int N = 111111;

int d[N];
vector<int> g[N];
int n;
bool u[N];
int root;

vector< pair<int, int> > ans;


int cnt[N], fath[N];

int main() {
    freopen("kingdom.in", "r", stdin);
    freopen("kingdom.out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        d[x]++; d[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    root = 1;
    for (int i = 1; i <= n; ++i)
        if (d[i] > 1) { 
            root = i;
        }
    
    queue<int> pool;
    for (int i = 0; i < g[root].size(); ++i) { 
        pool.push(g[root][i]);
        u[ g[root][i] ] = 1;
        fath[ g[root][i] ] = root;
    }

    memset(cnt, -1, sizeof(cnt));

    int cool = root;
    while (pool.size() > 1) {
        int a = pool.front(); pool.pop();
        int b = fath[a];
        cerr << a << " from " << b << endl;

        if (cnt[b] == -1) {
            cnt[a] = b;
            cnt[b] = a; 
        } else {
            cnt[a] = cnt[b];
            cnt[ cnt[a] ] = a;
            cnt[b] = -1;  
        }

        
        for (int i = 0; i < g[a].size(); ++i) {
            if (!u[ g[a][i] ]) { pool.push(g[a][i]);
            u[ g[a][i] ] = true;
            fath[ g[a][i] ] = a;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i)
        if (cnt[i] != -1 && cnt[i] > i) ans.push_back(make_pair(i, cnt[i]));


    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}
