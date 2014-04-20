#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

#define G 1

using namespace std;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    LD H, R, r1, h1, r2, h2, r, n;
	cin >> H >> R >> r2 >> h2 >> r1 >> h1 >> r >> n;

	LD S = PI * R * R;

	LD left = h1 + h2;
	LD right = min(H, (S * (h1 + h2) + n * n * n) / S);
	for (int it = 0; it < 200; ++it) {
		LD h = (left + right) / 2;
		LD Vp = S * (h - h1 - h2);
		LD dh = h - h1 - h2;
		LD hp = Vp / (n * n);
		LD hdown = hp - dh;

		if (hdown > h1 + h2) {
			right = h;
			continue;
		}

		LD m = n * n * n * r;
		if (hdown < h1) {			
			if (r1 * Vp * G > m * G) {
				right = h;
			} else {
				left = h;
			}

		} else {
			LD hfirst = (S * h1) / (S - n * n);
			LD hdeep = hp - hfirst;
			
			if (r1 * n * n * hfirst * G + r2 * n * n * hdeep * G > m * G) {
				right = h;
			} else {
				left = h;
			}
		}
	}
	cout.precision(10);
	cout << fixed << left << endl;
		
    
    return 0;
}
