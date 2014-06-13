#include <cstdio>
#include <vector>
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef long double LD;

const LD PI = acos(-1);
const LD R = 6400;

struct Tp {
    LD x, y, z;
} a[111], P;


LD ans = 1e100;

LD dist(const Tp& a, const Tp& b) {
    LD d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
    LD alpha = 2 * asin(d / (2 * R));
    LD ret = alpha * R;
    if (ret < ans) ans = ret;
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    {
        LD la, lo;
        cin >> la >> lo;
        P.z = R * sin(la / 180.0 * PI);
        P.x = R * cos(la / 180.0 * PI) * sin(lo / 180.0 * PI);
        P.y = R * cos(la / 180.0 * PI) * cos(lo / 180.0 * PI);
    }

    for (int i = 0; i < n; ++i) {
        LD lat, lon;
        cin >> lat >> lon;
        a[i].z = R * sin(lat / 180.0 * PI);
        a[i].x = R * cos(lat / 180.0 * PI) * sin(lon / 180.0 * PI);
        a[i].y = R * cos(lat / 180.0 * PI) * cos(lon / 180.0 * PI);
    }
    a[n] = a[0];

    for (int i = 0; i < n; ++i) {
        double left = 0;
        double right = 1;
        dist(P, a[i]);
        for (int it = 0; it < 100; ++it) {
            double c1 = left + (right - left) / 3;
            double c2 = right - (right - left) / 3;

            Tp p1, p2;
            {
                p1.x = a[i].x + (a[i + 1].x - a[i].x) * c1;
                p1.y = a[i].y + (a[i + 1].y - a[i].y) * c1;
                p1.z = a[i].z + (a[i + 1].z - a[i].z) * c1;
                LD d = sqrt(p1.x * p1.x + p1.y * p1.y + p1.z * p1.z);
                p1.x *= R / d;
                p1.y *= R / d;
                p1.z *= R / d;
            }
            {
                p2.x = a[i].x + (a[i + 1].x - a[i].x) * c2;
                p2.y = a[i].y + (a[i + 1].y - a[i].y) * c2;
                p2.z = a[i].z + (a[i + 1].z - a[i].z) * c2;
                LD d = sqrt(p2.x * p2.x + p2.y * p2.y + p2.z * p2.z);
                p2.x *= R / d;
                p2.y *= R / d;
                p2.z *= R / d;
            }

            if (dist(P, p1) < dist(P, p2)) {
                right = c2;
            } else {
                left = c1;
            }
        }
    }
    cout.precision(10);
    cout << fixed;
    cout << ans << endl;

    return 0;
}
