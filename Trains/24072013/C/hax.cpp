#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

int was[5555];
int deg[5555], N;
vector<int> g[5555];
vector<int> ans;

int bits(int x) {
    int ans = 0;
    while (x) {
        ++ans;
        x &= x - 1;
    }
    return ans;
}

bool dfs(int x, vector<int>& ans) {
//    cerr << x << endl;

    was[x] = true;
    ans.push_back(x);
    if (ans.size() == (1 << N)) return true;

    vector< pair<int, int> > nei;
    for (int i = 0; i < g[x].size(); ++i) {
        if (!was[g[x][i]]) {
            nei.push_back(make_pair(-deg[ g[x][i] ], g[x][i]));
        }
    }
    if (nei.size()) {
        sort(nei.begin(), nei.end());
        for (int i = 0; i < nei.size(); ++i) {
            --deg[x];
            --deg[nei[i].second];
            if (dfs(nei[i].second, ans)) return true;
            ++deg[x];
            ++deg[nei[i].second];
        }
    }

    was[x] = false;
    ans.pop_back();
//    cerr << -x << endl;
    return false;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    for (int n = 2; n <= 12; ++n) {
        cerr << "N: " << n << endl;
        N = n;
        ans.clear();
        for (int i = 0; i < (1 << n); ++i) deg[i] = 0, was[i] = 0, g[i].clear();
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                if (bits(i ^ j) >= n / 2) {
                    g[i].push_back(j);
                    ++deg[i];
    //                cerr << i << " " << j << endl;
                }
            }
        }
        for (int i =0; i < (1 << n); ++i) if (!was[i]) {
//            cerr << "Enter " << i << endl;
            dfs(i, ans);
        }

        for (int i = 1; i < ans.size(); ++i) {
            if (bits(ans[i - 1] ^ ans[i]) < n / 2) {
                throw 1;
            }
        }
        if (bits(ans[ans.size() - 1] ^ ans[0]) < n / 2) {
            throw 1;
        }
        for (int i=  0; i < (1 << n); ++i)  {
            int x = ans[i];
            for (int j =0 ; j < n; ++j) putchar('0' + ((x & (1 << j)) > 0));
            puts("");
        }
    }
    
    return 0;
}
