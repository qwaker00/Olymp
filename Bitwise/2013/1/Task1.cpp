#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using std::vector;
using std::min;
using std::sort;
using std::fixed;
using std::cin;
using std::cout;
using std::endl;

const int N = 4444;
const int ITER = 40;

int X0[N], Y0[N];

double getSign(double x, double y) {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

double getPoint(double X0, double Y0, double sign0, double y) {
    double dx2 = -16. * (y - Y0);
    return X0 + sign0 * sqrt(dx2);
}

double asinh(double x) {
    return logl(x + sqrtl(x*x + 1));
}

double sqr(double x) {
    return x * x;
}

double getPoint(double X0, double Y0, double x) {
    return (-sqr(X0 - x) / 16. + Y0);
}

void doit(vector<double>& a, double x0, double y0, double x1, double y1) {
    double x = 8 * ((x0 * x0 - x1 * x1) / 16 - y0 + y1) / (x0 - x1);
    a.push_back(x);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        vector<double> points;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int tx, ty;
            scanf("%d%d", &tx, &ty);
            X0[i] = tx; Y0[i] = ty;

            if (Y0[i] <= 0) {
                --i;
                --n;
            }

            double dx = sqrt(double(Y0[i])) * 4;
            points.push_back(double(X0[i]) - dx);
            points.push_back(double(X0[i]) + dx);
        }


        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                if (X0[i] == X0[j]) continue;

                doit(points, X0[i], Y0[i], X0[j], Y0[j]);
            }

        sort(points.begin(), points.end());


        double ans = 0;
        for (int i = 0; i + 1 < points.size(); ++i) {
            double cx = (points[i] + points[i + 1]) / 2.;

            double besty = -1;
            int num = -1;
            for (int j = 0; j < n; ++j) {
                double cand = getPoint(X0[j], Y0[j], cx);
                if (cand > besty) {
                    besty = cand;
                    num = j;
                }
            }

            if (besty <= 0) continue;

            double l = points[i], r = points[i + 1];
            double x0 = X0[num];
            
            ans += (sqrtl(64 + sqr(r - x0)) * (r - x0) / 16 + 4 * asinh((r - x0) / 8)) -
                   (sqrtl(64 + sqr(l - x0)) * (l - x0) / 16 + 4 * asinh((l - x0) / 8));
        }
        
        cout.precision(2);
        cout << fixed;
        cout << ans << endl;
    }

    return 0;
}

