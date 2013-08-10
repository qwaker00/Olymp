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

#define BN 505*5005

int CODE[256];
int b[BN][64];
int wend[BN];
int linky[BN];
int hit[BN], v[BN], vn;

int bn, n, m, ans[555];
char buf[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
//    cerr << clock() << endl;
//    cerr << sizeof(b) << endl;

    for (int i = 'a'; i <= 'z'; ++i) CODE[i] = i - 'a';
    for (int i = 'A'; i <= 'Z'; ++i) CODE[i] = i - 'A' + CODE['z'] + 1;
    for (int i = '0'; i <= '9'; ++i) CODE[i] = i - '0' + CODE['Z'] + 1;
    CODE['-'] = CODE['9'] + 1;
    CODE['$'] = CODE['-'] + 1;

    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {        
        gets(buf);
        
        int cur = 0;
        for (int j = 0; buf[j]; ++j) {
            int c = CODE[(int)buf[j]];
            if (!b[cur][c]) b[cur][c] = ++bn;
            cur = b[cur][c];
        }
        wend[cur] = i + 1;
    }

    queue<int> q;
    for (int i = 0; i < 64; ++i) if (b[0][i]) q.push(b[0][i]);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        v[vn++] = x;
        for (int i = 0; i < 64; ++i)
            if (b[x][i]) {
                linky[b[x][i]] = b[linky[x]][i];
                q.push(b[x][i]);
            } else b[x][i] = b[linky[x]][i];
    }
    /*
    for (int i = 0; i <= bn; ++i) {
        cout << i << ": " << linky[i];
        for (int j = 0; j < 64; ++j) if (b[i][j]) cout << endl << "\t" << char(j + 'a') << "->" << b[i][j];
        cout << endl;        
    }
    */
    scanf("%d\n", &m);
    for (int i = 0; i < m; ++i) {
        gets(buf);
        int cur = 0;
        for (int j = 0; buf[j]; ++j) {
            cur = b[cur][CODE[(int)buf[j]]];
            ++hit[cur];
        }
    }
    for (int i = vn - 1; i >= 0; --i) {
        int x = v[i];
        hit[linky[x]] += hit[x];
        if (wend[x])
            ans[wend[x] - 1] = hit[x];
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }

//    cerr << clock() << endl;
     
    return 0;
}
