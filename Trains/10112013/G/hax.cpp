#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <assert.h>
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
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef long double ld;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 20011;

int n;
int s;
int vmin, vmax;

struct rat {
    ll a, b;

    rat(ll x = 0) {
        a = x;
        b = 1;
    }
    rat(ll x, ll y) {
        a = x;
        b = y;
    }

    bool operator==(const rat& A) const {
        return a * A.b == b * A.a;
    }
    bool operator!=(const rat& A) const {
        return a * A.b != b * A.a;
    }

    bool operator <(const rat& A) const {
        return a * A.b < b * A.a;
    }
    bool operator <(ll x) const {
        return *this < rat(x);
    }
};

struct cell {
    rat angle;
    int type;
    int id;

    cell(rat aangle, int atype, int aid) {
        angle = aangle;
        type = atype;
        id = aid;
    }

    bool operator <(const cell& A) const {
        if (angle != A.angle) return angle < A.angle;
        return type < A.type;
    }
};
 
int used[N];
int X[N], R[N], G[N], D[N];

vector<cell> a;

inline void add(int x, rat tmin, rat tmax, int from, int to, int num) {
    rat minv(x, to);
    rat maxv(x, from);
    if (from == 0) {
        maxv.a = vmax + 1;
        maxv.b = 1; 
    }
    //cerr << "\t[" << ld(minv.a) / minv.b << ";" << ld(maxv.a) / ld(maxv.b) << "]" << endl;

    a.push_back(cell(minv, 1, num));
    a.push_back(cell(maxv, -1, num));                                          
}

vector<int> check(rat vans) {
    vector<int> whos;
    for (int i = 0; i < n; ++i) {
        rat t(ll(X[i]) * vans.b, vans.a);

        int d = D[i];
        while (rat(d + R[i], 1) < t) {
            d += R[i] + G[i];
        }

        while (rat(d, 1) < t) {
            if (t < rat(d + R[i], 1)) {
                whos.push_back(i + 1);
                break;
            }
            d += R[i] + G[i];
        }
    }
    return whos;
}

rat vans;
void relax(vector<int>& whos, rat v) {
    vector<int> cand;
    cand = check(v);
    if (cand.size() < whos.size() || (cand.size() == whos.size() && vans < v)) {
        vans = v;
        whos.swap(cand);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    //cerr.precision(20);
    //cerr << fixed;

    scanf("%d%d%d%d", &n, &s, &vmin, &vmax);
    for (int i = 0; i < n; ++i) {
        int x, r, g, d;
        scanf("%d%d%d%d", &x, &r, &g, &d); 
        X[i] = x; R[i] = r; G[i] = g; D[i] = d;

        rat tmin(x, vmax);
        rat tmax(x, vmin);

        //cerr << "For traffic light #" << i + 1 << endl;
        //cerr << "\tMin time: " << ld(tmin.a) / tmin.b << endl;
        //cerr << "\tMax time: " << ld(tmax.a) / tmax.b << endl;
          

        int period = r + g;
        while (rat(d + r, 1) < tmin) d += period;

        while (!(tmax < rat(d, 1))) {
            add(x, tmin, tmax, d, d + r, i + 1);
            d += period;
        }
    }
    a.push_back(cell(rat(vmin, 1), 0, 0));
    a.push_back(cell(rat(vmax, 1), 0, 0));

    sort(a.begin(), a.end());

    vans = vmax;

    
    int cnt = 0;
    int ans = 1e9;
    int where = 1e9;
    
    //cerr << "Museum:" << endl;
    for (int i = 0; i < a.size(); ++i) {
        if (rat(vmax, 1) < a[i].angle) break;
        //cerr << "\t" << ld(a[i].angle.a) / a[i].angle.b << ": " << a[i].type << endl;

        if (!(a[i].angle < vmin) && cnt <= ans) {
            ans = cnt;
            vans = a[i].angle;
            where = -(i + 1);
        }
        
        cnt += a[i].type;
        
        if (!(a[i].angle < vmin) && cnt <= ans) {
            ans = cnt;
            vans = a[i].angle;
            where = i + 1;
        }
    }
    if (cnt == ans) vans = vmax;

    vector<int> whos = check(vans);
    
    relax(whos, rat(vmax, 1));
    relax(whos, rat(vmin, 1));
    relax(whos, rat((vmax + vmin) / 2, 1));
    

    cout.precision(20);
    cout << fixed;
    cout << ld(vans.a) / vans.b << endl;
    
    assert(!(vans < rat(vmin, 1)) && !(rat(vmax, 1) < vans));
    
    cout << whos.size() << endl;
    for (int i = 0; i < whos.size(); ++i) printf("%d ", whos[i]);

    cout << endl;

    return 0;
}
