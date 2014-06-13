#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;


int dx[] = {0, 1, 1, 0, -1, -1, 0};
int dy[] = {0, 0, 1, 1,  0, -1, -1};
int posx[555], posy[555], id[555 * 2][555 * 2];


int bad[555];
int D[555][555];

#define NEW(x, y, i) do { id[x][y] = ++i; posx[i] = x; posy[i] = y; } while(false)
#define GO(i, d) id[posx[i] + dx[d]][posy[i] + dy[d]]

int main() {
    freopen("dogs.in", "r", stdin);
    freopen("dogs.out", "w", stdout);

    int x = 555, y = 555, i = 0, step = 0;

    NEW(x, y, i);
    while (i <= 500) {
        for (int p = 5; p >= 1; --p) {
            for (int j = 0; j < step && i <= 500; ++j) {
                x += dx[p];
                y += dy[p];
                NEW(x, y, i);
            }
        }
        if (i <= 500) {
            x += dx[1];
            y += dy[1];
            NEW(x, y, i);
        }
        for (int j = 0; j < step && i <= 500; ++j) {
            x += dx[6];
            y += dy[6];
            NEW(x, y, i);
        }
        ++step;
    }
//    cerr << posx[500] -555<< " " << posy[500]-555 << endl;

    int n, m, s1, t1, s2, t2;
    scanf("%d%d", &n, &m);
    while (n != 0 || m != 0) {

        memset(bad, 0, sizeof(bad));
        memset(D, 63, sizeof(D));

        scanf("%d%d%d%d", &s1, &t1, &s2, &t2);
        for (int i = 0; i < m; ++i) {
            int x;
            scanf("%d", &x);
            bad[x] = 1;
        }

        queue< pair<int, int> > q;
        q.push(make_pair(s1, s2));
        D[s1][s2] = 0;
        int ans = -1;
        while (!q.empty()) {
            pair<int, int> t = q.front(); q.pop();
            if (t.first == t1 && t.second == t2) {
                ans = D[t.first][t.second];
                break;
            }
            for (int d1 = 1; d1 <= 6; ++d1) {
                for (int d2 = 1; d2 <= 6; d2++)
                    if (d1 != d2) {
                        pair<int, int> y = make_pair(GO(t.first, d1), GO(t.second, d2));
                        if (y.first && !bad[y.first] && y.first <= n &&
                            y.second && !bad[y.second] && y.second <= n &&
                            y.first != y.second &&
                            D[y.first][y.second] > D[t.first][t.second] + 1)
                        {
                            D[y.first][y.second] = D[t.first][t.second] + 1;
//                            cerr << y.first << " " << y.second << endl;
                            q.push(y);
                        }
                    }
            }
        }
        if (ans == -1)
            puts("neda sa");
        else
            printf("%d\n", ans);

        scanf("%d%d", &n, &m);
    }

    return 0;
}
