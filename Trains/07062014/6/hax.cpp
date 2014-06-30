#include <cstdio>

typedef long long LL;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, l, s;
    scanf("%d%d%d", &n, &l, &s);
    LL sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += LL(s) * s;
    }
    if (LL(l) * l > sum)
        puts("NO");
    else
        puts("YES");
    return 0;
}
