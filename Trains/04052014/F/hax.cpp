#include <cstdio>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <set>

using namespace std;
typedef long long LL;


struct Tp {
    int d, p, r, g;

    bool operator<(const Tp& t) const {
        return d < t.d;
    }
} a[111111];


int n, c, d;
LL f[111111];

inline LL calcV(int cid, LL t) {
    return f[cid] - a[cid].p + a[cid].r + LL(t - a[cid].d - 1) * a[cid].g;
}

int TIMER = 0;

struct Cmp {
    bool operator()(int x, int y) {
        LL t1 = calcV(x, TIMER);
        LL t2 = calcV(y, TIMER);
        return t1 > t2 || t1 == t2 && x < y;
    }
};

int prp[111111];

inline void maybeaddevent(int i, priority_queue< pair<LL, int> >& q, set<int, Cmp>& lines) {
    set<int, Cmp>::iterator ii = lines.find(i);
    if (ii != lines.begin()) {
        set<int, Cmp>::iterator jj = ii--;
        int j = *jj;

        if (a[j].g > a[i].g) {
            LL num = f[i] - a[i].p + a[i].r + (-a[i].d - 1) * a[i].g - f[j] + a[j].p - a[j].r - (-a[j].d - 1) * a[j].g;
            LL denum = a[j].g - a[i].g;
            LL tt = (num + denum + 1) / denum;
            q.push(make_pair(-tt, -j - 1));
        }
    }
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int __it = 0;
    while (1) {
        scanf("%d%d%d", &n, &c, &d);

        priority_queue< pair<LL, int> > q;
        q.push(make_pair(d + 1, 0));
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &a[i].d, &a[i].p, &a[i].r, &a[i].g);
            q.push(make_pair(-a[i].d, i + 1));
        }
        sort(a, a + n);

        LL ans = 0;
        set< int, Cmp > lines;
        while (!q.empty()) {
            pair<LL, int> t = q.top(); q.pop();
            TIMER = -t.first;

            if (t.second > 0) // Add car
            {
                int i = t.second - 1;

                f[i] = c;
                if (lines.size()) {
                    LL v = calcV(*lines.begin(), TIMER);
                    f[i] = max(f[i], v);
                }

                lines.insert(i);
                maybeaddevent(i, q, lines);
            } else
            if (t.second == 0) {
                ans = calcV(*lines.begin(), TIMER);
                break;
            } else {
                TIMER--;
                int i = -t.second - 1;
                set<int, Cmp>::iterator ii = lines.find(i);
                if (ii != lines.begin()) {
                    set<int, Cmp>::iterator jj = ii--;
                    int j = *jj;
                    if (calcV(j, TIMER + 1) >= calcV(i, TIMER + 1))
                        lines.erase(j);
                }
                ++TIMER;
                maybeaddevent(i, q, lines);
            }
        }

        ++__it;
        printf("Case %d: ", __it);
        cout << ans << "\n";
    }


    return 0;
}

