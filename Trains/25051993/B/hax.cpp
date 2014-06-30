#include <iostream>
#include <cstdio>
#include <cstdlib>

using std::cin;
using std::cout;

int a[2222], v[2222];
int b[2222][2222], sb[2222];

int main() {
    freopen("arcanoid.in", "r", stdin);
    freopen("arcanoid.out", "w", stdout);

    int n, d, r;
    int m;
    cin >> n >> d >> r >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= r;
    }
    d -= r + r;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        int it = 0;
        if (v[i] > 0) {
            b[i][0] = d - a[i];
        } else
            if (v[i] < 0) {
                b[i][0] = a[i];
            } else {
                sb[i] = -1;
                continue;
            }
        for (int j = 1; j < m; ++j) {
            b[i][j] = b[i][j - 1] + d;
        }
        sb[i] = 0;
    }

    int ansX = 1, ansY = 0, lasthit = 0;
    for (int i = 0; i < m; ++i) {
        ansX = 1, ansY = 0;
        for (int j = 0; j < n; ++j)
            if (sb[j] != -1 && b[j][sb[j]] * ansY < ansX * abs(v[j]) ) {
                ansX = b[j][sb[j]];
                ansY = abs(v[j]);
            }
        for (int j = 0; j < n; ++j)
            if (sb[j] != -1 && b[j][sb[j]] * ansY == ansX * abs(v[j]) ) {
                ++sb[j];
                lasthit = j;
            }
    }

    cout.precision(12);
    cout << std::fixed;
    for (int i = 0; i < n; ++i) {
        if (i == lasthit) {
            if (v[i] > 0 && (sb[i] & 1) || v[i] < 0 && ((sb[i] & 1)==0)) {
                cout << d + r + r << " ";
            } else {
                cout << 0 << " ";
            }
        } else
        if (v[i] == 0) {
            cout << a[i] + r << " ";
        } else {
            if (v[i] > 0) {
                int B = (a[i] * ansY + v[i] * ansX) % (ansY * d);
                int A = (a[i] * ansY + v[i] * ansX) / (ansY * d);
                if (A & 1) {
                    B = ansY * d - B;
                }
                cout << double(B) / ansY + r << " ";
            } else {
                v[i] = -v[i];
                a[i] = d - a[i];
                int B = (a[i] * ansY + v[i] * ansX) % (ansY * d);
                int A = (a[i] * ansY + v[i] * ansX) / (ansY * d);
                if ((A & 1) == 0) {
                    B = ansY * d - B;
                }
                cout << double(B) / ansY + r << " ";
            }
        }
    }
    cout << std::endl;

    return 0;
}
