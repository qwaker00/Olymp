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

LL calc(const vector< pair<int, int> >& a, int k, int s) {
    LL ans = 0;
    LL ss = s;
    for (int i = 0, j = 0; i < k; ++i) {
        while (j < a.size() && a[j].first >= ss) ss -= a[j++].first;
        ans += ss;
        ss -= a[i].first;
    }
    return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    srand(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, s;
        cin >> n >> k >> s;

        vector< pair<int, int> > a(n);
        vector<int> out(n);
        vector< pair<int, int> > ansa;

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        LL ans = 1e18;
        LL t = calc(a, k, s);
        if (t < ans) {
            ans = t;
            ansa = a;
        }

        sort(a.begin(), a.end());
        t = calc(a, k, s);
        if (t < ans) {
            ans = t;
            ansa = a;
        }

        reverse(a.begin(), a.end());
        t = calc(a, k, s);
        if (t < ans) {
            ans = t;
            ansa = a;
        }

        for (int __it = 0; __it < 2000; ++__it) {
            random_shuffle(a.begin(), a.end());
            t = calc(a, k, s);
            if (t < ans) {
                ans = t;
                ansa = a;
            }
        }

        for (int i = 0; i < a.size(); ++i) out[ansa[i].second] = i + 1;
        for (int i = 0; i < n; ++i) cout << out[i] << " ";
        cout << "\n";
    }

    return 0;
}
