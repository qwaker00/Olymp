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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 11111

int  n, k, cnt1 = 0, cnt2 = 0;
char s[555];
map<string, int> mp1;
map<string, int> mp2;
vector<int> g[N];
vector<int> lst[N];
vector<int> ans;

int pr[N], nx[N];
int was[N];
int IT = 0;

int getid1(const char * s) {
    int& t = mp1[s];
    if (!t) t = ++cnt1;
    return t;
}
int getid2(const char * s) {
    int& t = mp2[s];
    if (!t) t = ++cnt2;
    return t;
}

bool kuhn(int x) {
    if (was[x] == IT) return false;
    was[x] = IT;
    for (int i = 0; i < g[x].size(); ++i)
        if (pr[g[x][i]] == -1 || kuhn(pr[g[x][i]])) {
            pr[g[x][i]] = x;
            nx[x] = g[x][i];
            return true;
        }
    return false;
}

int main() {
    freopen("heavy.in", "r", stdin);
    freopen("heavy.out", "w", stdout);

    scanf("%d%d\n", &n, &k);
    for (int i = 0; i < n; ++i) {
        gets(s);

        char ch = 0;
        swap(ch, s[k]);
        int l = getid1(s) - 1;
        swap(ch, s[k]);
        int r = getid2(s + strlen(s) - k) + n - 1;

        lst[l].push_back(i + 1);
        lst[r].push_back(i + 1);

        g[l].push_back(r);
        g[r].push_back(l);
    }

    int q = 0;
    memset(pr, -1, sizeof(pr));
    memset(nx, -1, sizeof(nx));
    for (int i = 0; i < n; ++i) {
        ++IT;
        q += kuhn(i);
    }

    ++IT;
    for (int i = 0; i < n; ++i)
        if (nx[i] == -1 && lst[i].size() != 0)
            for (int j = 0; j < g[i].size(); ++j)
                if (was[ g[i][j] ] != IT) {
                    was[ g[i][j] ] = IT;
                    ans.push_back(g[i][j]);
                }
    for (int i = 0; i < n; ++i)
        if (pr[i + n] == -1 && lst[i + n].size() != 0)
            for (int j = 0; j < g[i + n].size(); ++j)
                if (was[ g[i + n][j] ] != IT) {
                    was[ g[i + n][j] ] = IT;
                    ans.push_back(g[i + n][j]);
                }
    for (int i = 0; i < n; ++i)
        if (nx[i] != -1 && was[i] != IT && was[nx[i]] != IT) {
            was[i] = IT;
            //was[nx[i]] = IT;
            ans.push_back(i);
        }

    if (q != ans.size())
        throw 1;

    ++IT;
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        int x = ans[i];

        int sz = 0;
        for (int j = 0; j < lst[x].size(); ++j)
            if (was[lst[x][j]] != IT)
                ++sz;

        printf("%d", sz);
        for (int j = 0; j < lst[x].size(); ++j)
            if (was[lst[x][j]] != IT) {
                printf(" %d", lst[x][j]);
                was[lst[x][j]] = IT;
            }
        puts("");
    }
    for (int i = 1; i <= n; ++i) if (was[i] != IT) throw 1;
    
    return 0;
}
