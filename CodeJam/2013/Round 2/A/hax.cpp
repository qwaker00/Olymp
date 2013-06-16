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


struct Tp {
    int x, y;
    LL c;

    bool operator<(const Tp& t) const {
        return x < t.x || x == t.x && y < t.y;
    }
} a[1111];
int c[1111];

LL Profit(LL n, LL N) {
    if (n == 0) return 0;
    return N * n - n * (n - 1) / 2;
}

void Unique(vector<Tp>& all) {
    sort(all.begin(), all.end());
    vector<Tp> r;

    Tp cur = all[0];
    for (int i = 1; i < all.size(); ++i) {
        if (all[i].x == cur.x && cur.y == all[i].y) {
            cur.c += all[i].c;
        } else {
            if (cur.c > 0) 
                r.push_back(cur);
            cur = all[i];
        }
    }
    r.push_back(cur);

    all = r;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T; 
    cin >>T;
    for (int __it = 1; __it <= T; ++__it){
        int n, m;
        LL ans = 0;

        cin >> n >> m;

        for (int i= 0; i < m; ++i) {
            cin >> a[i].x >> a[i].y >> a[i].c;
            ans += Profit(a[i].y - a[i].x, n) * a[i].c;
        }
        sort(a, a + m);
        memset(c, 0, sizeof(c));

        vector<Tp> all;
        for (int i = 0; i < m; ++i) {
            LL rest = a[i].c;

            vector<pair<int, pair<int, int> > > cand;
            for (size_t j = 0; j < all.size(); ++j) {
                if (all[j].x < a[i].x && all[j].y >= a[i].x && all[j].y <= a[i].y) {
                    cand.push_back(make_pair(-all[j].y + all[j].x, make_pair(all[j].x, j)));
                }
            }

            sort(cand.begin(), cand.end());
            for (int j = 0; rest && j < cand.size(); ++j) {
                int ind = cand[j].second.second;
                LL t = min(all[ind].c, rest);
                if (t) {
                    rest -= t;
                    all[ind].c -= t;

                    Tp t1, t2;
                    t1.x = a[i].x;
                    t1.y = all[ind].y;
                    t1.c = t;

                    t2.x = all[ind].x;
                    t2.y = a[i].y;
                    t2.c = t;

                    all.push_back(t1);
                    all.push_back(t2);
                }
            }
            if (rest) {
                a[i].c = rest;
                all.push_back(a[i]);
            }
        }

        bool changed = true;
        for (int it = 0; it < 3; ++it) {
        Unique(all);
        changed = false;
        int ss = all.size();
        for (int i = 0; i < ss; ++i) {
            LL rest = all[i].c;


            vector<pair<int, pair<int, int> > > cand;
            for (size_t j = 0; j < all.size(); ++j) if (all[i].c) {
                if (all[j].x < all[i].x && all[j].y >= all[i].x && all[j].y < all[i].y) {
                    cand.push_back(make_pair(-all[j].y + all[j].x, make_pair(all[j].x, j)));
                }
            }

            sort(cand.begin(), cand.end());
            for (int j = 0; rest && j < cand.size(); ++j) {
                int ind = cand[j].second.second;
                int t = min(all[ind].c, rest);
                if (t) {
                    changed = true;
                    rest -= t;
                    all[ind].c -= t;

                    Tp t1, t2;
                    t1.x = all[i].x;
                    t1.y = all[ind].y;
                    t1.c = t;

                    t2.x = all[ind].x;
                    t2.y = all[i].y;
                    t2.c = t;

                    all.push_back(t1);
                    all.push_back(t2);
                }
            }
            all[i].c = rest;
        }
        }

        for (int i = 0; i < all.size(); ++i) ans -= Profit(all[i].y - all[i].x, n) * all[i].c;

        cout << "Case #" << __it << ": " << ans << endl;
    }
    cerr << clock() << endl;
    
    return 0;
}
