#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

struct cell {
    ll x, y;
    int id;

    cell(ll ax, ll ay, int aid = 0)
        : x(ax)
        , y(ay)
        , id(aid)
    {}

    bool operator <(const cell& A) const {
        return x < A.x || (x == A.x && y < A.y);
    }
};

bool cw(cell a, cell b, cell c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
} 
bool ccw(cell a, cell b, cell c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
} 

void convex_hull(vector<cell>& a) {
    if (a.size() < 3) return;
    sort(a.begin(), a.end());
    cell p0 = a[0], pn = a.back();

    vector<cell> up, down;
    up.push_back(p0);
    down.push_back(p0);
    for (size_t i = 1; i < a.size(); ++i) {
        if (i + 1 == a.size() || cw(p0, a[i], pn)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i])) {
                up.pop_back();
            }
            up.push_back(a[i]);
        }
        if (i + 1 == a.size() || ccw(p0, a[i], pn)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i])) {
                down.pop_back();
            }
            down.push_back(a[i]);
        }
    }
    a = up;
    for (int i = down.size() - 2; i >= 0; --i) a.push_back(down[i]);
}

const int N = 1000111;
vector<int> g[N];
ll x[N], y[N], z[N];

ll sqr(ll x) {
    return x * x;
}
ll dis2(int id1, int id2) {
    return sqr(x[id1] - x[id2]) + sqr(y[id1] - y[id2]) + sqr(z[id1] - z[id2]);
}

int cl[N];

void dfs(int x, int color) {
    cl[x] = color;
    for (int i = 0; i < g[x].size(); ++i)
        if (cl[ g[x][i] ] == -1) {
            dfs(g[x][i], 1 - color);
        }
}

int sign(ll x) {
    if (x < 0) return -1;
    if (x == 0) return 0;
    return 1;
}

ll myabs(ll x) { if (x < 0) return -x; return x;}
ll baddist(ll x, ll y, ll A, ll B, ll C) {
    return myabs(A * x + B * y + C);
}
ll baddist(ll x, ll y, ll x1, ll y1, ll x2, ll y2) {
    ll A = y1 - y2;
    ll B = x2 - x1;
    return baddist(x, y , A, B, -A * x1 - B * y1);
}

ll bestd = -1;
vector< pair<int, int> > edges;
vector<cell> a;

void relax(int x, int y) {
    ll dist = dis2(a[x].id, a[y].id);
    if (dist > bestd) {
        bestd = dist;
        edges.clear();
    }
    if (dist == bestd) {
        edges.push_back(make_pair(x, y));
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        edges.clear();
        bestd = -1;
        int n;
        scanf("%d", &n);
        a.clear();
        for (int i = 0; i < n; ++i) {
            int ax, ay, az;
            scanf("%d%d%d", &ax, &ay, &az);
            x[i] = ax;
            y[i] = ay;
            z[i] = az;
            a.push_back(cell(x[i], y[i], i));           
        }

        if (a.size() == 1) {
            puts("NIE");
            continue;
        }

        convex_hull(a);
        int m = a.size();
        if (m > 10000) {
            int pos = 0;
            ll bestd = 0;
            for (int i = 0; i < m; ++i) {
                if (baddist(a[i].x, a[i].y, a[0].x, a[0].y, a[1].x, a[1].y) >= bestd) {
                    pos = i;
                    bestd = dis2(a[i].id, a[0].id);
                }
            }
            relax(0, pos);
            relax(1, pos);
            relax(0, (pos + 1) % m);
            relax(1, (pos + 1) % m);
            relax(0, (pos + m - 1) % m);
            relax(1, (pos + m - 1) % m);

            ll curd = bestd;
            for (int i = 1; i < m; ++i) {
                int nxt = (i + 1) % m;
                while (true) {
                    int npos = (pos + 1) % m;
                    ll cand = baddist(a[npos].x, a[npos].y, a[i].x, a[i].y, a[nxt].x, a[nxt].y);
                    if (cand >= curd) {
                        curd = cand;
                        pos = npos;
                    } else break;
                } 

                relax(i, (pos + m - 1) % m);
                relax(nxt, (pos + m - 1) % m);
                relax(i, pos);
                relax(nxt, pos);
                relax(i, (pos + 1) % m);
                relax(nxt, (pos + 1) % m);
            }
        } else {
            for (int i = 0; i < m; ++i)
                for (int j = i + 1; j < m; ++j)
                    relax(i, j);
        }

        for (int i = 0; i < n; ++i) { 
            g[i].clear();
            cl[i] = -1;
        }
        for (int i = 0; i < edges.size(); ++i) {
            g[ edges[i].first ].push_back( edges[i].second );
            g[ edges[i].second].push_back( edges[i].first );
        }

        for (int i = 0; i < n; ++i)
            if (cl[i] == -1) {
                dfs(i, 0);
            }

        bool cool = true;
        for (int i = 0; cool && i < n; ++i)
            for (int j = 0; j < g[i].size(); ++j)
                if (cl[i] == cl[ g[i][j] ]) {
                    cool = false;
                    break;
                }
        if (cool) puts("TAK");
        else puts("NIE");
    }

    return 0;
}