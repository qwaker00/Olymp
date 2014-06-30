#include <iostream>
#include <cstdio>
#include <assert.h>

int main() {
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);

    int n, a, b;
    long long ans = -1;
    int outx, outy;
    std::cin >> n >> a >> b;

    for (int x = 1; x <= n; ++x) {
        for (int y = x; y; y = (y - 1) & x) {
            long long t = ((long long)a * x + (long long)b * y) ^ ((long long)a * y + (long long)b * x);
            if (t > ans) {
                ans = t;
                outx = x;
                outy = y;
            }
        }
    }
    std::cout << outx << " " << outy << "\n";

    return 0;
}
