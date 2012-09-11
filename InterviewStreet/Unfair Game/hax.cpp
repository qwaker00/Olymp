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

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int ed[66666];
int f[33][33333];

void Min(int& a, int b) {
	if (b < a) a = b;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	ed[0] = 0;
	for (int i = 1; i < 65536; ++i) ed[i] = ed[i & (i - 1)] + 1;

	int T;
	cin >> T;
	while (T--) {
		int n, a[33][33], x, nn, msa[33];
		memset(msa, 0, sizeof(msa));

		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			for (int j = 0; j < 30; j++) {
				msa[j] |= (x & 1) << i;
				a[i][j] = x & 1;
				x >>= 1;
			}
		}

		nn =  1 << n;
		memset(f, 63, sizeof(f));
		f[0][0] = 0;
		for (int i = 0; i < 30; ++i) {
			int msk = msa[i];
			for (int j = 0; j < nn; ++j) if (f[i][j] < 1e9) {
				if ( (ed[j ^ msk] & 1) == 0 ) {
					Min(f[i + 1][j & msk], f[i][j]);
				} else {
					for (int k = 0; k < n; ++k)	{
						if ((j & (1 << k)) && (msk & (1 << k))) {
							//
						} else
						if ((j & (1 << k)) || (msk & (1 << k))) {
							Min(f[i + 1][(j & msk) | (1 << k)], f[i][j] + (1 << i));
						} else {
							Min(f[i + 1][j & msk], f[i][j] + (1 << i));
						}
					}
				}
			}
		}
		cout << f[30][0] << endl;
	}

	return 0;
}
