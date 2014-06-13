#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

typedef long double LD;
const LD PI = atan(1) * 4;
const LD eps = 1e-10;

LD S(LD r, LD R, LD d) {
    if (d >= r + R) return 0;
    if (d + r <= R) return PI * r * r;
    if (d + R <= r) return PI * R * R;
    LD a = acos((R * R + d * d - r * r) / (2 * R * d));
    LD b = acos((r * r + d * d - R * R) / (2 * r * d));
    LD S1 = R * R * a - R * R * sin(2 * a) / 2;
    LD S2 = r * r * b - r * r * sin(2 * b) / 2;
    return S1 + S2;
}

LD Dist(LD x1, LD y1, LD x2, LD y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void ERR() {
    puts("impossible");
    exit(0);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    bool swapped = false;
    LD W, H, Sa, Sb, Sab;
    cin >> W >> H;
    cin >> Sa >> Sb >> Sab;

    LD Ra = sqrt(Sa / PI);
    LD Rb = sqrt(Sb / PI);
    if (Ra > Rb) {
        swap(Ra, Rb);
        swap(Sa, Sb);
        swapped = true;
    }

    if (Ra * 2 > W + eps || Ra * 2 > H + eps || Rb * 2 > W + eps || Rb * 2 > H + eps) ERR();
    LD x1 = Ra, y1 = Ra;
    LD x2 = W - Rb, y2 = H - Rb;
    LD d = Dist(x1, y1, x2, y2);

    if (fabs(d) < eps) {
        if (fabs(Sab - min(Sa, Sb)) > eps) ERR();
    } else {
        if (S(Ra, Rb, d) > Sab + eps) ERR();
        LD left = 0;
        LD right = d;
        for (int it = 0; it < 100; ++it) {
            LD center = (left + right) / 2;
            if (S(Ra, Rb, center) < Sab) {
                right = center;
            } else {
                left = center;
            }
        }
        x1 = x2 + (x1 - x2) / d * left;
        y1 = y2 + (y1 - y2) / d * left;
    }

    if (swapped) {
        swap(Ra, Rb);
        swap(Sa, Sb);
        swap(x1, x2);
        swap(y1, y2);
    }
    cout.precision(20);
    cout << fixed;

//    cerr << Dist(x1, y1, x2, y2) << " " << Ra << " " << Rb << endl;
    cout << x1 << " " << y1 << " " << Ra << " " << x2 << " " << y2 << " " << Rb << endl;

    return 0;
}

