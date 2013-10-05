#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <assert.h>
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

const int N = 133;
const int M = 65555;
char w[N][M];
int l[N];

int f[2][16][M];
int n, m;

int cnt[M];

void relax(int& x, int y) {
	if (x < y) x = y;
}

int main() {
	//freopen("in", "r", stdin);

	int n, m;	
	
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < 16; ++j)
			if (i & (1 << j)) ++cnt[i];

	scanf("%d%d\n", &n, &m);
	memset(f, 128 + 63, sizeof(f));

	for (int i = 0; i < n; ++i) {
		gets(w[i]);
		l[i] = strlen(w[i]);
	}

	int lim = 1 << m;
	for (int msk = 0; msk < lim; ++msk) {
		if (cnt[msk] == l[0]) {
			int cans = 0;
			int pos = 0;
			for (int i = 0; i < m; ++i) {
				if (msk & (1 << i)) {
					++pos;
					if (pos > 1 && (msk & (1 << (i - 1))) && w[0][pos - 1] == w[0][pos - 2]) {
						++cans;
					}
				}
			} 
			f[1][0][msk] = cans;
		}
	}

	for (int I = 1; I < n; ++I) {
		int i = I & 1;
		memset(f[1 - i], 128 + 63, sizeof(f[1 - i]));

		for (int j = 0; j < m; ++j)  {
			int ni = i, nj = j + 1;
			if (nj == m) {
				ni = 1 - i;
				nj = 0; 
			}

			for (int msk = 0; msk < lim; ++msk) {
				int pos = j == 0 ? 0 : cnt[msk & ((1 << j) - 1)];
				int rpos = cnt[msk] - pos;
				if (pos > l[I]) continue;
				if (rpos > l[I - 1]) continue;

				int nmsk = (msk & (lim - 1 - (1 << j)));
				if (i == ni || l[I] == cnt[nmsk]) {
					relax(f[ni][nj][nmsk], f[i][j][msk]);
				}

				int add = 0;
				if (pos < l[I]) {
					if (pos > 0 && (msk & (1 << (j - 1))) && w[I][pos - 1] == w[I][pos]) ++add;
					if ((msk & (1 << j)) && w[I][pos] == w[I - 1][ l[I - 1] - rpos ]) ++add;
				}
				nmsk = msk | (1 << j);
				if (i == ni || l[I] == cnt[nmsk]) {
					relax(f[ni][nj][nmsk], f[i][j][msk] + add);
				}
			}
		}
	}

	int ans = 0;
	int cx = n & 1;
	for (int msk = 0; msk < lim; ++msk)
		if (cnt[msk] == l[n - 1]) {
			ans = max(ans, f[cx][0][msk]);
		}

	cout << ans * 2 << endl;

	return 0;
}
