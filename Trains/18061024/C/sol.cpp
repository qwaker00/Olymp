#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 40;
int a[N][N+N+N];
typedef long long ll;
ll C[N];

int f(ll n, ll i) {
    if (i > n * 2) return 0;
    if (n <= 27) return a[n][i];

    ll c;
    for (int I = 0; I < N; ++I)
        if (C[I] >= n) {
            c = C[I];
            break;
        }

    if (c == n) return 1;
    ll w = (c + c + 1) / 3;
    ll sw = w / 2;
    if (c - n <= sw) {
        return f(n - (c - sw), i % w);
    }

    if (i >= w) return (2 * f(n, i - w)) % 3;

    ll h1 = sw / 3;
    ll h2 = h1 + 1;
    ll c2 = c / 3;

    int x = -1;
    int y = i / (w / 3);
    if (n - c2 <= h1) x = 0;
    else if (n - c2 <= h1 + h2) x = 1;
    else x = 2;

    if (x == 0 && y == 0) return f(n + h1 + h2, i);
    if (x == 0 && y == 1) return 0;
    if (x == 0 && y == 2) return 0;
    if (x == 1 && y == 0) return f(n - h2 - c2, i);
    if (x == 1 && y == 1) return (2 * f(n, i - w / 3)) % 3;
    if (x == 1 && y == 2) return 0;
    return f(n - h2 - c2, i % (w / 3));
}

int main() {
    freopen("coef.in", "r", stdin);
    freopen("coef.out", "w", stdout);

    a[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        int w = i + i + 1;
        for (int j = 0; j < w; ++j) {
            a[i][j] = a[i - 1][j];
            if (j - 1 >= 0) a[i][j] += a[i - 1][j - 1];
            if (j - 2 >= 0) a[i][j] += a[i - 1][j - 2];
            a[i][j] %= 3;
        }
    }

    C[0] = 1;
    for (int i = 1; i < N; ++i) {
        C[i] = C[i - 1] * 3 + 1;
    }

    int t;
    scanf("%d", &t);

    while (t--) {
        ll n, i;
        scanf("%lld%lld", &n, &i);
        printf("%d\n", f(n, i));
    }

    /*
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < i + i + 1; j++)
            if (f(i, j) != a[i][j]) {
                cerr << "!" << i << " " << j << " : " << a[i][j] << " - " << f(i, j) << endl;
            }
            */

    return 0;
}

