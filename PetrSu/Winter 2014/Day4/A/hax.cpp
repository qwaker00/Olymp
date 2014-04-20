#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <memory.h>

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
using namespace std;

#define N 50005
#define ALF (122 - 48 + 3)

char s[6];
unsigned lm[N / 32 + 1][ALF][5];
int an;
pair<int, int> ans[111111];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(s);
		for (int j = 0; j < 5; ++j) s[j] -= 48;
		for (int j = 0; j < (N / 32) && an < 100000; ++j) {
			unsigned msk = lm[j][s[0]][0] & lm[j][s[1]][1] & lm[j][s[2]][2] & lm[j][s[3]][3] & lm[j][s[4]][4];
			if (msk) {
				for (int k = 0; k < 32; ++k) if ((1u << k) & msk) {
					ans[an++] = make_pair((j << 5) + k, i);
				}
			}
		}
		if (an == 100000) break;
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < ALF; ++k) {
				if (k != s[j]) {
					lm[i >> 5][k][j] |= (1u << (i & 31));
				}
			}
		}
	}
	while (an > 100000) --an;

	printf("%d\n", an);
	for (int i = 0; i < an; ++i) {
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
	
//	cerr << "Time: " << clock() << endl;
	return 0;
}
