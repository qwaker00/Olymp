#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

int an = 0;
pair<int, pair<int, char> > a[666];
int f[1000111][8], was[1000111];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int s = 1;
    for (int i = 2; s <= 1000000; ++i) {
        s += i * i;
        a[an++] = make_pair(s, make_pair(i, 'H'));
    }
    s = 1;
    for (int i = 3; s <= 1000000; i += 2) {
        s += i * i;
        a[an++] = make_pair(s, make_pair(i, 'L'));
    }
    s = 4;
    for (int i = 4; s <= 1000000; i += 2) {
        s += i * i;
        a[an++] = make_pair(s, make_pair(i, 'L'));
    }
    sort(a, a + an);

    for (int i = 1; i < an; ++i)
        assert(a[i - 1].first != a[i].first);

    int maxs = 0;
    f[0][7] = 1;
    for (int i = 0; i < an; ++i) {
        int x = a[i].first;
        maxs = min(1000000, maxs + x);
        for (int j = maxs; j >= x; --j)
            if (f[j - x][7] && (f[j][7] == 0 || f[j - x][7] + 1 <= f[j][7])) {
                for (int k = 6; k > 0; --k)
                    f[j][k] = f[j][k - 1];
                f[j][0] = i + 1;
                f[j][7] = f[j - x][7] + 1;
            }
    }
//  cerr << double(clock()) / CLOCKS_PER_SEC << endl;
//  cerr << an << endl;

    int __it = 0;
    while (1) {
        int n;
        scanf("%d", &n);
//        n = __it + 1;
        if (n == 0) break;
//        if (n > 1000000) break;

        __it++;
        printf("Case %d:", __it);
        if (!f[n][7])  {
            puts(" impossible");
        } else {
            vector<int> cl;
            int last = -1;
            while (n) {
                int cc = 0;
                while (was[f[n][cc]]) ++cc;

                assert(f[n][cc] > 0 && !was[f[n][cc]]);

                was[f[n][cc]] = 1;
                printf(" %d%c", a[f[n][cc] - 1].second.first, a[f[n][cc] - 1].second.second);
                last = f[n][cc];
                cl.push_back(last);

                n -= a[f[n][cc] - 1].first;
            }
            puts("");

            assert(cl.size() <= 6);
            for (int i = 0; i < cl.size(); ++i) was[cl[i]] = 0;
        }
    }


    return 0;
}

