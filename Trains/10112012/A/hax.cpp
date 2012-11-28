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

typedef long double LD;
typedef long long LL;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


struct cellll {
    ll x, y, z;

    cellll(ll ax = 0, ll ay = 0, ll az = 0) : x(ax), y(ay), z(az) {}
};

struct cell {
    ld x, y, z;

    cell(ld ax = 0, ld ay = 0, ld az = 0) : x(ax), y(ay), z(az) {}

    cell(cellll A) : x(A.x), y(A.y), z(A.z) {}
};
               

inline ld det2(ld x11, ld x12, ld x21, ld x22) {
    return x11 * x22 - x12 * x21;
}

inline ld det3(cell a, cell b, cell c) {
    return a.x * det2(b.y, b.z, c.y, c.z) - a.y * det2(b.x, b.z, c.x, c.z) + a.z * det2(b.x, b.y, c.x, c.y);
}

inline ll det2(ll x11, ll x12, ll x21, ll x22) {
    return x11 * x22 - x12 * x21;
}

inline ll det3(cellll a, cellll b, cellll c) {
    return a.x * det2(b.y, b.z, c.y, c.z) - a.y * det2(b.x, b.z, c.x, c.z) + a.z * det2(b.x, b.y, c.x, c.y);
}

inline ld sq(cell a, cell b) {
    ld A = a.y * b.z - a.z * b.y;
    ld B = a.x * b.z - a.z * b.x;
    ld C = a.x * b.y - a.y * b.x;
    return sqrtl(A*A + B*B + C*C);
}

inline ld myabs(ld x) {
    if (x < 0) return -x;
    return x;
}

double doit() {
    int n;
    cin >> n;
    vector<cellll> a(n);

    cell center;

    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    ld ans = 1e16;

    int cnt = 0;

    vector<cell> centers;

    for (int i1 = 0; i1 < n; ++i1)
        for (int i2 = i1 + 1; i2 < n; ++i2)
            for (int i3 = i2 + 2; i3 < n; ++i3) {
                cellll A(a[i1].x - a[i3].x, a[i1].y - a[i3].y, a[i1].z - a[i3].z);
                cellll B(a[i2].x - a[i3].x, a[i2].y - a[i3].y, a[i2].z - a[i3].z);

                bool bad = false;
                bool ls = true, gr = true;
                for (int j = 0; j < n; ++j) {
                    cellll C(a[j].x - a[i3].x, a[j].y - a[i3].y, a[j].z - a[i3].z);
                    ll value = det3(A, B, C);
                    if (value < 0) gr = false;
                    if (value > 0) ls = false;  
                    if (value == 0 && i1 != j && i2 != j && j < i3) {
                        bad = true;
                        break;
                    }
                }
                if (bad) continue;

                cell localc;
                int cntl = 0;
                for (int j = 0; j < n; ++j) {
                    cellll C(a[j].x - a[i3].x, a[j].y - a[i3].y, a[j].z - a[i3].z);
                    ll value = det3(A, B, C);
                    if (value == 0) {
                        localc.x += a[j].x;
                        localc.y += a[j].y;
                        localc.z += a[j].z;
                        ++cntl;
                    }    
                }
                localc.x /= double(cntl); 
                localc.y /= double(cntl);
                localc.z /= double(cntl);


                if ((gr && !ls) || (!gr && ls)) {
                    ++cnt;

                    center.x += localc.x;
                    center.y += localc.y;
                    center.z += localc.z;
                }     
            }

    center.x /= double(cnt);
    center.y /= double(cnt);
    center.z /= double(cnt);
    cerr << center.z << endl;


    for (int i1 = 0; i1 < n; ++i1)
        for (int i2 = i1 + 1; i2 < n; ++i2)
            for (int i3 = i2 + 2; i3 < n; ++i3) {
                cellll A(a[i1].x - a[i3].x, a[i1].y - a[i3].y, a[i1].z - a[i3].z);
                cellll B(a[i2].x - a[i3].x, a[i2].y - a[i3].y, a[i2].z - a[i3].z);

                bool ls = true, gr = true;
                for (int j = 0; j < n; ++j) {
                    cellll C(a[j].x - a[i3].x, a[j].y - a[i3].y, a[j].z - a[i3].z);
                    ll value = det3(A, B, C);
                    if (value < 0) gr = false;
                    if (value > 0) ls = false;  
                }

                if ((gr && !ls) || (!gr && ls)) {
                    cell nA(A), nB(B);
                    cell nC(center.x - a[i3].x, center.y - a[i3].y, center.z - a[i3].z);
                    ld square = sq(nA, nB);
                    ld volume = myabs(det3(nA, nB, nC));
                    ans = min(ans, volume / square);
                }     
            }

    return ans;
}

int main() {
    freopen("asteroids.in", "r", stdin);
    freopen("asteroids.out", "w", stdout);

    cout.precision(10); cout << fixed;
    cout << doit() + doit() << endl;
    return 0;

    cout.precision(10);
    cout << fixed;
    cout << doit() << endl;
    cout << doit() << endl;
    //cout << doit() + doit() << endl;


    return 0;
}
