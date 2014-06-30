#include <iostream>
#include <cstdio>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>
#include <cstdlib>
#include <vector>

using namespace std;

struct Tp {
    int x, y;
} man[2222];
int n, m, k, s;
int b[22][22];

struct Te {
    int x, y, f, c;
} e[222222];
int en = 0;
vector<int> g[22222];
int D[22222], st[22222], P[22222];
int best[22222], was[22222];

void add(int x, int y, int f, int c) {
    //cerr << x << " " << y << " " << f << " " << c << endl;

    e[en].x = x;
    e[en].y = y;
    e[en].f = f;
    e[en].c = c;
    g[x].push_back(en);
    ++en;

    e[en].x = y;
    e[en].y = x;
    e[en].f = 0;
    e[en].c = -c;
    g[y].push_back(en);
    ++en;
}

vector<int> out;
int wasit[22222], IT = 0;

bool dfs(int mani) {
    if (was[mani]) return true;
    if (wasit[mani] == IT) return true;
    wasit[mani] = IT;

    pair<int, pair<int, int> > bestp = make_pair(2e9, make_pair(-1, -1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) if (!b[i][j]) {
            pair<int, pair<int, int> > p = make_pair( abs(i - man[mani].x) + abs(j - man[mani].y), make_pair(i, j) );
            if (p < bestp) {
                bestp = p;
            }
        }
    }

    int fid = (bestp.second.first - 1) * m + bestp.second.second;
    if (best[fid] == 0 || dfs(best[fid])) {
        if (!b[bestp.second.first][bestp.second.second]) {
            b[bestp.second.first][bestp.second.second] = 1;
            was[mani] = 1;
            out.push_back(mani);
            return true;
        }
    }

    return false;
}

int main() {
    freopen("agrarian.in", "r", stdin);
    freopen("agrarian.out", "w", stdout);

    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (int i = 1; i <= k; ++i) {
        scanf("%d%d", &man[i].x, &man[i].y);
        b[man[i].x][man[i].y] = 1;
    }
    for (int i = 0; i < s; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        b[x][y] = 1;
    }

    int S = 0;
    int F = k + n * m + 1;
    for (int i = 1; i <= k; ++i) {
        add(0, i, 1, 0);
        for (int j = 1; j <= n; ++j)
            for (int jj = 1; jj <= m; ++jj)
                if (!b[j][jj]) {
                    add(i, (j - 1) * m + jj + k, 1, abs(man[i].x - j) + abs(man[i].y - jj));
                }
    }
    for (int j = 1; j <= n; ++j)
        for (int jj = 1; jj <= m; ++jj)
            if (!b[j][jj]) {
                add((j - 1) * m + jj + k, F, 1, 0);
            }

    while (true) {
        deque<int> q;
        for (int i = S; i <= F; ++i) {
            D[i] = 1e9;
            st[i] = 0;
        }
        q.push_back(S);
        D[S] = 0;
        st[S] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop_front();
            st[x] = 2;
            for (int i = 0; i < (int)g[x].size(); ++i) {
                const Te& E = e[g[x][i]];
                if (E.f > 0 && D[E.y] > D[x] + E.c) {
                    D[E.y] = D[x] + E.c;
                    P[E.y] = g[x][i];
                    if (st[E.y] == 0) {
                        q.push_back(E.y);
                    } else
                        if (st[E.y] == 2) {
                            q.push_front(E.y);
                        }
                    st[E.y] = 1;
                }
            }
        }
        if (D[F] >= 1e9) break;
        int x = F;
        while (x != S) {
            --e[P[x]].f;
            ++e[P[x] ^ 1].f;
            x = e[P[x]].x;
        }
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < (int)g[i].size(); ++j) {
            if (e[g[i][j]].f == 0) {
                best[ e[g[i][j]].y - k ] = i;
                break;
            }
        }
    }

    while (out.size() < k) {
        for (int i = 1; i <= k; ++i) if (!was[i]) {
            ++IT;
            dfs(i);
        }
    }

    for (int i = 0; i < out.size(); ++i)
        cout << out[i] << " ";
    cout << endl;


    sort(out.begin(), out.end());
    assert(out.size() == k);
    for (int i = 0; i < out.size(); ++i)
        assert(out[i] == i + 1);

    return 0;
}
