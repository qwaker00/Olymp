#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;
int n, m, k;
const int N = 1033;
int f[N][N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;
    memset(f, 63, sizeof(f));
    --k;

    for (int i = 0; i < n; ++i) {
        int l = i;
        int r = m - (n - i);
        if (k < l || k > r || (l == r && l == k)) f[i][i] = 0;
        else f[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len)
        for (int left = 0; left + len <= n; ++left) {
            int right = left + len - 1;

            int l = left;
            int r = m - (n - right);
            if (k < l || k > r || (right - left == r - l)) f[left][right] = 0;
            else {
                f[left][right] = min(f[left + 1][right], f[left][right - 1]) + 1;
                for (int center = left + 1; center < right; ++center)
                    f[left][right] = min(f[left][right], max(f[left][center - 1], f[center + 1][right]) + 1);
            }
        }

    cout << f[0][n - 1] << endl;

    return 0;
}
