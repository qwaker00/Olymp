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

int n, x, y, was[55555];
vector<int> g[55555];

vector<int>* dfs(int x) {
    was[x] = 1;
    vector<int> *ans = NULL;
    for (size_t i = 0; i < g[x].size(); ++i) if (!was[g[x][i]]) {
        vector<int>* d = dfs(g[x][i]);
        if (!ans) ans = d;else
        if (d->size() > ans->size()) {
            int delta = d->size() - ans->size();
            for (size_t i = 0; i < ans->size(); ++i) {
                d->operator[](delta + i) += ans->operator[](i);
            }
            swap(ans, d);
            delete d;
        } else {
            int delta = ans->size() - d->size();
            for (size_t i = 0; i < d->size(); ++i) {
                ans->operator[](delta + i) += d->operator[](i);
            }
            delete d;
        }
    }
    if (!ans) ans = new vector<int>(1, 1);else ans->push_back(1);
    return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int>* d = dfs(2);
    for (int i = d->size() - 1; i >= 0; --i)
        cout << d->operator[](i) << endl;
    
    return 0;
}
