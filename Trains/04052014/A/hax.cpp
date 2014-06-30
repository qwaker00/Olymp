#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
const LL INF = 9e18;

LL A[33], B[33];
LL f[33][2][2];

LL minimize(LL& x, LL y) {
    if (x > y) x = y;
}

LL calcMinSum(LL b, LL a, LL m, int mc, int si = 0, int sj = 1, int sk = 1) {
    for (int i = 0; i < mc; ++i) {
        A[mc - i - 1] = a % m;
        a /= m;
    }
    for (int i = 0; i < mc; ++i) {
        B[mc - i - 1] = b % m;
        b /= m;
    }
//    if (b) return INF;
    A[0] += a * m;
    B[0] += b * m;

    memset(f, 63, sizeof(f));
    f[si][sj][sk] = 0;
    for (int i = si; i < mc; ++i) {
        vector<LL> dd;
        dd.push_back(0);
        if (A[i] > 0)
            dd.push_back(A[i] - 1);
        dd.push_back(A[i] + 1);
        dd.push_back(A[i]);
        if (B[i] > 0)
            dd.push_back(B[i] - 1);
        dd.push_back(B[i] + 1);
        dd.push_back(B[i]);
        dd.push_back(m - 1);
        dd.push_back(m);

        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k) if (f[i][j][k] < 1e18) {
                for (int di = 0; di < dd.size(); ++di) {
                    int d = dd[di];

                    if (j && d > A[i]) continue;
                    if (k && d < B[i]) continue;
                    minimize(f[i + 1][j && d == A[i]][k && d == B[i]], f[i][j][k] + d);
                }
            }
    }
    LL ans = INF;
    for (int i= 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            minimize(ans, f[mc][i][j]);
    return ans;
}

vector<LL> restore(LL b, LL a, LL m, int mc, LL opt) {
    LL _b = b, _a = a;
    for (int i = 0; i < mc; ++i) {
        A[mc - i - 1] = a % m;
        a /= m;
    }
    for (int i = 0; i < mc; ++i) {
        B[mc - i - 1] = b % m;
        b /= m;
    }
//    if (b) return INF;
    A[0] += a * m;
    B[0] += b * m;

    memset(f, 63, sizeof(f));
    int j = 1, k = 1;
    LL s = 0;
    vector<LL> ans;
    for (int i = 0; i < mc; ++i) {
        vector<LL> dd;
        dd.push_back(0);
        if (A[i] > 0)
            dd.push_back(A[i] - 1);
        dd.push_back(A[i] + 1);
        dd.push_back(A[i]);
        if (B[i] > 0)
            dd.push_back(B[i] - 1);
        dd.push_back(B[i] + 1);
        dd.push_back(B[i]);
        dd.push_back(m - 1);
        dd.push_back(m);
        sort(dd.rbegin(), dd.rend());

        for (int di = 0; di < dd.size(); ++di) {
            int d = dd[di];

            if (j && d > A[i]) continue;
            if (k && d < B[i]) continue;

            if (calcMinSum(_b, _a, m, mc, i + 1, j && d == A[i], k && d == B[i]) + s + d == opt) {
                ans.push_back(d);
                j &= d == A[i];
                k &= d == B[i];
                s += d;
                break;
            }
        }
    }
    return ans;
}

vector<LL> solveRestore(LL a, LL b, LL add, LL m, int mc, LL opt) {
    if (a < 0) a = 0;
    a = (a + add - 1) / add;
    b /= add;
    if (mc == 0) {
        return vector<LL>(1, a);
    }
    return restore(a, b, m, mc + 1, opt);
}

LL solve(LL a, LL b, LL add, LL m, int mc) {
    if (b < 0) return INF;
    if (a > b) return INF;
    if (a < 0) a = 0;

    a = (a + add - 1) / add;
    b /= add;
    if (a > b) return INF;

    if (mc == 0) {
        return a;
    }
/*    else if (mc == 1) {
        if (a >= m * m) return INF;
        LL rets = INF, ret = INF;
        for (LL y = 0; y < m; ++y) {
            LL x = (a - y + m - 1) / m;
            if (x * m + y >= a && x * m + y <= b && x + y < rets) {
                rets = x + y;
                ret = x * m + y;
            }
        }
        return rets;
    }*/
    return calcMinSum(a, b, m, mc + 1);
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int __it = 0;
    while (1) {
        int a, m, p, q, r, s;
        scanf("%d%d%d%d%d%d", &a, &m, &p, &q, &r, &s);
        if (a == 0) break;


        ++__it;
        printf("Case %d:", __it);

        if (p >= r && p <= s && q >= r && q <= s) {
            puts(" empty");
            continue;
        }

        LL rr = r;
        LL mm = 1;
        LL mi = INF;
        LL mimm = 0;
        int mii = 0;
        for (int mc = 0; rr; ++mc) {
            LL t = solve(r - mm * p, s - mm * q, a, m, mc) + mc;
            if (t < mi) {
                mi = t;
                mii = mc;
                mimm = mm;
            }

            if (m == 1) break;
            rr /= m;
            mm *= m;
        }

        if (mi == INF)
            puts(" impossible");
        else {
            vector<LL> ans = solveRestore(r - mimm * p, s - mimm * q, a, m, mii, mi - mii);
            int mc = -1;
            for (int i = 0; i < ans.size(); ++i) {
                ++mc;
                if (ans[i] > 0) {
                    if (mc > 0) {
                        cout << ' ' << mc << 'M';
                        mc = 0;
                    }
                    cout << ' ' << ans[i] << 'A';
                }
            }
            if (mc > 0)
                cout << ' ' << mc << 'M';
            puts("");
        }
    }


    return 0;
}

