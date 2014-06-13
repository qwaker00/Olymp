#include <cstdio>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

typedef long long LL;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n);
        for (int i  = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

/*        {
            vector<int> b(n * 50);
            vector<char> c(n * 50);
            for (int i = 0; i < 50; ++i)
                for (int j = 0; j < n; ++j)
                    b[i * n + j] = a[j];
            char ch = 'a';
            for (int i = 0; i < 50 * n; ++i) {
                if (c[i] == 0)
                    c[i] = ch++;
                putchar(c[i]);
                fflush(stdout);
                if (i + b[i] < 50 * n) {
                    assert(c[i + b[i]] == 0);
                    c[i + b[i]]= c[i];
                }
            }
            puts("");
        }
        return 0;
*/

        LL ans = 0;
        bool bad = 0;
        vector<int> was(n);
        for (int i = 0; i < n; ++i) if (!was[i]) {
            LL sum = 0, j = i;
            while (!was[j]) {
                was[j] = 1;
                sum += a[j];
                j = (j + a[j]) % n;
            }
            if (j != i) {
                bad = 1;
                break;
            }
            ans += sum / n;
        }
        if (bad) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
