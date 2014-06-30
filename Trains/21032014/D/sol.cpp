#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int N = 3003;
char s[N], w[N];
int B, C, I, D, ls, lw;
int f[N][N], best[N][N], p[N][N];
char ans[N*10];
const int INF = 2e9;

int main() {
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    //cerr << sizeof(f) * 3 + sizeof(ans) * 3<< endl;

    scanf("%d%d%d%d\n", &B, &I, &D, &C);
    gets(s);
    gets(w);
    ls = strlen(s);
    lw = strlen(w);

    for (int i = ls; i >= 0; --i) {
        for (int j = lw; j >= 0; --j) {
            if (i == ls && j == lw) {
                f[i][j] = 0;
                best[i][j] = i;
                continue;
            }
            f[i][j] = INF;
            if (i + 1 <= ls && f[i + 1][j] + D < f[i][j]) {
                f[i][j] = f[i + 1][j] + D;
                p[i][j] = -'D';
            }
            if (j + 1 <= lw && f[i][j + 1] + I < f[i][j]) {
                f[i][j] = f[i][j + 1] + I;
                p[i][j] = -'I';
            }
            if (i + 1 <= ls && j + 1 <= lw && s[i] == w[j] && f[i + 1][j + 1] + C < f[i][j]) {
                f[i][j] = f[i + 1][j + 1] + C;
                p[i][j] = -'C';
            }
            if (i + 1 <= ls && f[best[i + 1][j]][j] + B < f[i][j]) {
                f[i][j] = f[best[i + 1][j]][j] + B;
                p[i][j] = best[i + 1][j];
            }
            if (i == ls || f[best[i + 1][j]][j] > f[i][j])
                best[i][j] = i;
            else
                best[i][j] = best[i + 1][j];

//          cerr << i << " " << j << " " << f[i][j] << " " << -p[i][j] << endl;
        }
    }

    vector< pair<int, int> > r;
    int p1 = 0, p2 = 0, an = 0;
    while (p1 < ls || p2 < lw) {
        if (p[p1][p2] < 0) {
            ans[an++] = -p[p1][p2];
            if (p[p1][p2] == -'I') ++p2;else
                if (p[p1][p2] == -'D') ++p1;else
                {
                    ++p1;
                    ++p2;
                }
        } else {
            r.push_back(make_pair(p1 + 1, p[p1][p2]));
            p1 = p[p1][p2];
        }
    }

    printf("%d\n", f[0][0]);
    printf("%d\n", (int)r.size());
    for (int i = 0; i < (int)r.size(); ++i) {
        printf("%d %d\n", r[i].first, r[i].second);
    }

    ans[an] = 0;
    puts(ans);

    return 0;
}
