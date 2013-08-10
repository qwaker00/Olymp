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

const int N = 100111;
int a[N], n, m, k;
vector<int> s[N];
int rig[N];

void Add(int r, int l) {
    while (r < N) {
        s[r].push_back(l);
        r = (r | (r - 1)) + 1;
    } 
}
int Count(int r, int l) {
    int ans = 0;
    while (r > 0) {
        ans += s[r].end() - lower_bound(s[r].begin(), s[r].end(), l);
        r &= r -1;
    }
    return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        Add(r, l);
    }
    for (int i = 1; i <= n; ++i) sort(s[i].begin(), s[i].end());

    set<int> segs;
    scanf("%d", &k);
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        x += ans;
        if (a[x] > 0) {
            --a[x];
            if (a[x] == 0) {
                rig[x] = x;
                set<int>::iterator i = segs.upper_bound(x);
                if (i != segs.end() && *i == x + 1) {
                    ans -= Count(rig[*i], *i);

                    rig[x] = rig[*i];
                    segs.erase(i++);
                }
                if (i != segs.begin()) {
                    --i;
                    if (rig[*i] + 1 == x) {
                        ans -= Count(rig[*i], *i);

                        rig[*i] = rig[x];
                        x = *i;
                        segs.erase(i);
                    }
                }
                ans += Count(rig[x], x);
                segs.insert(x);
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
                      