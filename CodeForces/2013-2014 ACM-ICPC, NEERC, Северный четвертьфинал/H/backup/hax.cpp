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

int n, k, cnt1 = 0, cnt2 = 0;
char s[555];
map<string, int> mp1;
map<string, int> mp2;
vector<int> g[N];
vector<int> lst[N];

bool used[N];

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

vector<int> A, B;
vector<int> ans;

void dfs(int x) {
    if (!lst[x].size() || used[x]) return;
    used[x] = true;

    if (x < n) A.push_back(x);
    else B.push_back(x);

    for (int i = 0; i < g[x].size(); ++i)
        dfs(g[x][i]);         
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

    for (int i = 0; i < n; ++i)
        if (lst[i].size() && !used[i]) {
            A.clear();
            B.clear();

            dfs(i);

            if (A.size() < B.size()) ans.insert(ans.end(), A.begin(), A.end());
            else ans.insert(ans.end(), B.begin(), B.end());
        }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        int x = ans[i];

        printf("%d", lst[x].size());
        for (int j = 0; j < lst[x].size(); ++j)
            printf(" %d", lst[x][j]);
        puts("");
    }
    
    return 0;
}
