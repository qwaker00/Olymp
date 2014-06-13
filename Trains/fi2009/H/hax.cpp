#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define V(x, y) (((x)*2) - ((y) == 'y'))
#define NOT(x)  ((((x)-1)^1)+1)

vector<int> g[444];
vector<int> gr[444];

inline void add(int x, int y) {
    g[x].push_back(y);
    g[NOT(y)].push_back(NOT(x));

    //cerr << x << " " << y << endl;
    //cerr << NOT(y) << " " << NOT(x) << endl;

    gr[y].push_back(x);
    gr[NOT(x)].push_back(NOT(y));
}

inline void rem(int x, int y) {
    g[x].pop_back();
    g[NOT(y)].pop_back();

    gr[y].pop_back();
    gr[NOT(x)].pop_back();
}

int was[444], IT = 0, v[444], vn = 0, c[444];

void dfs1(int x) {
    was[x] = IT;
    for (int i = 0; i < g[x].size(); ++i)
        if (was[g[x][i]] != IT)
            dfs1(g[x][i]);
    v[vn++] = x;
}

void dfs2(int x, int comp) {
    was[x] = IT;
    c[x] = comp;
    for (int i = 0; i < gr[x].size(); ++i)
        if (was[gr[x][i]] != IT)
            dfs2(gr[x][i], comp);
}

bool check(int n) {
    ++IT;

    for (int i = 0; i <= n * 2; ++i) c[i] = i;

    vn = 0;
    for (int i = 0; i <= n * 2; ++i)
        if (was[i] != IT) {
            dfs1(i);
        }
    ++IT;
    int comp = 0;
    for (int i = vn - 1; i >= 0; --i)
        if (was[v[i]] != IT)
            dfs2(v[i], ++comp);

    for (int i = 1; i <= n; ++i)
        if (c[V(i, 'y')] == c[V(i, 'n')]) {
            //cerr << "bad " << i << endl;
            return false;
        }
    return true;
}

int main() {
    freopen("major.in", "r", stdin);
    //freopen(".out", "w", stdout);

    int __it = 0;
    while (1) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < m; ++i) {
            int k;
            scanf("%d", &k);

            int vx[4];
            char vy[4];
            for (int j = 0; j < k; ++j) {
                scanf("%d %c", &vx[j], &vy[j]);
            }
            for (int j = 0; j < k; ++j) {
                int x = V(vx[j], vy[j]);
                if (k < 3) {
                    add(NOT(x), x);
                } else {
                    for (int jj = 0; jj < k; ++jj) if (jj != j) {
                        add(NOT(x), V(vx[jj], vy[jj]));
                    }
                }
            }
        }

        ++__it;
        printf("Case %d: ", __it);
        if (!check(n)) {
            puts("impossible");
        } else {
            for (int i = 1; i <= n; ++i) {
                add(V(i, 'n'), V(i, 'y'));
                //cerr << "check " << i << " " << 'y' << endl;
                int ay = check(n);
                rem(V(i, 'n'), V(i, 'y'));

                add(V(i, 'y'), V(i, 'n'));
                //cerr << "check " << i << " " << 'n' << endl;
                int an = check(n);
                rem(V(i, 'y'), V(i, 'n'));

                if (ay && an)
                    putchar('?');
                else
                    if (ay)
                        putchar('y');
                    else
                        putchar('n');
            }
            puts("");
        }

        for (int i = 1; i <= n; ++i) {
            gr[i*2].clear();
            gr[i*2-1].clear();
            g[i*2].clear();
            g[i*2-1].clear();
        }
    }

    return 0;
}
