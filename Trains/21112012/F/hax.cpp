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
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct Tp {
    LD x, y;

    LD operator*(const Tp& A) const {
        return x * A.x + y * A.y;
    } 

    LD operator!() const {
        return sqrtl(x * x + y * y);
    }

    Tp operator-(const Tp& A) const {
        Tp res;
        res.x = x - A.x;
        res.y = y - A.y;
        return res;
    } 
    Tp operator+(const Tp& A) const {
        Tp res;
        res.x = x + A.x;
        res.y = y + A.y;
        return res;
    } 
    Tp operator*(const LD& A) const {
        Tp res;
        res.x = x * A;
        res.y = y * A;
        return res;
    } 

    Tp operator%(LD A) const {
        Tp res;
        res.x = cos(A) * x - sin(A) * y;
        res.y = sin(A) * x + cos(A) * y;
        return res;
    }
} a[4], ans[4];

struct Line {
    LD A, B, C;

public:
    Line(Tp a = Tp(), Tp b = Tp()) {
        A = a.y - b. y;
        B = a.x - b.x;
        C = - a.x * A - a.y * B;
    }

    static Line Perpend(Line l, Tp p) {
        Line res;
        
        res.A = l.B;
        res.B = -l.A;
        res.C = -p.x * res.A -p.y * res.B;

        return res;
    }
};

class ByAng {
    Tp a;

public:
    ByAng(Tp& a) : a(a) { }

    bool operator()(const Tp& A, const Tp &B) const {
        return (A.x - a.x) * (B.y - a.y) > (B.x - a.x) * (A.y - a.y);
    }
};

#define eps 1e-12

bool Check(Tp a[4], Tp ans[4]) {
    sort(a + 1, a + 4, ByAng(a[0]) );

    LD u = acos( (a[1] - a[0]) * (a[3] - a[0]) / !(a[1] - a[0]) / !(a[3] - a[0]) );
    LD v = acos( (a[0] - a[3]) * (a[2] - a[3]) / !(a[0] - a[3]) / !(a[2] - a[3]) );

    LD A = !(a[0] - a[3]);
    LD B = !(a[2] - a[3]);
    LD C = !(a[0] - a[1]);

    LD ang = atan2( A - C * cos(u) - B * sin(v), A - B * cos(v) - C * sin(u) );
    if (ang < - PI / 2) ang += PI;
    if (ang > PI / 2) ang -= PI;

    if ( !(ang < v - eps && PI / 2 - ang < u - eps) ) {
        return false;
    }    

    Line l1(ans[0], a[0]);
    Line l2(ans[0], a[3]);
    Line l3 = Line::Perpend(l2, a[2]);
    Line l4 = Line::Perpend(l1, a[1]);


//    ans[3] = l1.Intersect(l4);
//    ans[2] = l1.Intersect(l4);
//    ans[1] = l1.Intersect(l4);

    Tp p0 = (a[0] + a[3]) * 0.5;
    Tp dv = (a[3] - a[0]) * 0.5;
    dv = dv % (ang + ang);
    ans[0] = p0 + dv;

    Tp vv = a[3] - ans[0];
    Tp vv2 = (a[2] + a[3]) * 0.5 - a[3];
    LD alpha = (vv2.x * vv.x + vv2.y * vv.y) / (!vv * !vv);
    ans[1] = a[3] + vv * alpha * 2;

    vv = a[2] - ans[1];
    vv2 = (a[1] + a[2]) * 0.5 - a[2];
    alpha = (vv2.x * vv.x + vv2.y * vv.y) / (!vv * !vv);
    ans[2] = a[2] + vv * alpha * 2;

    vv = a[1] - ans[2];
    vv2 = (a[0] + a[1]) * 0.5 - a[1];
    alpha = (vv2.x * vv.x + vv2.y * vv.y) / (!vv * !vv);
    ans[3] = a[1] + vv * alpha * 2;
    
//    cout << ans[0].x << " " << ans[0].y << endl;
//    cout << ans[1].x << " " << ans[1].y << endl;
//    cout << ans[2].x << " " << ans[2].y << endl;
//    cout << ans[3].x << " " << ans[3].y << endl;
//    cout << endl;
    return true;
}

int main() {
    freopen("four.in", "r", stdin);
    freopen("four.out", "w", stdout);

    cout.precision(10);
    cout << fixed;

    int perm[4];
    for (int i = 0; i < 4; ++i) {
        cin >> a[i].x >> a[i].y;
        perm[i] = i;
    }

    do {
        Tp aa[4];
        for (int i = 0; i < 4; i++) aa[i] = a[perm[i]];
        if (Check(a, ans)) {
            for (int i = 0; i < 4; i ++) {
                cout << ans[i].x << " " << ans[i].y << endl; 
            }
            return 0;
        }
    } while (next_permutation(perm, perm + 4));
            for (int i = 0; i < 4; i ++) {
                cout << 0 << " " << 0 << endl; 
            }
    
    return 0;
}
