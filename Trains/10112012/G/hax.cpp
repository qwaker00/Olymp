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

#define N 333

char rot[N][N];
int a[N][N], cyc[N * N];
int n, m, L;
char s[N], was[N * N];
LL A[N * N], cnt[N * N];
vector<pair<int, int> > REQ[N * N];

LL DivMod(const char* s, LL di, LL M) {
    LL ans = 0, rem = 0;
    for (int i = 0; i < L; i++) {
        rem = rem * 10 + s[i] - '0';
        ans = (ans * 10 + rem / di) % M;
        rem %= di;
    }
    return ans;
}

LL Mod(const char* s, LL mo) {
    LL ans = 0;
    for (int i =0 ; i < L; i++) ans = (ans * 10 + s[i] - '0') % mo;
    return ans;
}

int main() {
    freopen("garbling.in", "r", stdin);
    freopen("garbling.out", "w", stdout);
    
    scanf("%d%d%s\n", &n, &m, s);
    for (int i = 0; i < n; i++) {   
        gets(rot[i]);
    }
    L = strlen(s);
    
    for (int i = 0; i < n; i++) for(int j = 0; j < m; j++) a[i][j] = i * m + j;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; ++j) {
            ++cnt[ a[i][j] ];
            //cerr << a[i][j] +  1 << endl;
            if (rot[i][j] == 'L') {
                swap(a[i][j], a[i + 1][j]);
                swap(a[i][j + 1], a[i][j]);
                swap(a[i + 1][j + 1], a[i][j + 1]);
            } else
            if (rot[i][j] == 'R') {
                swap(a[i][j], a[i][j + 1]);
                swap(a[i + 1][j], a[i][j]);
                swap(a[i + 1][j + 1], a[i + 1][j]);
            }
        }
    }


     
    LL rc = LL(n - 1) * (m - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) if (!was[i * m + j]) {

            LL tot = 0;
            int len = 0, cur = i * m + j;
            do {
                cyc[len++] = cur;
                tot += cnt[cur];
                was[cur] = true;
                cur = a[cur / m][cur % m];
            } while (cur != cyc[0]);

            LL iters = DivMod(s, rc * len, 100000);
            LL rem = Mod(s, rc * len);

            tot %= 100000;

            do {
                A[cur] = (iters * tot) % 100000;
                cur = a[cur / m][cur % m];
            } while (cur != cyc[0]);

            LL pls = 0;
            LL rem2 = rem;
            int kk = 0;
            while (rem2 >= rc) {
                pls += cnt[ cyc[kk] ];
                rem2 -= rc;
                if (--kk < 0) kk = len - 1;
            }

            int it = 0;
            cur = i * m + j;
            do {
                A[cur] = (A[cur] + pls) % 100000;
                REQ[rem2].push_back(make_pair(cur, cyc[kk]));

                ++it;
                pls += cnt[ cyc[it] ]; 
                if (++kk >= len) kk = 0;
                pls -= cnt[ cyc[kk] ];

                cur = a[cur / m][cur % m];
            } while (cur != cyc[0]);
        }
    }
    
    memset(cnt, 0, sizeof(cnt));
    int it = 0;
    for (int i = 0; i < n; i++) for(int j = 0; j < m; j++) a[i][j] = i * m + j;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; ++j) {
            ++cnt[ a[i][j] ];
            ++it;
            for (int k = 0; k < REQ[it].size(); ++k) {
                A[REQ[it][k].first] += cnt[REQ[it][k].second];
            }

            //cerr << a[i][j] +  1 << endl;
            if (rot[i][j] == 'L') {
                swap(a[i][j], a[i + 1][j]);
                swap(a[i][j + 1], a[i][j]);
                swap(a[i + 1][j + 1], a[i][j + 1]);
            } else
            if (rot[i][j] == 'R') {
                swap(a[i][j], a[i][j + 1]);
                swap(a[i + 1][j], a[i][j]);
                swap(a[i + 1][j + 1], a[i + 1][j]);
            }
        }
    }
    for (int i = 0; i < n * m; ++i) printf("%d\n", int(A[i] % 100000));

    return 0;
}
