#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 77777;

vector< pair<int, int> > g[N];
int pi[N+N], po[N+N], timer = 0;
int p[N][18], d[N];

void dfs(int x, int pr = 0) {
    p[x][0] = pr;
    for (int j = 1; j < 18; ++j)
        p[x][j] = p[p[x][j - 1]][j - 1];
    d[x] = d[pr] + 1;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (g[x][i].first == pr) continue;
        pi[g[x][i].first] = ++timer;
        dfs(g[x][i].first, x);
        po[g[x][i].first] = ++timer;
    }
}

int lca(int x, int y) {
    if (d[x] > d[y]) for (int j = 17; j >= 0; --j) if (d[ p[x][j] ] >= d[y]) x = p[x][j];
    if (d[y] > d[x]) for (int j = 17; j >= 0; --j) if (d[ p[y][j] ] >= d[x]) y = p[y][j];
    if (x == y) return x;
    for (int j = 17; j >= 0; --j) if (p[x][j] != p[y][j]) {
        x = p[x][j];
        y = p[y][j];
    }
    return p[x][0];
}

struct Te {
    int t, x, y, z;
    Te(int t, int x, int y, int z) : t(t), x(x), y(y), z(z) {};
    Te() {};

    bool operator<(const Te& T) const {
        return z > T.z || z == T.z && t < T.t;
    }
} e[N+N];
int en = 0;


typedef long long LL;
LL S[N+N], C[N+N];
inline void add(LL* S, int x, int y) {
    while (x < N+N) {
        S[x] += y;
        x = (x | (x - 1)) + 1;
    }
}
inline LL sum(LL* S, int l, int r) {
    if (r < l) return 0;
    if (l > 0) return sum(S, 0, r) - sum(S, 0, l - 1);
    LL ans = 0;
    while (r) {
        ans += S[r];
        r &= r - 1;
    }
    return ans;
}

int main() {
    freopen("span.in", "r", stdin);
    freopen("span.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
        e[en++] = Te(1, x, y, z);
    }
    for (int i = n - 1; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        e[en++] = Te(0, x, y, z);
    }

    dfs(1);

    sort(e, e + en);
    LL ans = 0;
    for (int i = 0; i < en; ++i) {
        if (e[i].t == 1) {
            int x = e[i].x;
            int y = e[i].y;
            if (d[x] > d[y]) swap(x, y);
            add(S, pi[y], e[i].z);
            add(C, pi[y], 1);
            add(S, po[y], -e[i].z);
            add(C, po[y], -1);
        } else {
            int x = e[i].x;
            int y = e[i].y;
            int z = lca(x, y);
            LL Y = 0;
            LL K = 0;
            if (z != x) {
                Y += sum(S, pi[z] + 1, po[x] - 1);
                K += sum(C, pi[z] + 1, po[x] - 1);
            }
            if (z != y) {
                Y += sum(S, pi[z] + 1, po[y] - 1);
                K += sum(C, pi[z] + 1, po[y] - 1);
            }
            ans += Y - K * e[i].z;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
