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

#define BN 2222222

char s[4444];
int b[BN][26], bn;
bool eb[BN], p[BN], d[BN];
int f[4444][6];

void rec(int x, int p, char* s, int l, int err, int erc) {
    if (eb[x]) {
        if (erc == 0) {
            erc++;
            erc--;
        }
        f[p][err] = min(f[p][err], erc);        
    }
    if (l > 0)
    for (int i = 0; i < 26; ++i) {
        if (!b[x][i]) continue;
        if (*s == i + 'a')
            rec(b[x][i], p + 1, s + 1, l - 1, min(err + 1, 4), erc);else
            if (err == 4) {
                rec(b[x][i], p + 1, s + 1, l - 1, 0, erc + 1);
            }
    }
}

int main() {
    freopen("dict.txt", "r", stdin);

    int maxl = 0;
    while (gets(s)) {
        int l = strlen(s);
        if (l > maxl) maxl = l;
        int cur = 0;
        for (int i = 0; i < l; ++i) {
            if (b[cur][s[i] - 'a'] == 0) b[cur][s[i] - 'a'] = ++bn;
            cur = b[cur][s[i] - 'a'];
        }
        eb[cur] = 1;
    }                /*
    queue<int> q;
    for (int i = 0; i < 26; ++i) if (b[0][i]) {
        q.push(b[0][i]);
        p[b[0][i]] = 0;
        d[b[0][i]] = 1;
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < 26; ++i)
            if (b[x][i]) {
                q.push(b[x][i]);
                p[b[x][i]] = b[p[x]][i];
                d[b[x][i]] = d[x] + 1;
            } else b[x][i] = b[p[x]][i];
    }
    */
    cerr << bn << " " << maxl << " " << clock() << endl;

    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);    

    int T;
    cin >> T;
    gets(s);
    for (int __it = 1; __it <= T; ++__it) {
        gets(s);
        int l = strlen(s);        

        memset(f, 63, sizeof(f));
        f[0][4] = 0;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j <= 4; ++j) {
                if (f[i][j] < 1e9)
                    rec(0, i, s + i, l - i, j, f[i][j]);    
            }
        }

        int ans = *min_element(f[l], f[l] + 5);
        cout << "Case #" << __it << ": " << ans << endl;
    }
    
    return 0;
}
