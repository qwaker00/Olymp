#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000111;
int a[N];
int n;

int calc(int start, ll b) {
    int ans = 1;
    ll sum = 0;
    for (int i = 1, p = start; i <= n; ++i, ++p) {
        if (p > n) p = 1;
        if (a[p] + sum <= b) {
            sum += a[p];
        } else {
            sum = a[p];
            ++ans;
        }
    }
    return ans;
}

int main() {
    //freopen(".in", "r", stdin);
    int qc;
    scanf("%d%d\n", &n, &qc);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    while (qc--) {
        ll b;
        scanf("%I64d", &b);

        int start = 0;
        ll sum = 0;
        int ans = 1e9;
        for (int i = 1, p = 1; i <= 3*n; ++i, ++p) {
            if (p > n) {
                ans = min(calc(start, b), ans);
                p = 1;
            }
            if (a[p] + sum <= b) {
                sum += a[p];
            } else {
                start = p;
                sum = a[p];
            }
        }
        for (int i = 0; i < 5; ++i) {
            start = rand() % n + 1;
            ans = min(calc(start, b), ans);
        }
       printf("%d\n", ans);
    }

    return 0;
}