#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, ed[66666];
char s[1555][1555];
unsigned g[1555][55], gr[1555][55];

int main() {
	freopen("triatrip.in", "r", stdin);
	freopen("triatrip.out", "w", stdout);

	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
		for (int j = 0; j < n; ++j) if (s[i][j] == '+') {
			g[i][j >> 5] |= (1u << (j & 31));
			gr[j][i >> 5] |= (1u << (i & 31));
		}
	}

	for (int i = 1; i < (1 << 16); ++i) {
		ed[i] = ed[i & (i - 1)] + 1;
	}

	long long ans = 0;
	int nn = ((n + 31) >> 5);
	for (int i= 0;i < n; ++i) {
		for (int j = 0; j < n; ++j) if (s[i][j] == '+') {
			for (int k = 0; k < nn; ++k) {
				unsigned x = g[j][k] & gr[i][k];
				ans += ed[x >> 16] + ed[x & ((1 << 16) - 1)];
			}
		}
	}
	cout << ans / 3 << endl;

	return 0;
}
