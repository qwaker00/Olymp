#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


LL f[2222][2222];
short p[2222][2222];

unsigned char alf[255], alfp[255], a[4444], b[4444], ansa[4444], ansb[4444];
int lalf, la, lb, d[255][255], mina[255], minb[255], an, bn;

int main() {
    freopen("dissim.in", "r", stdin);
    freopen("dissim.out", "w", stdout);

    gets((char*)alf);
    lalf = strlen((char*)alf);
    for (int i = 0; i < lalf; ++i) alfp[alf[i]] = i;

    gets((char*)a);
    la = strlen((char*)a);

    gets((char*)b);
    lb = strlen((char*)b);

    for (int i = 0; i < la; ++i) a[i] = alfp[a[i]];
    for (int i = 0; i < lb; ++i) b[i] = alfp[b[i]];

    for (int i = 0; i < lalf; ++i) {
        int& mi = mina[i] = 0;
        int minv = 2e9;
        for (int j = 0; j< lalf; ++j) {
            scanf("%d", &d[i][j]);
            if (d[i][j] < minv) {
                minv = d[i][j];
                mi = j;
            }
        }
    }
    for (int i = 0; i < lalf; ++i) {
        int& mi = minb[i] = 0;
        int minv = 2e9;
        for (int j = 0; j < lalf; ++j) {
            if (d[j][i] < minv) {
                minv = d[j][i];
                mi = j;
            }
        }
    }

    memset(f, 127, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i <= la; ++i)
        for (int j = 0; j <= lb; ++j)
            if (f[i][j] < 1e18) {
                if (i < la && f[i + 1][j] > f[i][j] + d[ a[i] ][ mina[a[i]] ]) {
                    f[i + 1][j] = f[i][j] + d[ a[i] ][ mina[a[i]] ];
                    p[i + 1][j] = 1;
                }
                if (j < lb && f[i][j + 1] > f[i][j] + d[ minb[b[j]] ][ b[j] ]) {
                    f[i][j + 1] = f[i][j] + d[ minb[b[j]] ][ b[j] ];
                    p[i][j + 1] = 2;
                }
                if (i < la && j < lb && f[i + 1][j + 1] > f[i][j] + d[ a[i] ][ b[j] ]) {
                    f[i + 1][j + 1] = f[i][j] + d[ a[i] ][ b[j] ];
                    p[i + 1][j + 1] = 3;
                }
            }

    cout << f[la][lb] << endl;

    int i = la, j = lb;
    while (i > 0 || j > 0) {
        if (p[i][j] == 3) {
            --i;
            --j;
            ansa[an++] = a[i];
            ansb[bn++] = b[j];
        } else
        if (p[i][j] == 2) {
            --j;
            ansa[an++] = minb[b[j]];
            ansb[bn++] = b[j];
        } else {
            --i;
            ansa[an++] = a[i];
            ansb[bn++] = mina[a[i]];
        }
    }

    for (int i = an - 1; i >= 0; --i) putchar(alf[ansa[i]]);
    putchar('\n');
    for (int i = bn - 1; i >= 0; --i) putchar(alf[ansb[i]]);
    putchar('\n');

    
    return 0;
}
