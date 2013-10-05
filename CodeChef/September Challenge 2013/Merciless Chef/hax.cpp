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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111

vector<int> g[N];
int n, m, t, x, y;
int a[N], an = 0;
int start[N];
int finish[N];
int health[N];

struct Tp {
    int l, r, add, topush;
    vector<int> h;
} A[N + N + N];

void dfs(int x) {
    a[an++] = x;
    start[x] = an;
    for (size_t i = 0; i < g[x].size(); ++i) {
        dfs(g[x][i]);
    }
    finish[x] = an - 1;
}

void Init(int x, int l, int r) {
    A[x].l = l, A[x].r = r;
    A[x].add = 0;
    if (l < r) {
        Init(x + x, l, (l + r) >> 1);
        Init(x + x + 1, (l + r + 2) >> 1, r);
        A[x].h.resize(r - l + 1);
        merge(A[x + x].h.begin(), A[x + x].h.end(), A[x + x + 1].h.begin(), A[x + x + 1].h.end(), A[x].h.begin(), greater<int>());
    } else {
        A[x].h.push_back(health[l]);
    }
}

void Modify(int x, int l, int r, int y) {
    if (r < A[x].l || l > A[x].r) return;
    if (l <= A[x].l && r >= A[x].r) {
        A[x].topush += y;
    }
    Modify(x + x, l, r, y);
    Modify(x + x + 1, l, r, y);
}

int Count(int x, int l, int r) {
    if (r < A[x].l || l > A[x].r || A[x].h.empty()) return 0;
    if (A[x].topush) {
        A[x].add += A[x].topush;
        A[x + x].topush += A[x].topush;
        A[x + x + 1].topush += A[x].topush;
        A[x].topush = 0;
    }
    if (l <= A[x].l && r >= A[x].r) {
        while (!A[x].h.empty() && A[x].h.back() <= A[x].add) A[x].h.pop_back();
        return A[x].h.size();
    }
    return Count(x + x, l, r) + Count(x + x + 1, l, r);
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int p;
        scanf("%d%d", &health[i], &p);
        g[p].push_back(i);
    }
    dfs(0);
    Init(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &x, &y);
            Modify(1, start[x], finish[x], y);
        } else {
            scanf("%d", &x);
            printf("%d\n", Count(1, start[x], finish[x]));
        }        
    }
    
    return 0;
}
