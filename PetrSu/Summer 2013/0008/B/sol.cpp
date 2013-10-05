#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int N = 5555;
double f[N], g[N];
int sa[N], sb[N], sc[N], sd[N];

double calc(double a, double b, double c, double d) {
	if (a + c < 1e-5) {
		if (b > d) return 0;
		return 1;
	}
	double res = (d - b + c) / (a + c);
	if (res < 0) return 0;
	if (res > 1) return 1;
	return res;
}

int main() {
	freopen("braess.in", "r", stdin);
	freopen("braess.out", "w", stdout);	
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", sa + i + 1, sb + i + 1, sc + i + 1, sd + i + 1);
		sa[i + 1] += sa[i];
		sb[i + 1] += sb[i];
		sc[i + 1] += sc[i];
		sd[i + 1] += sd[i];
	}

	f[1] = g[1] = 0;
	++n;
	for (int i = 2; i <= n; ++i) {
		f[i] = -1e18;
		g[i] = 1e18;
		for (int j = 1; j < i; ++j) {
			int A = sa[i] - sa[j], B = sb[i] - sb[j], C = sc[i] - sc[j], D = sd[i] - sd[j];
			double k1 = calc(A, B, C, D);
			double k2 = 1. - k1;
			
			double t1 = A * k1 + B;
			double t2 = C * k2 + D;
			
			f[i] = max(f[i], f[j] + min(t1, t2));
			g[i] = min(g[i], g[j] + min(t1, t2));
		}
	}
	
	cout.precision(15);
	cout << fixed;
	{
		int A = sa[n], B = sb[n], C = sc[n], D = sd[n];
		double k1 = calc(A, B, C, D);
		double k2 = 1. - k1;
			
		double t1 = A * k1 + B;
		double t2 = C * k2 + D;

		cout << min(t1, t2) << endl;
	}
	{
		double ans = 0;
		for (int i = 2; i <= n; ++i) {
			int A = sa[i] - sa[i - 1], B = sb[i] - sb[i - 1], C = sc[i] - sc[i - 1], D = sd[i] - sd[i - 1];
			double k1 = calc(A, B, C, D);
			double k2 = 1. - k1;
			
			double t1 = A * k1 + B;
			double t2 = C * k2 + D;

			ans += min(t1, t2);
		}

		cout << ans << endl;
	}

	
	cout << g[n] << endl;
	cout << f[n] << endl;

	return 0;
}
