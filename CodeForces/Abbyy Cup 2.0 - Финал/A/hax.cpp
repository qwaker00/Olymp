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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, k[5555], x, y, m, gn[5555], newa, olda;
pair<int, int> poolX[222222], t[222222];
int poolN, poolNext[222222], poolStart[222222];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
//	printf("%d\n", sizeof(poolX) + sizeof(t) + sizeof(poolN));

	cin >> n;
	int ans = 0;
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		total += k[i];
		cin >> olda;
		cin >> x >> y >> m;
		gn[i] = 0;
		for (int j = 1; j < k[i]; j++) {
			int newa = (LL(olda) * x + y) % m;

			if (poolN < 222000) {
				poolX[++poolN] = make_pair(olda, i + 1);
				poolNext[poolN] = poolStart[gn[i]];
				poolStart[gn[i]] = poolN;
			}

			if (newa < olda) ++gn[i];
			olda = newa;
		}
		if (k[i]) {
			if (poolN < 222000) {
				poolX[++poolN] = make_pair(olda, i + 1);
				poolNext[poolN] = poolStart[gn[i]];
				poolStart[gn[i]] = poolN;
			}
			++gn[i];
		}
		ans = max(ans, gn[i] - 1);
	}
	cout << ans << endl;

	if (total <= 200000) {
		for (int i = 0; i <= ans; i++) {
			int tn = 0;
			for (int j = poolStart[i]; j; j = poolNext[j])
				t[tn++] = poolX[j];

			sort(t, t + tn);
			for (int j = 0; j < tn; j++) cout << t[j].first << " " << t[j].second << endl;
		}
	}
	
	return 0;
}
