#include <iostream>
#include <algorithm>
#include <fstream>
#include <complex>
#include <vector>
#include <math.h>
using namespace std;

typedef complex<double> cld;
typedef long long ll;

const int M = 16;
const int N = 1 << M;
const int MOD = 786433;
const double PI = acos(-1.);

cld roots[N], a[N], b[N], f[M + 3][N], invf[M + 3][N];
int revbit[N];

void fft(cld* arr, cld* out) {
    for (int i = 0; i < N; ++i) {
        out[ revbit[i] ] = arr[i];
    }

    for (int window = 2; window <= N; window += window) {
        for (int L = 0; L < N; L += window) {
            int k = N / window;
            int pos = k;

            int shift = window / 2;
            for (int l = L, r = L + shift; l < r; ++l) {
                cld a = out[l], b = out[l + shift];
                out[l] = a + roots[pos] * b;
                out[l + shift] = a - roots[pos] * b;
                pos += k;
            }
        }
    }
}

int main() {
    freopen("avl.in", "r", stdin);
    freopen("avl.out", "w", stdout);

    roots[0] = 1;
    double rootAngle = 2. * PI / N;
    roots[1] = cld(cos(rootAngle), sin(rootAngle));
    for (int i = 2; i < N; ++i) {
        roots[i] = cld(cos(rootAngle * i), sin(rootAngle * i));
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            if (i & (1 << j)) {
                revbit[i] += (1 << (M - j - 1));
            }
    }

    f[0][0] = 1;
    f[0][1] = 1;
    f[1][2] = 2;
    f[1][3] = 1;
    fft(f[0], invf[0]);
    fft(f[1], invf[1]);
    for (int h = 2; h < M; ++h) {
        for (int i = 0; i < N; ++i) {
            invf[h][i] = invf[h - 1][i] * invf[h - 1][i];
            if (h > 1) {
                invf[h][i] += 2. * invf[h - 1][i] * invf[h - 2][i];
            }
        }
        fft(invf[h], f[h]);
        reverse(f[h], f[h] + N);
        for (int i = N - 1; i; --i) {
            ll value = ll(f[h][i - 1].real() / N + 0.5);
            f[h][i] = double(value % MOD);
        }
        f[h][0] = 0;
        fft(f[h], invf[h]);

    }

    for (int n = 1; n <= 10; ++n)
        for (int h = 1; h <= n; ++h)
            cerr << n << " " << h << ": " << ll(f[h][n].real() + 0.5) << endl;

    int n, h;
    cin >> n >> h;

    cout << ll(f[h][n].real() + 0.5) << endl;

    return 0;
}

