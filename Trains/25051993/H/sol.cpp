#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
    freopen("cash.in", "r", stdin);
    freopen("cash.out", "w", stdout);

    int s, n;
    cin >> s >> n;

    if (n * 50 >= s) {
        n = s / 50;
        printf("%d\n", n);
        for (int i = 0; i < n; ++i) {
            puts("50");
        }
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = 50;

    s -= n * 50;
    for (int i = 0; i < n; ++i) {
        while (a[i] + 100 <= 450 && s >= 100) {
            a[i] += 100;
            s -= 100;
        }
    }
    a[n - 1] += s;

    printf("%d\n", n);
    for (int i = 0; i < n; ++i) printf("%d\n", a[i]);

    return 0;
}
