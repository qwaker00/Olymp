#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <ctime>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int N = 100111;
const int iter = 50;
int n, r;
int x[N], y[N];
pair<int, int> w[N];

double ans = 0;
double minx = 1e10, maxx = -1e10, miny = 1e10, maxy = -1e10;

inline double sq(double x1, double y1, double x2, double y2) {
	double res = fabs(x1 - x2) * fabs(y1 - y2);
	ans = max(ans, res); 
	return res;
}

double trih(double x, double y, double x1, double y1, double L, double R) {
	//return sq(x1, y1, x + r * cos(L), y + r * sin(L));
//	return 0;
	for (int i = 0; i < iter; ++i) {
		double p1 = L + (R - L) / 3, p2 = R - (R - L) / 3.;

		double x2 = cos(p1) * r + x;
		double y2 = sin(p1) * r + y;
		double x3 = cos(p2) * r + x;
		double y3 = sin(p2) * r + y;

		if (sq(x1, y1, x2, y2) > sq(x1, y1, x3, y3)) {
			R = p2;
		} else {
			L = p1;
		}
	}

	return sq(x1, y1, x + r * cos(L), y + r * sin(L));
}

int main() {
	freopen("approximate.in", "r", stdin);
	freopen("approximate.out", "w", stdout);

	scanf("%d%d", &n, &r);
	while (n) {

	minx = 1e10, maxx = -1e10, miny = 1e10, maxy = -1e10;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);

		minx = min(minx, double(x[i]));
		miny = min(miny, double(y[i]));
		maxx = max(maxx, double(x[i]));
		maxy = max(maxy, double(y[i]));
	}
	ans = (maxx - minx) * (maxy - miny);
    
    set<int> q;

    for (int i = 0; i < n; ++i) {
    	w[i].first = x[i];
    	w[i].second = i;
    }
    sort(w, w + n);
	for (int i = 0; i < min(n, 2); ++i) {
		q.insert(w[i].second);
	}
	for (int i = max(0, n - 2); i < n; ++i) {
		q.insert(w[i].second);
	}

	for (int i = 0; i < n; ++i) {
    	w[i].first = y[i];
    	w[i].second = i;
    }
    sort(w, w + n);
	for (int i = 0; i < min(n, 2); ++i) {
		q.insert(w[i].second);
	}
	for (int i = max(0, n - 2); i < n; ++i) {
		q.insert(w[i].second);
	}

	vector<int> a(q.begin(), q.end());
	n = a.size();
    for (int left = 0; left < n; ++left)
    	for (int right = 0; right < n; ++right)
    		if (left != right && x[ a[right] ] >= x[ a[left] ])
    			for (int down = 0; down < n; ++down)
    				if (down != left && down != right)
    					for (int up = 0; up < n; ++up)
    						if (up != down && up != left && up != right && y[ a[up] ] >= y[ a[down] ]) {
    							double x1 = x[ a[left] ] - r;
    							double x2 = x[ a[right] ] + r;
    							double y1 = y[ a[down] ] - r;
    							double y2 = y[ a[up] ] + r;
								
								ans = max(ans, (x2 - x1) * (y2 - y1));
    						}
        
	for (int I = 0; I < n; ++I)
		for (int J = I + 1; J < n; ++J) {
			double l1, r1, l2, r2;
			int i = a[I], j = a[J];

			
				if (x[i] > x[j]) {
					if (y[i] > y[j]) {
						l1 = 0;
						r1 = PI / 2.;
						l2 = PI;
						r2 = 3. * PI / 2.;
					} else {
						l1 = 3. * PI / 2.;
						r1 = PI + PI;
						l2 = PI / 2.;
						r2 = PI;
					}
				} else {
				    if (y[i] > y[j]) {
						l2 = 3. * PI / 2.;
						r2 = PI + PI;
						l1 = PI / 2.;
						r1 = PI;
					} else {
					    l2 = 0;
						r2 = PI / 2.;
						l1 = PI;
						r1 = 3. * PI / 2.;
					}
				}

				for (int i = 0; i < iter; ++i) {
					double p1 = l1 + (r1 - l1) / 3., p2 = r1 - (r1 - l1) / 3.;

					double res1 = trih(x[j], y[j], x[i] + cos(p1) * r, y[i] + sin(p1) * r, l2, r2);
					double res2 = trih(x[j], y[j], x[i] + cos(p2) * r, y[i] + sin(p2) * r, l2, r2);
					if (res1 > res2) {
						r1 = p2;
					} else {
						l1 = p1;
					}
				}
		}
        

	for (int I = 0; I < n; ++I)
		for (int J = 0; J < n; ++J)
			if (I != J)
				for (int K = 0; K < n; ++K)
					if (K != I && K != J) {
						int i = a[I], j = a[J], k = a[K];

						trih(x[k], y[k], x[i] + r, y[j] + r, PI, 3. * PI / 2);
						trih(x[k], y[k], x[i] + r, y[j] - r, PI / 2,  PI);
						trih(x[k], y[k], x[i] - r, y[j] + r, 3. * PI / 2, PI + PI);
						trih(x[k], y[k], x[i] - r, y[j] - r, 0, PI / 2);
					}	

	printf("%.15lf\n", ans);

	//cerr << "Done" << II++ << endl;
	scanf("%d%d", &n, &r);
	}


	return 0;
}
