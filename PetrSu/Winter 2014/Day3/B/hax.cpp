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

#define P 5
#define N 1111111
#define M 1000000007

char ID[256];
char s1[N], s2[N];
LL h1[N], h2[N], Pl[N];
int n;

inline LL mod(LL x, LL y) {
	if (x < 0) x = y - ((-x) % y);
	return x % y;
}

inline bool check_seg(int l, int r) {
	LL H1 = mod(h1[r] - h1[l - 1] * Pl[r - l + 1], M);
	LL H2 = mod(h2[l] - h2[r + 1] * Pl[r - l + 1], M);
	return (H1 == H2);
}

int main() {
//	freopen(".in","r", stdin);
//	freopen(".out","w", stdout);

	ID['A'] = 1;
	ID['C'] = 2;
	ID['G'] = 3;
	ID['T'] = 4;

	Pl[0] = 1;
	for (int i = 1; i < N; ++i) {
		Pl[i] = (Pl[i - 1] * P) % M;
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d\n", &n);
		gets(s1 + 1);
		gets(s2 + 1);
		for (int i = 1; i <= n; ++i) s1[i] = ID[s1[i]];
		for (int i = 1; i <= n; ++i) s2[i] = ID[s2[i]];

		h1[0] = 0;
		for (int i = 1; i <= n; ++i) h1[i] = (h1[i - 1] * P + s1[i]) % M;
		h2[n + 1] = 0;
		for (int i = n; i >= 1; --i) h2[i] = (h2[i + 1] * P + s2[i]) % M;

		int ans1 = 0;
		for (int i = 1; i <= n; ++i) {
			while (i - ans1 > 0 && i + ans1 <= n && check_seg(i - ans1, i + ans1))
				++ans1;
		}
		int ans2 = 0;
		for (int i = 2; i <= n; ++i) {
			while (i - ans2 - 1 > 0 && i + ans2 <= n && check_seg(i - ans2 - 1, i + ans2))
				++ans2;
		}

		cout << max(ans1 * 2 - 1, max(ans2 * 2, 0)) << endl;
//		cerr << clock() << endl;
	}

	return 0;
}