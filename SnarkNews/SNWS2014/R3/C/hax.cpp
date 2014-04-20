#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

bool gr[1111111];
LL block[111], user[111];
char g[22][22];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);
	while (T--) {
		int n, a, b, f;
		scanf("%d%d%d%d", &n, &a, &b, &f);
		for (int i = 0; i < b; ++i) {
			int k;
			scanf("%d", &k);
			block[i] = 0;
			for (int j = 0; j < k; ++j) {
				int x;
				scanf("%d", &x);

				block[i] |= (1ll << (x - 1));
			}
		}
		for (int i = 0; i < n; ++i) {
			int k;
			scanf("%d", &k);
			user[i] = 0;			
			for (int j = 0; j < k; ++j) {
				int x;
				scanf("%d", &x);

				user[i] |= (1ll << (x - 1));
			}
		}

		memset(g, 0, sizeof(g));
		for (int i = 0; i < f; ++i) {			
			int x, y;
			scanf("%d%d", &x, &y);
			g[x][y] = g[y][x] = 1;
		}

		int ans = 0;
		gr[0] = 1;
		for (int i = 1; i < (1 << n); ++i) {
			bool bad = false;
			LL msk = 0;
			for (int j = 0; j < n; ++j) if (i & (1 << j)) {
				if (!gr[i ^ (1 << j)]) {
					bad = true;
				} else {
					msk = user[j];
					for (int jj = j + 1; jj < n; ++jj)
						if ((i & (1 << jj))) {
							if (!g[j][jj]) {
								bad = true;
								break;
							}
							msk |= user[jj];
						}
				}
				break;
			}
			if (bad) {
				gr[i] = 0;
				continue;
			}
//			cerr << i << endl;
			gr[i] = 1;
			for (int j = 0; j < b; ++j)
				if ((msk | block[j]) == msk) {
					++ans;
//					cerr << i << endl;
					break;
				}
		}
		cout << ans << endl;
	}
	
    return 0;
}
