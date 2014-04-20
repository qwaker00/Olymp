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

const int N = 11;

#define y0 y00

double f[N][1 << N];
bool u[N][1 << N];
double x0[N], y0[N], vx[N], vy[N], V;

inline double sqr(double x) {
	return x * x;
}

double solve(double x0, double y0, double x, double y, double vx, double vy) {
	double dx = x - x0;
	double dy = y - y0;
	double a = sqr(dx) + sqr(dy);
	double b = 2 * (vx * dx + vy * dy);
	double c = sqr(vx) + sqr(vy) - sqr(V);
	double d = sqr(b) - 4. * a * c;
	double sqrtd = sqrt(d);

    double m1 = (-b + sqrtd) / (a + a);
    double m2 = (-b - sqrtd) / (a + a);
	m1 = 1 / m1;
	m2 = 1 / m2;
		

    if (m1 < 0) return m2;
    if (m2 < 0) return m1;
    return min(m1, m2);
}

int main() {
	//freopen("in","r", stdin);
	//freopen(".out","w", stdout);

	int T;
	scanf("%d", &T);
	while (T--) {
		double X0, Y0;
		scanf("%lf%lf%lf", &X0, &Y0,&V);

		int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
        	scanf("%lf%lf%lf%lf", &x0[i], &y0[i], &vx[i], &vy[i]);
        }

        memset(u, 0, sizeof(u));

        for (int i = 0; i < n; ++i) {
        	f[i][1 << i] = solve(X0, Y0, x0[i], y0[i], vx[i], vy[i]);
        	u[i][1 << i] = true;
        }

        int lim = 1 << n;
        for (int msk = 0; msk < lim; ++msk)
        	for (int i = 0; i < n; ++i)
        		if (u[i][msk]) {
        			double mx = x0[i] + vx[i] * f[i][msk];
        			double my = y0[i] + vy[i] * f[i][msk];
					
					for (int j = 0; j < n; ++j)
						if (!(msk & (1 << j))) {
							double res = f[i][msk] + solve(mx, my, x0[j] + vx[j] * f[i][msk], y0[j] + vy[j] * f[i][msk], vx[j], vy[j]);
							int nmsk = msk | (1 << j);
							if (!u[j][nmsk] || f[j][nmsk] > res) {
								u[j][nmsk] = true;
								f[j][nmsk] = res;
							}
						}
        		}
		
		double ans = f[0][lim - 1];
		for (int i = 0; i < n; ++i)
			ans = min(ans, f[i][lim - 1]);
		printf("%.15lf\n", ans);
	}

	return 0;
}