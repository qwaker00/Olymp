#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int w[1111111], s[1111111];
vector<int> g[1111111];

void dfs(int x) {
    w[x] = 1;
    s[x] = 0;
    priority_queue<int> q;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int y = g[x][i];
        dfs(y);
        w[x] += w[y];
        s[x] += s[y];
        q.push(-w[y]);
    }
    while (q.size() > 1) {
        int t1 = q.top(); q.pop();
        s[x] += -t1;
        int t2 = q.top(); q.pop();
        s[x] += -t2;
        q.push(t1 + t2);
    }
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    cin >> T;    
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 2; i <= n; ++i) {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
        dfs(1);
        cout << s[1] << endl;
    }
    
    return 0;
}
