#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cassert>

using namespace std;
typedef long double LD;

struct Te {
    int x, y, c;
    bool operator<(const Te& t) const {
        return c < t.c;
    }
} e[222222];
int pr[222222];

int fs(int x) {
    if (x != pr[x]) pr[x] = fs(pr[x]);
    return pr[x];
}

int main() {
   // freopen(".in", "r", stdin);
   // freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    int it = 0;
    while(T--) {
        ++it;

        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].c);
        }
        sort(e, e + m);
        int mi = 0;
        int ma = 0;
        for (int i = 1; i <= n; ++i) pr[i] = i;
        for (int i = 0; i < m; ++i) {
            int x = fs(e[i].x);
            int y = fs(e[i].y);
            if (x != y) {
                mi += (e[i].c == 1);
                pr[x] = y;
            }
        }

        reverse(e, e + m);
        for (int i = 1; i <= n; ++i) pr[i] = i;
         for (int i = 0; i < m; ++i) {
            int x = fs(e[i].x);
            int y = fs(e[i].y);
            if (x != y) {
                ma += (e[i].c == 1);
                pr[x] = y;
            }
        }

        assert(mi <= ma);

        int bad = 0;
        for (int i = 1; i <= n; ++i) if (fs(i) != pr[1]) {
            bad = 1;
            break;
        }

        cout << "Case #" << it << ": ";
        if (bad) {
            cout << "No\n";
        } else {
            int f1 = 1, f2 = 1, ok = 0;
            while (f1 <= ma) {
                if (f1 >= mi && f1 <= ma) {
                    ok = 1;
                    break;
                }
                int f3 = f1 + f2;
                f2 = f1;
                f1 = f3;
            }
            if (ok)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}
