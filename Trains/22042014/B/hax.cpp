#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

char A[55], B[55], C[55];
int f[55][2];
const int MOD = 1000000007;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    gets(A);
    gets(B);
    gets(C);
    int n = strlen(A);

    f[n][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        int la = ((A[i] == '?') ? (i == 0) : A[i] - 48), ra = ((A[i] == '?') ? 9 : A[i] - 48);
        int lb = ((B[i] == '?') ? (i == 0) : B[i] - 48), rb = ((B[i] == '?') ? 9 : B[i] - 48);
        for (int j = 0; j < 2; ++j) if (f[i + 1][j]) {
           for (int da = la; da <= ra; ++da) {
               for (int db = lb; db <= rb; ++db) {
                    int dd = da + db + j, dc = dd % 10, dcarry = dd / 10;
                    if (C[i] == '?' || C[i] == dc + 48) {
                        f[i][dcarry] = (f[i][dcarry] + f[i + 1][j]) % MOD;
                    }
               }
           }
        }
    }
    printf("%d\n", f[0][0]);

    return 0;
}

