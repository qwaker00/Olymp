#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))


#define N 1111

int n;
long double a, b, p[N], q[N], s[N], left, right, rightMax;

long double Calc(long double gn) {
	long double sum = gn * b;
	for (int i = 0; i < n; i++) {
		long double x = p[i] - s[i] * gn;
		if (x > 1e-15) {
			sum += x / q[i] * a;
		}
	}
	return sum;
}

int hn;
long double h[N];
long double ans = 1e100, ansg = 0;

int main() {
    freopen("academy.in", "r", stdin);
    freopen("academy.out", "w", stdout);

    std::cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
    	std::cin >> p[i] >> q[i] >> s[i];
    	rightMax = std::max(right, p[i] / s[i]);
    	h[hn++] = p[i] / s[i];
    }
    h[hn++] = 0;
    std::sort(h, h + hn);

    for (int i = 1; i < hn; i++) {
	    left = h[i - 1];
	    right = h[i];

	    long double g;
/*    	for (int it = 0; it < 200; it++) {
    		long double c1 = left + (right - left) / 3;
	    	long double c2 = right - (right - left) / 3;
    		if (Calc(c2) < Calc(c1)) {
    			left = c1;
	    	} else
    			right = c2;
	    }*/
	    if (Calc(left) < Calc(right)) g = left; else g = right;
	    long double t = Calc(g);
    	if (t < ans) {
    		ans = t;
    		ansg = g;
    	}
	}
    std::cout.precision(10);
    std::cout << std::fixed;
    std::cout << Calc(ansg) << std::endl << ansg << std::endl;
    for (int i = 0; i < n; i++) {
		long double x = p[i] - s[i] * ansg;
		if (x > 1e-15) {
			std::cout << x / q[i] << " ";
		} else std::cout << 0. << " ";   	
    }
    std::cout << std::endl;

    return 0;
}
