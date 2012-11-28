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

vector< vector<int> > leaves;

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

    int coolcnt = 0;
    int root = 1;
    for (int i = 1; i <= n; ++i)
        if (d[i] > 1) { 
            ++coolcnt;
            root = i;
        }

    //cerr << "root = " << root << endl;
    //cerr << "coolcnt = " << coolcnt << endl;
    if (coolcnt < 2) {
        cout << n / 2 << endl;
        for (int i = 1; i < n - 1; i += 2) {
            printf("%d %d\n", g[root][i], g[root][i - 1]);
        }
        if (!(n & 1)) {
            printf("%d %d\n", root, g[root].back());
        }
        return 0;
    }

    vector< pair<int, int> > ans;
    for (int i = 1; i <= n; ++i)
        if (d[i] != 1) {
            vector<int> c;
            for (int j = 0; j < g[i].size(); ++j)
                if (d[ g[i][j] ] == 1) {
                    c.push_back(g[i][j]);
                }
            while (c.size() > 2) {
                int x = c.back(); c.pop_back();
                int y = c.back(); c.pop_back();
                ans.push_back( make_pair(x, y) );
            }
            if (c.size() > 0) { 
                leaves.push_back(c);
                q.push( make_pair(c.size(), int(leaves.size()) - 1) );
            }
        }
    
    

    
    while (q.size() > 1) {
        pair<int, int> a = q.top(); q.pop();
        pair<int, int> b = q.top(); q.pop();

        int x = leaves[a.second].back(), y = leaves[b.second].back();
        leaves[a.second].pop_back();
        leaves[b.second].pop_back();

        ans.push_back( make_pair(x, y) );

        a.first--; b.first--;
        if (a.first > 0) q.push(a);
        if (b.first > 0) q.push(b);
    }

    if (q.size() > 0) {
        pair<int, int> a = q.top();
        for (int i = 0; i < leaves[a.second].size(); ++i) {
            ans.push_back(make_pair(root, leaves[a.second][i]));
        }
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}
