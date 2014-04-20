#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef unsigned long long ULL;
typedef long double LD;
using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        int n, k, c, ans = 2e9;
        cin >> n >> k >> c;

        for (int e = 0; e <= 0; ++e) {
            int preans = 0;
            if (k - (k % (n - e)) >= c) {
                preans = c;
                if (preans + e < ans) ans = preans + e;
            } else {
                preans = c + (n - e) - k % (n - e);
                if (preans + e < ans) ans = preans + e;

                preans = c + n - k / ((k + (n - e - 1)) / (n - e));
                if (preans < ans) ans = preans;
            }
        }

        printf("Case #%d: %d\n", __it, ans);
    }   
    
    return 0;
}
