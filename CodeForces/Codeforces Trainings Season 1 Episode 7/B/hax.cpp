#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 55
#define L 333

LD f[L][N];
int p[L][N];

int  id[333];
char ch[N];
char s[L];
LD   sp[N][N], tp[N][N];

char ans[L];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d\n", &n);
        gets(s);
        for (int i = 0; i < n; ++i) {
            ch[i] = s[i + i];
            id[ (unsigned char)ch[i] ] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                double p;
                scanf("%lf", &p);
                sp[i][j] = p;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                double p;
                scanf("%lf", &p);
                tp[i][j] = p;
            }
        }
        int w;
        scanf("%d\n", &w);
        while (w--) {
            gets(s);
            int l = strlen(s);

//            for (int i = 0; i <= l; ++i) for (int j = 0; j <= n; ++j) f[i][j] = 0;
            memset(f, 0, sizeof(f));

            for (int i = 0; i < n; ++i) f[1][i] = sp[ id[(unsigned char)s[0]] ][i];
            for (int i = 1; i < l; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < n; ++k) {
                        if (f[i][j] * tp[j][k] * sp[id[(unsigned char)s[i]]][k] > f[i + 1][k]) {
                            f[i + 1][k] = f[i][j] * tp[j][k] * sp[id[(unsigned char)s[i]]][k];
                            p[i + 1][k] = j;
                        }
                    }
                }
            }
            int mx = 0;
   
            for (int i = 1; i < n; ++i) if (f[l][i] > f[l][mx]) {
                
                mx = i;
            
            }

            if (fabsl(f[l][mx]) < 1e-300) {
                    assert(true);
            }
                      
//            cerr.precision(20);
//            cerr << fixed << f[l][mx] << endl;

            for (int i = 0; i < l; ++i) {
                ans[l - i - 1] = ch[mx];
                mx = p[l - i][mx];
            }
            ans[l] = 0;
            puts(ans);
        }
    }            
        
    return 0;
}
