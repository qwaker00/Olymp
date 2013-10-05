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

LL m, n, t, l;
struct Prob {
    LL i, a, l, o;
} prob[111];
struct Team {
    LL t, z, v, c;
} team[111];

int ed[111111];


LL upDiv(LL x, LL y) {
    return (x + y - 1) / y;
}

bool canSolve(Team& t, Prob& p) {
    return t.t + t.c > p.i - p.o;
}

LL expected(Team& t, Prob& p) {
    return upDiv(p.i, p.o) + max(5ll, upDiv(p.a, t.c));
}

LL actual(Team& t, Prob& p) {
    return max(0ll, p.i - t.t) + upDiv(p.a, t.z + t.c) + upDiv(p.l, t.v);
}

int main() {
    freopen("unfair.in", "r", stdin);
    freopen("unfair.out", "w", stdout);


    cin >> m >> n >> t >> l;
    for (int i = 0; i < m; ++i) {
        cin >> prob[i].i >> prob[i].a >> prob[i].l >> prob[i].o;
    }
    for (int i = 0; i < t; ++i) {
        cin >> team[i].t >> team[i].z >> team[i].v >> team[i].c;
    }

    size_t ans = 1e9;
    int out = 0;
    for (int msk = 1; msk < (1 << m); ++msk) {
        ed[msk] = ed[msk & (msk - 1)] + 1;
        if (ed[msk] != n) continue;

        vector< pair< pair<LL, LL>, int > > users;
        for (int i = 0; i < t; ++i) {
            vector< pair<LL, LL> > tasks;
            for (int j = 0; j < m; ++j) if (msk & (1 << j) && canSolve(team[i], prob[j])) {
                tasks.push_back(
                    make_pair(expected(team[i], prob[j]), actual(team[i], prob[j]))
                );
            }
            sort(tasks.begin(), tasks.end());
            LL timer = 0;
            LL score = 0;
            LL bad = 0;
            for (int j = 0; j < tasks.size(); ++j) {
                timer += tasks[j].second;
                if (timer > l) break;
                score += 1;
                bad += timer;
            }
            users.push_back(make_pair(make_pair(-score, bad), i));
        }
        sort(users.begin(), users.end());
        for (size_t i = 0; i < users.size(); ++i) if (users[i].second == 0) {
            if (i < ans) {
                ans = i;
                out = msk;
            }
        }
    }
    for (int i = 0; i < m; ++i) if (out & (1 << i))
        cout << (i + 1) << " ";
    cout << endl;
    
    return 0;
}
