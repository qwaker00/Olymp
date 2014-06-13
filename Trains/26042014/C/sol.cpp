#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 1000111;
vector< pair<int, int> > a[N];
vector< pair<int, int> > b[N];
vector< pair<int, int> > cur;

int main() {
    int m, n, w;
    int it = 0;
    while (true) {
        ++it;
        scanf("%d%d%d", &m, &n, &w);
        if (m == 0 && n == 0 && w == 0) break;

        for (int i = 0; i < m; ++i) {
            a[i].clear();
            b[i].clear();
        }
        ll sq = ll(n) * ll(m);
        ll wallssq = 0;
        ll goodsq = 0;

        while (w--) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            wallssq += ll(x2 - x1 + 1) * ll(y2 - y1 + 1);
            a[y1].push_back(make_pair(x1, x2));
        }
        for (int i = 0; i < m; ++i)
            sort(a[i].begin(), a[i].end(), std::greater< pair<int, int> >());

        if (a[m - 1].size() > 0) {
            if (a[m - 1][0].second == n - 1) {
            } else {
                b[m - 1].push_back(make_pair(a[m - 1][0].second + 1, n - 1));
            }
        } else {
            b[m - 1].push_back(make_pair(0, n - 1));
        }


        for (int y = m - 1; y >= 0; --y) {
            if (b[y].empty()) {
                break;
            }
            for (int i = 0; i < b[y].size(); ++i) goodsq += b[y][i].second - b[y][i].first + 1;
            if (y == 0) break;

            cur.clear();
            {
                int to = n - 1;
                for (int i = 0; i < a[y - 1].size(); ++i) {
                    int from = a[y - 1][i].second + 1;
                    if (from <= to) {
                        cur.push_back(make_pair(from, to));
                    }
                    to = a[y - 1][i].first - 1;
                }
                int from = 0;
                if (from <= to) {
                    cur.push_back(make_pair(from, to));
                }
            }

            int pointer = 0;
            for (int i = 0; i < cur.size(); ++i) {
                while (pointer < b[y].size() && b[y][pointer].first > cur[i].second) ++pointer;
                if (pointer < b[y].size() && b[y][pointer].second >= cur[i].first) {
                    b[y - 1].push_back( make_pair(cur[i].first, min(cur[i].second, b[y][pointer].second)) );
                }
            }
        }

        printf("Case %d: %lld\n", it, sq - wallssq - goodsq);
    }

    return 0;
}

