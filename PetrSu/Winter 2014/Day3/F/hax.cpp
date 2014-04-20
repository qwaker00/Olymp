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

bool p[8][8], at[8][8], at_t[8][8];
int dx[] = {-2, -2, -1, 1, 2,  2,  1, -1};
int dy[] = {-1, 1,   2, 2, 1, -1, -2, -2};

int main() {
//	freopen(".in","r", stdin);
//	freopen(".out","w", stdout);

	int T;
	scanf("%d", &T);
	while (T--)	{
		memset(p, 0, sizeof(p));

		int n;
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i) {
			char pc;
			int pr;
			scanf("%c%d ", &pc, &pr);
			p[pr - 1][pc - 'a'] = 1;
		}

		ULL ans = 0;
		int moved = 0;
		memset(at, 0, sizeof(at));
		while (moved < n) {
			int last = 0;
			int moved_t = moved;
			memcpy(at_t, at, sizeof(at));
			for (int j = 0; j < 64; ++j) {
				for (int k = 0; k < 8; ++k) {
					int x = (j >> 3) + dx[k];
					int y = (j & 7) + dy[k];
					if (x < 0 || y < 0 || x >= 8 || y >= 8 || at_t[x][y]) continue;
					if (p[x][y]) {
						++moved_t;
						at_t[x][y] = 1;
						if (moved_t == n) break;
					}
				}
				if (moved_t == n) {
					last = j;
					break;
				}
			}

			ans += (1ull << last);
			for (int k = 0; k < 8; ++k) {
				int x = (last >> 3) + dx[k];
				int y = (last & 7) + dy[k];
				if (x < 0 || y < 0 || x >= 8 || y >= 8 || at[x][y]) continue;
				if (p[x][y]) {
					++moved;
					at[x][y] = 1;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}