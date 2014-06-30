#include <iostream>
#include <cstdio>
#include <memory.h>
#include <assert.h>
#include <algorithm>

using namespace std;

pair<long long, long long> a[333][333];

int main() {
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    memset(a, 63, sizeof(a));
    for (int i = 0; i < m; ++i) {
        int x, y;
        long long c;
        cin >> x >> y >> c;
        a[x][y].first = min(a[x][y].first, c);
        a[y][x].first = min(a[y][x].first, c);
        a[x][y].second = 1;
        a[y][x].second = 1;
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                pair<long long, long long> b = make_pair(a[i][k].first + a[k][j].first, a[i][k].second + a[k][j].second);
                if (b < a[i][j]) a[i][j] = b;
            }
    long long sum = 0, c = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            sum += a[i][j].second;
            ++c;
        }
    }
    cout.precision(10);
    cout << fixed << ((long double)sum) / c << endl;
    return 0;
}
