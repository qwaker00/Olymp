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


const int N = 1000111;
int a[N];

int f[N][11];
int n;

void relax(int& x, int y) {
	if (x > y) x = y;
}

int main() {
	//freopen("in", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	memset(f, 63, sizeof(f));
	f[0][5 + a[0]] = 0;
	for (int i = 0; i + 1 < n; ++i) {
		for (int j = 0; j <= 10; ++j) {
			int w = j - 5;

			if (w == 0) {
				if (a[i + 1] >= 0) {
					relax(f[i + 1][ a[i + 1] + 5 ], f[i][j]);
				}
			} else {
				int cnt = 0;
				int pos = 5 + a[i + 1];
				while (pos >= 0 && pos <= 10) {
					if (pos >= j) {
						relax(f[i + 1][pos], f[i][j] + cnt);
					}
					pos += w;
					++cnt;
				}
			}
		}
	}

    /*
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= 10; ++j)
			if (f[i][j] < 1000)
			printf("%d %d: %d\n", i, j - 5, f[i][j]);
            */

	int ans = f[n - 1][0];
	for (int i = 0; i <= 10; ++i) {
		ans = min(ans, f[n - 1][i]);
	}

	if (ans > 1e9) {
		puts("BRAK");
		return 0;
	}

	cout << ans << endl;

	
	return 0;
}
