#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>

using std::vector;
using std::sort;

struct Tp {
    int x, y;

    bool operator<(const Tp& t) const {
        return y < t.y || y == t.y && x < t.x;
    }
} a[111];


int mul(int i, int j, int k) {
    return (a[k].x - a[i].x) * (a[j].y - a[i].y) - (a[k].y - a[i].y) * (a[j].x - a[i].x);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int __it = 0;
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        sort(a, a + n);

        vector<int> st1;
        vector<int> st2;
        for (int i = 0; i < n; ++i) {
            while (st1.size() > 1 && mul(st1[st1.size() - 2], st1[st1.size() - 1], i) >= 0) st1.pop_back();
            while (st2.size() > 1 && mul(st2[st2.size() - 2], st2[st2.size() - 1], i) <= 0) st2.pop_back();
            st1.push_back(i);
            st2.push_back(i);
        }
        st2.pop_back();
        std::reverse(st2.begin(), st2.end());
        st2.pop_back();
        st1.insert(st1.begin(), st2.begin(), st2.end());

        st1.push_back(st1[0]);

        double mind = 1e100;
        for (int i = 1; i < st1.size(); ++i) {
            double A = a[st1[i]].y - a[st1[i - 1]].y;
            double B = a[st1[i - 1]].x - a[st1[i]].x;
            double C = -A * a[st1[i]].x - B * a[st1[i]].y;
            double maxd = 0;
            for (int j = 0; j < st1.size(); ++j) {
                double D = fabsl( double(A * a[st1[j]].x + B * a[st1[j]].y + C) / sqrtl(A * A + B * B) );
                if (D > maxd) maxd = D;
            }
            if (maxd < mind) mind = maxd;
        }
        ++__it;

        if (fmodl(mind * 100, 1) > 1e-9)
            mind = (mind * 100 - fmodl(mind * 100, 1) + 1 + 1e-9) / 100;
        else
            mind = (mind * 100 - fmodl(mind * 100, 1) + 1e-9) / 100;

        printf("Case %d: %.2lf\n", __it, mind);
    }


    return 0;
}

