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

const int N = 11111;
int n;
int a[N], pos[N];
pair<int, int> b[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = make_pair(a[i], i);
    }
    sort(b, b + n);
    for (int i = 0; i < n; ++i) a[b[i].second] = i;

    priority_queue< pair<int, int> > q;
    for (int i = 0; i < n; ++i) {
        if (a[i] != i)
            q.push( make_pair(-abs(a[i] - i), i) );
    }

    while (!q.empty()) {
        pair<int, int> t = q.top(); q.pop();
        int l = t.second;
        int r = a[t.second];
        if (l > r) swap(l, r);
        if (-abs(l - r) != t.first) continue;

        ans.push_back(make_pair(l + 1, r + 1));
        for (int i = l; i < (r + l + 1) / 2; ++i) {
            swap(a[i], a[r - i + l]);
            if (a[i] != )
            q.push( make_pair(-abs(a[i]) );
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
//    for (int i =0; i < n; ++i) cerr << a[i] << " ";
//    cerr << endl;
    
    return 0;
}
