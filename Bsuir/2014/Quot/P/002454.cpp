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

struct Tp {
    LL A, B, C;
} a[1111];
int n;

LL gcd(LL a, LL b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct Trat {
    LL a, b;

    Trat() : a(0), b(1) {}
    Trat(LL a) : a(a), b(1) {}
    Trat(LL av, LL bv) : a(av), b(bv) {
        if (b == 0) a = 1;
        if (a == 0) b = 1;
        if (b < 0) {
            b = -b;
            a = -a;
        }
        LL g = gcd(llabs(a), b);
        a /= g;
        b /= g;
    }
    bool operator<(const Trat& t) const {
        return a * t.b < t.a * b;
    }
};


typedef pair<Trat, Trat> point;

map<point, int> id;
int ids = 0;

int getid(const point& p) {
    if (id.count(p)) return id[p];
    return id[p] = ids++;
}

vector<int> g[500555];

int was[500555];

void dfs(int x) {
    was[x] = 1;
    for (int i = 0; i <g[x].size(); ++i) {
        if (!was[g[x][i]]) {
            dfs(g[x][i]);
        }
    }
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i].A = y2 - y1;
        a[i].B = x1 - x2;
        a[i].C = -x1 * a[i].A - y1 * a[i].B;
    }
    for (int i = 0; i < n; ++i) {
        vector<point> pts;
        for (int j = 0; j < n; ++j) if (i != j) {
            if (a[i].A * a[j].B == a[i].B * a[j].A) continue;
            LL d = a[i].A * a[j].B - a[i].B * a[j].A;
            LL dx = a[j].C * a[i].B - a[i].C * a[j].B;
            LL dy = a[j].A * a[i].C - a[i].A * a[j].C;
            Trat x(dx, d), y(dy, d);
            pts.push_back(point(x, y));
            getid(pts.back());
        }
        sort(pts.begin(), pts.end());
        for (int i = 1; i < (int)pts.size(); ++i) {
            int id1 = getid(pts[i - 1]);
            int id2 = getid(pts[i]);
            if (id1 != id2) {
                g[id1].push_back(id2);
                g[id2].push_back(id1);
            }
        }
    }

    int m = 0;
    for (int i = 0; i < ids; ++i) {
        sort(g[i].begin(), g[i].end());
        m += unique(g[i].begin(), g[i].end()) - g[i].begin();
    }

//    cerr << ids << endl;
//    cerr << m << endl;

    int k = 0;
    for (int i = 0; i < ids; ++i) if (!was[i]) {
        dfs(i);
        ++k;
    }

    cout << k + m / 2 - ids << endl;
    
    return 0;
}
