#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
typedef long long LL;

struct LD {
    LL x, y;

    LD() : x(0), y(1) { }

    LD(LL x) : x(x), y(1) { }

    LD(LL _x, LL _y) : x(_x), y(_y) {
        if (x == 0) {
            y = 1;
        } else
        if (y == 0) {
            x = 1;
        } else {
            LL g = __gcd(llabs(x), llabs(y));
            x /= g;
            y /= g;
        }
    }

    LD operator*(const LD& t) const {
       return LD(x * t.x, t.y * y);
    }
    LD operator/(const LD& t) const {
       return LD(x * t.y, t.x * y);
    }
    LD operator+(const LD& t) const {
       return LD(x * t.y + t.x * y, t.y * y);
    }
    LD operator-() const {
       return LD(-x, y);
    }
    LD operator-(const LD& t) const {
       return LD(x * t.y - t.x * y, t.y * y);
    }

    bool operator==(const LD& t) const {
       return t.x * y == x * t.y;
    }
};

bool angle_leq(const LD& a, const LD& b) {
    bool za = !(a.x > 0 || a.x == 0 && a.y > 0);
    bool zb = !(b.x > 0 || b.x == 0 && b.y > 0);
    if (za != zb) return za <= zb;
    return a.x * b.y <= b.x * a.y;
}

struct Tp {
    LD x, y;
} a[11], s, b[11], c[11];
int n, o[11];

pair<LD, LD> invalid_angle = make_pair(1e18+1e17+1, 0);
pair<LD, LD> universe_angle = make_pair(1e18+1e17+2, 0);

pair<LD, LD> getangle(const Tp& a, const Tp& b, const Tp& c) {
    LD a1 = (b.y - a.y) / (b.x - a.x);
    LD a2 = (c.y - a.y) / (c.x - a.x);
    return make_pair(a1, a2);
}

bool in(const pair<LD, LD>& seg, const LD& a) {
    if (angle_leq(seg.first, seg.second)) {
        return angle_leq(seg.first, a) && angle_leq(a, seg.second);
    } else {
        return angle_leq(seg.first, a) || angle_leq(a, seg.second);
    }
}

pair<LD, LD> intersect(const pair<LD, LD>& a1, const pair<LD, LD>& a2) {
    if (memcmp(&a1, &universe_angle, sizeof(a2)) == 0) return a2;
    if (memcmp(&a2, &universe_angle, sizeof(a2)) == 0) return a1;
    if (in(a1, a2.first)) {
        if (in(a1, a2.second)) return a2;
        return make_pair(a2.first, a1.second);
    } else if (in(a2, a1.first)) {
        if (in(a2, a1.second)) return a1;
        return make_pair(a1.first, a2.second);
    }
    return invalid_angle;
}

const double PI = atan(1) * 4;
void out(const LD& x) {
    double a = atan2(x.x, x.y);
    cout << a * 180 / PI << "("<<x.x<<","<<x.y<<")";
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    LL x, y;
    cin >> x >> y;
    s.x = x;
    s.y = y;
    for (int i = 0; i < n; ++i) {
        LL x, y;
        cin >> x >> y;
        a[i].x = x;
        a[i].y = y;
    }
    a[n] = a[0];
    for (int i = 0; i < n; ++i) o[i] = i;

    /*
    cerr << angle_leq(LD(0, 1), LD(1, 1)) << endl;
    cerr << angle_leq(LD(1, 1), LD(1, 0)) << endl;
    cerr << angle_leq(LD(1, 0), LD(1, -1)) << endl;
    cerr << angle_leq(LD(1, -1), LD(0, -1)) << endl;
    cerr << angle_leq(LD(0, -1), LD(-1, -1)) << endl;
    cerr << angle_leq(LD(-1, -1), LD(-1, 0)) << endl;
    cerr << angle_leq(LD(-1, 0), LD(-1, 1)) << endl;
    cerr << angle_leq(LD(-1, 1), LD(0, 1)) << endl;
    cerr << endl;
    */

    int ans = 0, it = 0;
    do {
        memcpy(b, a, sizeof(a[0]) * (n + 1));
        pair<LD, LD> angle = universe_angle;
        //cout << "Start! " << ++it << endl;
        for (int i = 1; i <= n; ++i) {
           int f = o[i - 1];

           pair<LD, LD> seg = ((i & 1) == 1) ? getangle(s, b[f], b[f + 1]) : getangle(s, b[f + 1], b[f]);

           /*out(angle.first);
           cout << " ";
           out(angle.second);
           cout << " + ";
           out(seg.first);
           cout << " ";
           out(seg.second);
           */

           angle = intersect(angle, seg);

           /*cout << " = ";
           out(angle.first);
           cout << " ";
           out(angle.second);
           cout << endl;
           */

           if (memcmp(&angle, &invalid_angle, sizeof(angle)) == 0) break;
           if (i == n) break;

           const LD A1 = b[f + 1].y - b[f].y;
           const LD B1 = b[f].x - b[f + 1].x;
           const LD C1 = -A1 * b[f].x - B1 * b[f].y;
           const LD A2 = -B1;
           const LD B2 = A1;
           const LD d = A1 * B2 - A2 * B1;
           for (int j = 0; j < n; ++j) {
               const LD C2 = -A2 * b[j].x - B2 * b[j].y;
               LD dx = -C1 * B2 + C2 * B1;
               LD dy = -A1 * C2 + A2 * C1;
               LD xx = dx / d;
               LD yy = dy / d;
               c[j].x = (xx - b[j].x) * 2 + b[j].x;
               c[j].y = (yy - b[j].y) * 2 + b[j].y;
           }
           c[n] = c[0];
           memcpy(b, c, sizeof(b[0]) * (n + 1));
        }
        if (memcmp(&angle, &invalid_angle, sizeof(angle)) == 0) continue;

        if (angle.first == angle.second) continue;
//        cerr << angle.first / PI * 180 << " " << angle.second / PI * 180 << endl;
//        for (int i = 0; i < n; ++i) cerr << o[i] << " ";
//        cerr << endl << endl;
        ++ans;
    } while(next_permutation(o, o + n));
    cout << ans << endl;

    return 0;
}

