#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef long long LL;
typedef long double LD;
using namespace std;


LL gcd(LL x, LL y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

struct Rat {
    LL x, y;

    Rat(LL _x, LL _y) : x(_x), y(_y) {
        LL g = gcd(llabs(x), llabs(y));
        x /= g;
        y /= g;
    }
    Rat operator+(const Rat& b) const {
        return Rat(x * b.y + b.x * y, y * b.y);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout.precision(10);
    Rat s(0, 1);
    for (int i = 0; i < 200000; ++i) {
        Rat x = s + Rat(4, 8 * i + 1) + Rat(-2, 8 * i + 4) + Rat(-1, 8 * i + 5) + Rat(-1, 8 * i + 6);
        cout << (x.x / x.y) << " " << x.x << "/" << x.y << endl;
        s = Rat((x.x % x.y) * 16, x.y);
    }
    return 0;
}
