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

const int N = 111111;
const int SH = 150;

char sa[N], sb[N];
int f[N][333];

inline void minimize(int x, int y, int z) {
	if (z < f[x][x - y + SH]) {
		f[x][x - y + SH] = z;
	}
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {    	
    	int a, b, k;
    	cin >> sa >> sb >> a >> b >> k;
    	int n = strlen(sa);
    	int m = strlen(sb);

    	if (a == 0) {
    		cout << 0 << "\n";
    		continue;
    	}

    	memset(f, 63, sizeof(f));
    	f[0][SH] = 0;
		for (int i = 0; i <= n; ++i) {
			for (int j = max(0, i - SH); j <= min(m, i + SH); ++j) {
				int ff = f[i][i - j + SH];
				if (ff > k) continue;
			    if (i + 1 <= n)
			   		minimize(i + 1, j, ff + a);
			    if (j + 1 <= m)
			   		minimize(i, j + 1, ff + a);
			   	if (i + 1 <= n && j + 1 <= m) {
			   		if (sa[i] == sb[j])
				   		minimize(i + 1, j + 1, ff);
				    else
				   		minimize(i + 1, j + 1, ff + b);
			   	}
			}
		}
		int ans = -1;
		if (n - m + SH >= 0 && n - m + SH < 333 && f[n][n - m + SH] <= k)
			ans = f[n][n - m + SH];
		cout << ans << "\n";
	}
    
    return 0;
}
