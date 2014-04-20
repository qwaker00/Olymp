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

using namespace std;

#define y1 botva
#define y2 botvabotva

const int N = 111;
const int iter = 70;

LD xl[N], xr[N], a[N], b[N], c[N];
LD x1, y1, x2, y2;

inline LD msqr(LD x) {
	return x * x;
}

inline LD dist(LD x1, LD y1, LD x2, LD y2) {
	return msqr(x1 - x2) + msqr(y1 - y2);
}

inline LD doit(LD x, LD y, int num, LD l, LD r) {
	LD f1, f2;
	for (int i = 0; i < iter; ++i) {
		LD x1 = l + (r - l) / 3, x2 = r - (r - l) / 3;
		LD y1 = a[num] * sqr(x1) + b[num] * x1 + c[num];
		LD y2 = a[num] * sqr(x2) + b[num] * x2 + c[num];

		f1 = dist(x, y, x1, y1);
		f2 = dist(x, y, x2, y2);
		
		if (f1 < f2) r = x2;
		else l = x1;
	}
	
    return f1;
}

inline void relax(LD& x, LD val) {
	if (val < x) x = val;
}

inline LD dist1(LD x, LD y, int num) {
	LD ans = doit(x, y, num, xl[num], xr[num]);
	LD p = -b[num] / (a[num] + a[num]);
	if (xl[num] <= p && p <= xr[num]) {
		relax(ans, doit(x, y, num, xl[num], p));
        relax(ans, doit(x, y, num, p, xr[num]));
	}
	return ans;
}

inline LD donint(int n1, int n2, LD l, LD r) {
    LD f1, f2;
	for (int i = 0; i < iter; ++i) {
		LD x1 = l + (r - l) / 3, x2 = r - (r - l) / 3;
		LD y1 = a[n1] * sqr(x1) + b[n1] * x1 + c[n1];
		LD y2 = a[n1] * sqr(x2) + b[n1] * x2 + c[n1];
		
		f1 = dist1(x1, y1, n2);
		f2 = dist1(x2, y2, n2);
		
		if (f1 < f2) r = x2;
		else l = x1;
	}
	return f1;
}



inline LD dist2(int n1, int n2) {
	LD ans = 1e100;
	
	LD A = (a[n1] - a[n2]), B = (b[n1] - b[n2]), C = (c[n1] - c[n2]);
	LD D = msqr(B) - 4. * A * C;
	if (D < -1e-5) {
	    relax(ans, donint(n1, n2, xl[n1], (xl[n1] + xr[n1]) / 2.));
		relax(ans, donint(n1, n2, (xl[n1] + xr[n1]) / 2., xr[n1]));
		return ans;
	}
	
	
	if (D < 0) D = 0;
	D = sqrtl(D);
	double p1 = (-B - D) / (A + A);
	double p2 = (-B + D) / (A + A);
	if (p1 > p2) swap(p1, p2);

	if (xl[n1] <= p1 && p1 <= xr[n1]) relax(ans, donint(n1, n2, xl[n1], p1));
	if (xl[n1] <= p2 && p2 <= xr[n1]) relax(ans, donint(n1, n2, p2, xr[n1]));
	if (xl[n1] <= p1 && p2 <= xr[n1]) relax(ans, donint(n1, n2, p1, p2));
	return ans;
}

LD d[N][N];
LD dis[N];
bool used[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen(".out", "w", stdout);

	int n;
	cin >> n;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> xl[i] >> xr[i]; 
	}

	int S = n;
	int T = n + 1;
	for (int i = 0; i < n; ++i) {
		d[i][i] = 0;
		for (int j = i + 1; j < n; ++j) {
			d[i][j] = d[j][i] = sqrtl(dist2(i, j));
		}
		d[S][i] = d[i][S] = sqrtl(dist1(x1, y1, i));
		d[T][i] = d[i][T] = sqrtl(dist1(x2, y2, i));
	}
	d[S][T] = d[T][S] = sqrtl(dist(x1, y1, x2, y2)); 

	n += 2;
	for (int i = 0; i < n; ++i) dis[i] = 1e100;
    dis[S] = 0;
    for (int q = 0; q < n; ++q) {
    	int who = -1;
    	for (int i = 0; i < n; ++i)
    		if (!used[i] && (who == -1 || dis[i] < dis[who])) {
    			who = i;
    		}
		if (who == -1) break;
		
		used[who] = true;
		for (int i = 0; i < n; ++i)
			dis[i] = min(dis[i], dis[who] + d[who][i]);
    }
    cout.precision(15);
    cout << fixed;
    cout << dis[T] << endl;
    
    return 0;
}
