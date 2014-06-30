#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, k;
int S[1111][1111];
int mx = 0, maxc = 0;

int main() {
    freopen("bread.in", "r", stdin);
    freopen("bread.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        for (int j = x1; j < x2; ++j) {
            ++S[j][y1];
            --S[j][y2];
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            cur += S[i][j];
            if (cur > mx) {
                mx = cur;
                maxc = 1;
            } else if (cur == mx) {
                ++maxc;
            }
        }
    }
    printf("%d\n%d\n", mx, maxc);

    return 0;
}
