#include <iostream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <climits>

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef long double ld;
const LD PI = 3.1415926535897932384626433832795;

template<typename T>
T sqr(const T& x) { return x * x; }

using namespace std;

int main() {
	//freopen(".in","r", stdin);
	//freopen(".out","w", stdout);

	int tnum;                   	
	scanf("%d", &tnum);
	for (int tc = 0; tc < tnum; ++tc) {
		double r1, r2, r3;
		scanf("%lf%lf%lf", &r1, &r2, &r3);
		if (r1 < r2) swap(r1, r2);
		if (r1 < r3) swap(r1, r3);
		if (r2 < r3) swap(r2, r3);
		double p = r3 * (r1 - r2) / (r1 + r2);
		double q = sqrt(sqr(r1 + r3) - sqr(p + r1));
		
		double l = r1 + r2;
		double r = r1 + r2 + r3 + r1 + r2 + r3;
		int itc = 60;
		while (itc >= 0) {
			double mid = (l + r) / 2;
			double R = mid;
			double m = R * (r2 - r1)/(r1 + r2);
			double n = sqrt(sqr(R - r1) - sqr(m + r1));
			double d = sqrt(sqr(p - m) + sqr(q - n));
			if (d + r3 < R) r = mid;
			else l = mid;
			--itc;
		}
		printf("%.15lf\n", l);

	}	

	return 0;
}