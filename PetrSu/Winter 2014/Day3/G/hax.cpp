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

const int N = 1000111;

bool f[N][2][2];
int from[N][2][2];
char a[N][2];
char ans[N];

int main() {
	//freopen("in","r", stdin);
	//freopen(".out","w", stdout);

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%c %c\n", &a[i][0], &a[i][1]);
		}

		for (int i = 0; i < n; ++i) memset(f[i], 0, sizeof(f[i]));

		f[0][0][0] = true;
		f[0][1][1] = true;

		for (int i = 0; i + 1 < n; ++i)
			for (int c0 = 0; c0 < 2; ++c0) 
				for (int c = 0; c < 2; ++c) {
					if (!f[i][c][c0]) continue;

					int color = a[i][c];
					for (int nc = 0; nc < 2; ++nc)
						if (a[i + 1][nc] != color) {
							f[i + 1][nc][c0] = true;
							from[i + 1][nc][c0] = c;
						}
				}
		
		int bc = -1, bc0 = -1;
		for (int c = 0; c < 2; ++c)
			for (int c2 = 0; c2 < 2; ++c2)
				if (f[n - 1][c][c2] && a[0][c2] != a[n - 1][c]) {
					bc = c;
					bc0 = c2;
				}
		if (bc == -1) {
			puts("-");
			continue;
		}

		int k = 0;
   		for (int i = n - 1; i >= 0; --i) {
   			ans[k++] = a[i][bc];
   			bc = from[i][bc][bc0];
   		}
   		reverse(ans, ans + k);
   		ans[k] = 0;
   		puts(ans);
	}

	return 0;
}