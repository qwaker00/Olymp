#include <iostream>
#include <cstdio>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

const int N = 422222;

int n, hn, h[N];

typedef pair<int, int> pii;
pii a[N];
set<pii> sx[N], sy[N], sd1[N], sd2[N];
struct cache {
    int x, y, d1, d2;
} b[N];

bool beat(const pii& q, const pii& a, const set<pii>& s) {
    set<pii>::const_iterator i = s.lower_bound(q);
    if (i != s.end() && *i == a) return true;
    if (i != s.begin()) {
        --i;
        if (*i == a) return true;
    }
    return false;
}

int main() {
    freopen("queen2.in", "r", stdin);
    freopen("queen2.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        h[hn++] = a[i].first;
        h[hn++] = a[i].second;
        h[hn++] = a[i].first + a[i].second;
        h[hn++] = a[i].first - a[i].second;
    }
    sort(h, h + hn);
    hn = unique(h, h + hn) - h;

    for (int i = 0; i < n; ++i) {
        b[i].x = lower_bound(h, h + hn, a[i].first) - h;
        b[i].y = lower_bound(h, h + hn, a[i].second) - h;
        b[i].d1 = lower_bound(h, h + hn, a[i].first + a[i].second) - h;
        b[i].d2 = lower_bound(h, h + hn, a[i].first - a[i].second) - h;

        sx[b[i].x].insert(a[i]);
        sy[b[i].y].insert(a[i]);
        sd1[b[i].d1].insert(a[i]);
        sd2[b[i].d2].insert(a[i]);
    }

    pii q(0, 0);
    for (int i = 0; i < n; ++i) {
        if (q.first == a[i].first) {
            if (!beat(q, a[i], sx[b[i].x])) {
                cout << i << endl;
                return 0;
            }
        } else
        if (q.second == a[i].second) {
            if (!beat(q, a[i], sy[b[i].y])) {
                cout << i << endl;
                return 0;
            }
        } else
        if (q.first + q.second == a[i].first + a[i].second) {
            if (!beat(q, a[i], sd1[b[i].d1])) {
                cout << i << endl;
                return 0;
            }
        } else
        if (q.first - q.second == a[i].first - a[i].second) {
            if (!beat(q, a[i], sd2[b[i].d2])) {
                cout << i << endl;
                return 0;
            }
        } else {
            cout << i << endl;
            return 0;
        }
        sx[b[i].x].erase(a[i]);
        sy[b[i].y].erase(a[i]);
        sd1[b[i].d1].erase(a[i]);
        sd2[b[i].d2].erase(a[i]);
        q = a[i];
    }
    cout << n << endl;
    return 0;
}
