#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;
const int N = 110;
double f[N][N];
int from[N][N];
double d[N][N];
int x[N], y[N];

int sqr(int x) {return x *x;}
int myabs(int x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    int it = 0;
    while (true) {
        ++it;
        int n, b1, b2;
        scanf("%d%d%d", &n, &b1, &b2);
        if (n == 0 && b1 == 0 && b2 == 0) break;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", x + i, y + i);
            for (int j = 0; j <= i; ++j) {
                d[i][j] = d[j][i] = sqrt(double(sqr(x[i] - x[j]) + sqr(y[i]-y[j])));
            }
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                f[i][j] = 1e100;
            }

        f[0][0] = 0;
        for (int i = 0; i + 1 < n; ++i)
            for (int j = 0; j + 1 < n; ++j) {
                int nxt = max(i, j) + 1;

                if (nxt != b1 && f[i][j] + d[i][nxt] < f[nxt][j]) {
                    f[nxt][j] = f[i][j] + d[i][nxt];
                    from[nxt][j] = -(i + 1);
                }
                if (nxt != b2 && f[i][j] + d[j][nxt] < f[i][nxt]) {
                    f[i][nxt] = f[i][j] + d[j][nxt];
                    from[i][nxt] = (j + 1);
                }
            }

        int bestx = -1, besty = -1;
        for (int i = 0; i < n; ++i)
            if (f[n - 2][i] < 1e99 && (bestx == -1 || f[n - 2][i] + d[n - 2][n - 1] + d[i][n - 1] < f[bestx][besty] + d[bestx][n - 1] + d[besty][n - 1])) {
                bestx = n - 2;
                besty = i;
            }
        for (int i = 0; i < n; ++i)
            if (f[i][n - 2] < 1e99 && (bestx == -1 || f[i][n - 2] + d[n - 2][n - 1] + d[i][n - 1] < f[bestx][besty] + d[bestx][n - 1] + d[besty][n - 1])) {
                bestx = i;
                besty = n - 2;
            }

        double ans = f[bestx][besty] + d[bestx][n - 1] + d[besty][n - 1];
        vector<int> a, b;
        a.push_back(bestx);
        b.push_back(besty);
        while (bestx != 0 || besty != 0) {
            int who = myabs(from[bestx][besty]) - 1;
            if (from[bestx][besty] < 0) {
                a.push_back(who);
                bestx = who;
            } else {
                b.push_back(who);
                besty = who;
            }
        }
        reverse(a.begin(), a.end());

        a.push_back(n - 1);
        a.insert(a.end(), b.begin(), b.end());
        if (a[1] != 1) {
            reverse(a.begin(), a.end());
        }

        long long t = ans * 1000;
        if (t % 10 >= 5) t += 10 - t % 10;
        ans = (double)t / 1000;

        printf("Case %d: %.2lf\n", it, ans);
        for (int i = 0; i < a.size(); ++i) printf("%d ", a[i]);
        puts("");
    }



    return 0;
}
