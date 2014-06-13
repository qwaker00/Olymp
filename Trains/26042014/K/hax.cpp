#include <cstdio>
#include <memory.h>
#include <vector>
#include <assert.h>
#include <cmath>
#include <algorithm>

using std::vector;
using std::random_shuffle;
typedef long long ll;
typedef long double ld;

struct Tp {
    ll x, y, z;
    char label;
} p[11];
struct Tpd {
    ld x, y, z;

    Tpd() {
        x = y = z = 0;
    }

    Tpd(Tp& t) {
        x = t.x;
        y = t.y;
        z = t.z;
    }
};

inline void CalcABCD(const Tp& a, const Tp& b, const Tp& c, ll& A, ll& B, ll& C, ll& D) {
    A = (b.y - a.y) * (c.z - a.z) - (c.y - a.y) * (b.z - a.z);
    B = (c.x - a.x) * (b.z - a.z) - (b.x - a.x) * (c.z - a.z);
    C = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    D = -A * a.x -B * a.y -C * a.z;
}

inline void CalcABCD(const Tpd& a, const Tpd& b, const Tpd& c, ld& A, ld& B, ld& C, ld& D) {
    A = (b.y - a.y) * (c.z - a.z) - (c.y - a.y) * (b.z - a.z);
    B = (c.x - a.x) * (b.z - a.z) - (b.x - a.x) * (c.z - a.z);
    C = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    D = -A * a.x -B * a.y -C * a.z;
}

inline ld Di(const Tpd& A, const Tpd& B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) +  (A.z - B.z) * (A.z - B.z));
}

inline ld Sq(const Tpd& a, const Tpd& b, const Tpd& c) {
    ld A, B, C, D;
    CalcABCD(a, b, c, A, B, C, D);
    return fabs(sqrt(A * A + B * B + C * C) / 2);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int it = 0;
    while (1) {
        ++it;

        for (int i = 0; i < 6; ++i) {
            int x, y, z;
            if (scanf("%d%d%d", &x, &y, &z) != 3) return 0;
            p[i].label = 'A' + i;
            p[i].x = x;
            p[i].y = y;
            p[i].z = z;
        }

        double ansmin = 1e100;
        double ansmax = -1e100;

        ll A, B, C, D;
        CalcABCD(p[0], p[1], p[2], A, B, C, D);
        ld m1 = fabs( ld(A * p[3].x + B * p[3].y + C * p[3].z + D) / 6 );
        ld m2 = fabs( ld(A * p[4].x + B * p[4].y + C * p[4].z + D) / 6 );
        ld cx = (m1 * (p[0].x + p[1].x + p[2].x + p[3].x) / 4 + m2 * (p[0].x + p[1].x + p[2].x + p[4].x) / 4) / (m1 + m2);
        ld cy = (m1 * (p[0].y + p[1].y + p[2].y + p[3].y) / 4 + m2 * (p[0].y + p[1].y + p[2].y + p[4].y) / 4) / (m1 + m2);
        ld cz = (m1 * (p[0].z + p[1].z + p[2].z + p[3].z) / 4 + m2 * (p[0].z + p[1].z + p[2].z + p[4].z) / 4) / (m1 + m2);

        for (int _i = 0; _i < 5; ++_i)
            for (int _j = _i + 1; _j < 5; ++_j)
                for (int _k = _j + 1; _k < 5; ++_k) {
                    vector<Tp> e;
                    int eN = 0, eP = 0;

                    ll A, B, C, D;
                    CalcABCD(p[_i], p[_j], p[_k], A, B, C, D);
                    if (A == 0 && B == 0 && C == 0) continue;

                    for (int ii = 0; ii < 5; ++ii) {
                        ll delta = A * p[ii].x + B * p[ii].y + C * p[ii].z + D;
                        if (delta == 0) e.push_back(p[ii]);else
                            if (delta < 0) ++eN;else ++eP;
                    }

                    if (eN > 0 && eP > 0) continue;
                    assert( e.size() <= 4 );
                    if (e.size() == 4) {
                        while (true) {
                            bool bad = false;
                            for (int i = 1; i < 4; ++i) if (e[i].label > 'C' && e[i - 1].label > 'C') {
                                bad = true;
                                break;
                            }
                            if (bad) {
                                random_shuffle(e.begin(), e.end());
                                continue;
                            }
                            break;
                        }
                    }
                    e.push_back(e.front());

                    ld lambda = (A * cx + B * cy + C * cz + D) / (A * A + B * B + C * C);
                    Tpd c;
                    c.x = cx - A * lambda;
                    c.y = cy - B * lambda;
                    c.z = cz - C * lambda;
                    bool bad = false;
                    ld ss = 0, ss2 = 0;
                    for (int i = 1; i < e.size(); ++i) {
                        ld d = 2 * Sq(c, e[i], e[i - 1]) / Di(e[i], e[i - 1]);
                        ss += Sq(c, e[i], e[i - 1]);
                        ss2 += Sq(e[0], e[i - 1], e[i]);
                        if (d < 0.2 + 1e-10) bad = true;
                    }
                    if (fabs(ss - ss2) > 1e-10) {
                        continue;
                    }
                    if (!bad) {
                        ld d = fabs(A * p[5].x + B * p[5].y + C * p[5].z + D) / sqrt(A * A + B * B + C * C);
                        if (d > ansmax) ansmax = d;
                        if (d < ansmin) ansmin = d;
                    }
                }



        printf("Case %d: %.5lf %.5lf\n", it, ansmin, ansmax);
    }

    return 0;
}
