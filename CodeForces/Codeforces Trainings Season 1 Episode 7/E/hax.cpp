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

#define N 211

int T;
int cost[N];
int pr[N];

int fs(int x) {
    if (pr[x] != x) pr[x] = fs(pr[x]);
    return pr[x];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);    
    while (T--) {
        int n;
        scanf("%d", &n);
        vector< pair<int, pair<int, int> > > l;
        for (int i = 0; i < n; ++i) {
            int id, k;
            scanf("%d", &id);
            scanf("%d", &cost[id]);
            scanf("%d", &k);
            pr[id] = id;
            for (int j = 0; j < k; ++j) {
                int x;
                scanf("%d", &x);
                if (x < id)
                    l.push_back(make_pair(0, make_pair(id, x)));
            }
        }
        for (int i = 0; i < l.size(); ++i) {
            l[i].first = -(cost[l[i].second.first] + cost[l[i].second.second]);
        }
        sort(l.begin(), l.end());
        LL ans = 0;
        for (int i = 0; i < l.size(); ++i) {
            int x = fs(l[i].second.first);
            int y = fs(l[i].second.second);
            if (x != y) {
                pr[x] = y;
            } else
                ans -= l[i].first;
        }
        cout << ans << endl;
    }
    
    return 0;
}
