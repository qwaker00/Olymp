#include <iostream>
#include <cstdio>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <cmath>

using namespace std;

bool a[222][222];
double b[222][222];
int n;

const double eps = 1e-10;

double gauss() {
    for (int i = 0; i < n; ++i) {
        int ii = i;
        for (int j = i + 1; j < n; ++j)
            if (fabs(b[j][i]) > fabs(b[ii][i]))
                ii = j;
        if (fabs(b[ii][i]) < eps) return 0.;
        if (ii != i) {
            for (int j = i; j < n; ++j) swap(b[i][j], b[ii][j]);
        }
        for (int j = i + 1; j < n; ++j) {
            double coef = b[j][i] / b[i][i];
            for (int k = i; k < n; ++k)
                b[j][k] -= b[i][k] * coef;
        }
    }
    return 1;
}

int main() {
    freopen("perfect.in", "r", stdin);
    freopen("perfect.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            a[i][x - 1] = 1;
        }
    }

    srand(0);
    for (int __it = 0; __it < 5; ++__it) {
        for (int i = 0; i < n; ++i) {
            b[i][i] = 0;
            for (int j = i + 1; j < n; ++j) {
                if (a[i][j] && a[j][i]) {
                    b[i][j] = rand();
                    b[j][i] = -b[i][j];
                } else
                    b[i][j] = b[j][i] = 0;
            }
        }

        if ( fabs(gauss()) > eps ) {
           puts("YES");
           return 0;
        }
    }
    puts("NO");

    return 0;
}
