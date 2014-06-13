#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef unsigned long long ULL;

struct Tp {
    double x, y;

    double sq() {
        return x * x + y * y;
    }
} a[111];
double R;


const double eps = 1e-8;

void intersect(Tp& a, Tp& b, double R, vector<Tp>& pts) {
    double A = a.y - b.y;
    double B = b.x - a.x;
    double C = -A * a.x - B * a.y;
    double distSQ = fabs(C) * fabs(C) / (A * A + B * B);
    if (distSQ > R * R) {
        pts.push_back(a);
        pts.push_back(b);
        return;
    }

    double A1 = -B;
    double B1 = A;
    double C1 = 0;

    double delta = A * B1 - B * A1;
    double deltaX = -C * B1 + B * C1;
    double deltaY = -A * C1 + C * A1;

    double x0 = deltaX / delta;
    double y0 = deltaY / delta;

    double dd = sqrt(R * R - distSQ) / sqrt(A * A + B * B);

    Tp p1, p2;
    p1.x = x0 - B * dd;
    p1.y = y0 + A * dd;

    p2.x = x0 + B * dd;
    p2.y = y0 - A * dd;

    vector<Tp> pp;
    if (fabs(fabs(b.x - a.x) - fabs(a.x - p2.x) - fabs(b.x - p2.x)) < eps &&
        fabs(fabs(b.y - a.y) - fabs(a.y - p2.y) - fabs(b.y - p2.y)) < eps)
    {
        pp.push_back(p2);
    }
    if (fabs(fabs(b.x - a.x) - fabs(a.x - p1.x) - fabs(b.x - p1.x)) < eps &&
        fabs(fabs(b.y - a.y) - fabs(a.y - p1.y) - fabs(b.y - p1.y)) < eps)
    {
        pp.push_back(p1);
    }

    if (pp.size() == 2) {
        double t1, t2;
        if (fabs(a.y - b.y) < eps) {
            t1 = (pp[0].x - a.x) / (b.x - a.x);
            t2 = (pp[1].x - a.x) / (b.x - a.x);
        } else {
            t1 = (pp[0].y - a.y) / (b.y - a.y);
            t2 = (pp[1].y - a.y) / (b.y - a.y);
        }
        if (t1 > t2) swap(pp[0], pp[1]);
    }
    pp.insert(pp.begin(), a);
    pp.push_back(b);

    for (int i = 0; i < pp.size(); ++i) {
        //if (pp[i].sq() > R * R + eps) continue;
        pts.push_back(pp[i]);
    }
}


double Calc(double x1, double x2, double R) {
    double a2 = acos(x2 / R);
    double a1 = acos(x1 / R);
    return (R*R/2 * (sin(2*a2)/2 - a2)) - (R*R/2 * (sin(2*a1)/2 - a1));
}

void process(Tp& a, Tp& b, bool in, double& ans) {
    if (in || fabs(a.sq() - R * R) > eps || fabs(b.sq() - R * R) > eps)
        ans += (b.x - a.x) * (b.y + a.y) / 2;
    else
        ans += Calc(a.x, b.x, R);
}

int main() {
    //freopen(".in", "r", stdin);

    int n;
    cin >> n >> R;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    a[n] = a[0];

    vector<Tp> pts;
    for (int i = 0; i < n; ++i) {
        intersect(a[i], a[i + 1], R, pts);
    }
    if (pts.size() < 2) {
        cout << 0 << endl;
        return 0;
    }

    bool found = 0;
    for (int i = 0; i < pts.size(); ++i) {
        if (pts[i].sq() > R*R + eps) {
            rotate(pts.begin(), pts.begin() + i, pts.end());
            found = 1;
            break;
        }
    }

    double ans = 0;
    if (!found) {
        pts.push_back(pts.front());
        for (int i = 0; i + 1 < pts.size(); ++i) {
            ans += (pts[i + 1].x - pts[i].x) * (pts[i].y + pts[i + 1].y) / 2;
        }
    } else {
        bool in = false;
        bool first = true;
        Tp lastp, firstp;
        for (int i = 0; i < pts.size(); ++i) {
            if (pts[i].sq() - R*R < eps) {
                if (!first) {
                    process(lastp, pts[i], in, ans);
                } else
                    firstp = pts[i];
                lastp = pts[i];
                first = false;
                if (fabs(pts[i].sq() - R*R) < eps) in ^= true;
            }
        }
        process(lastp, firstp, in, ans);
    }

    cout.precision(10);
    cout << fixed << fabs(ans) << endl;

    return 0;
}
