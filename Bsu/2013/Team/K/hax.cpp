#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 33;

vector<uint> g[N];

uint a[N][8];
uint need[8], cur[8];

int main() {
    freopen("wormholes.in", "r", stdin);
    freopen("wormholes.out", "w", stdout);
    
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(i);
		g[b].push_back(i);
		
		need[i >> 5] |= (1 << (i & 31));
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			a[i][ g[i][j] >> 5 ]  |= (1 << (g[i][j] & 31));
		}
	}

	int ans = n;
	int lim = 1 << n;
	for (int msk = 0; msk < lim; ++msk) {
		int cnt = 0;
		memset(cur, 0, sizeof(cur));
		for (int i = 0; i < n; ++i) 
			if (msk & (1 << i)) {
				++cnt;
				for (int j = 0; j < 8; ++j) cur[j] |= a[i][j];
			}

	 	if (cnt >= ans) continue;
	 	bool cool = true;
	 	for (int i = 0; i < 8; ++i) 
	 		if (cur[i] != need[i]) { 
	 			cool = false;
	 			break;
	 		}
	 	if (!cool) continue;
	    ans = cnt;
	}

    cout << ans << endl;

    cerr << clock() << endl;
    
    return 0;
}
