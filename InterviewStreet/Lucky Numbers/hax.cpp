#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int pr[3333], prn[3333], pn = 0;
LL f[22][444][3333];
int an;
int a[20];

LL Calc(LL R) {
	if (R == 1000000000000000000ll) --R;
	if (R == 0) return 0;

	an = 0;
	while (R > 0) {
		a[an++] = R % 10;
		R /= 10;
	}

	LL ans = 0;
	int ad = 0, ads = 0;
	for (int i = an - 1; i >= 0; i--) {
		for (int d = 0; d < a[i]; d++) ans += f[i][ad + d][ads + d * d];
		ad += a[i];
		ads += a[i] * a[i];
	}
	ans += f[0][ad][ads];

	return ans;
}

//int s[11111111], ss[11111111];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	/*
	for (int i = 2; i < 2000; i++) {
		pr[i] = true;
		for (int j = 2; j < i; j++) if (i % j == 0) {
			pr[i] = false;
			break;
		}
	}
	int ans = 0;
	s[0] = 0;
	ss[0] = 0;
	for (int i = 1; i <= 100000; i++) {
		s[i] = s[i / 10] + i % 10;
		ss[i] = ss[i / 10] + (i % 10) * (i % 10);
		if (pr[s[i]] && pr[ss[i]]) {
			cout << i << endl;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
	*/

	for (int i = 2; i < 3000; i++) {
		pr[i] = true;
		for (int j = 0; j < pn; j++) if (i % prn[j] == 0) {
			pr[i] = false;
			break;
		}
		if (pr[i]) prn[pn++] = i;
	}

	for (int i = 0; prn[i] < 444; i++)
		for (int j = 0; j < pn ; j++)
			f[0][prn[i]][prn[j]] = 1;

	int mass = 18 * 10;
	int masss = 18 * 90;
	for (int l = 1; l < 18; ++l) {
		for (int d = 0; d < 10; d++)
			for (int i = 0; i <= mass - d; ++i)
				for (int j = 0; j <= masss - d * d; ++j) {
//					if (f[l - 1][i + d][j + d * d]) cout << d << " " << l << " " << i << " " << j << " + " << f[l - 1][i + d][j + d * d] << endl;
					f[l][i][j] += f[l - 1][i + d][j + d * d];
				}
	}

	int T;
	LL A, B;

	cin >> T;
	while (T--) {
		cin >> A >> B;
		cout << Calc(B) - Calc(A - 1) << endl;
	}

	return 0;
}
