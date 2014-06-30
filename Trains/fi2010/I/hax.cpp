#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef unsigned long long ULL;


int A[555][555];
int minim[555][555][555];

int main() {
    freopen(".in", "r", stdin);

    int a, b, n, m;
    cin >> a >> b >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> A[i][j];
        }
        for (int j = 1; j <= m; ++j) {
            int mi = 2e9;
            for (int k = j; k <= m; ++k) {
                mi = min(mi, A[i][k]);
                minim[j][k][i] = mi;
            }
        }
    }

    int So = n * m;
    int ans = 0;
    for (int bb = 1; bb <= b || bb <= a; ++bb)  {
        for (int j = 1; j + bb - 1 <= m; ++j) {
            const int l = j;
            const int r = j + bb - 1;
            for (int i = 1; i <= n; ++i) {
                int mi = 2e9;
                for (int aa = 1; i + aa - 1 <= n && aa <= a || aa <= b; ++aa) if (aa <= a && bb <= b || aa <= b && bb <= a) {
                    mi = min(mi, minim[l][r][i + aa - 1]);
                    const int nu = mi * So;
                    const int denu = So - aa * bb;
                    const int V = ((nu - 1) / denu) * aa * bb;
                    if (V > ans)
                        ans = V;
                }
            }
        }
    }
    cout << ans << endl;


    return 0;
}
