#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int N = 1000111;
int a[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int m = 2 * n * k;
    for (int i = 0; i < m; ++i) scanf("%d", a + i);
    sort(a, a + m);

    int l = 0, r = a[m - 1] - a[0];
    int need = 2 * k - 2;
    while (l < r) {
        int d = (l + r) >> 1;

        int cnt = 0;
        int got = 0;
        for (int i = m - 2; i >= 0; --i) {
            if (a[i + 1] - a[i] <= d && cnt >= need) {
                ++got;
                if (got == n) break;
                cnt -= need;
                --i;
            } else {
                ++cnt;
            }
        }

        if (got >= n) r = d;
        else l = d + 1;
    }

    cout << l << endl;

    return 0;
}
