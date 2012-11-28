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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;
typedef long long ll;

const int N = 50055;

string w[N], a[N];
char b[111];
ll s[11], x[11];
ll c[11][11];

ll f[333], g[333];
int cnt[333];

int main() {
    freopen("high.in", "r", stdin);
    freopen("high.out", "w", stdout);
    
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; ++i) {
        scanf("%s", b);
        w[i] = b;    
    }

    for (int msk = 0; msk < 32; ++msk) 
        for (int i = 0; i < 5; ++i)
            if (msk & (1 << i)) ++cnt[msk];

    int lim = 32;
    for (int i = 0; i < lim; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j] = "";
            for (int q = 0; q < 5; ++q)
                if (!(i & (1 << q))) a[j] += w[j][q]; 
        } 

        sort(a, a + n);

        ll len = 1;
        ll ans = 0;
        for (int j = 1; j < n; ++j) {
            if (a[j] == a[j - 1]) {
                ans += len;
                ++len;
            } else {
                len = 1;
            }
        } 
        
        f[i] = ans;
        g[i] = ans;
        for (int msk = 0; msk < i; ++msk)
            if (((msk & i)) == msk) { 
                if ((cnt[i] - cnt[msk]) & 1) { 
                    g[i] -= f[msk];
                } else { 
                    g[i] += f[msk];
                }
            }

        //cerr << i << " " << ans << endl;
        //s[cnt] += ans;

        x[cnt[i]] += g[i];
    }

    /*
    c[0][0] = 1;
    for (int i = 1; i <= 5; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }

    for (int i = 0; i <= 5; ++i) {
        x[i] = s[i];
        for (int k = 0; k < i; ++k) x[i] -= c[i - k][5 - k] * x[k];
        cout << x[i] << " ";
    }
    cout << endl;
    */

    for (int i = 0; i <= 5; ++i)
        cout << x[i] << " ";
    cout << endl;


    return 0;
}
