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
vector<int> g[N];
vector<int> w[N + N];

bool used[N];

int d[N];
int dist[N];

int main() {
	//freopen("in", "r", stdin);
	
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	int maxd = 0;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);

		--x; --y;
		d[x]++; d[y]++;
		g[x].push_back(y);
		g[y].push_back(x);

		maxd = max(maxd, d[x]);
		maxd = max(maxd, d[y]);
	}

	for (int i = 0; i < n; ++i)
		w[ d[i] ].push_back(i);

	vector<int> ans;
	memset(dist, 63, sizeof(dist));

	for (int j = maxd; j >= 0; --j) {
		for (int a = 0; a < w[j].size(); ++a) {
			int x = w[j][a];

			if (used[x]) {
				continue;	
			}
			ans.push_back(x + 1);
			queue<int> q;
			q.push(x);
			dist[x] = 0;
			used[x] = true;

			while (!q.empty()) {
				x = q.front(); q.pop();
				used[x] = true;
				if (dist[x] == 2) continue;
				for (int i = 0; i < g[x].size(); ++i) 
					if (dist[ g[x][i] ] > dist[x] + 1) {
						dist[ g[x][i] ] = dist[x] + 1;
						q.push(g[x][i]);
						used[ g[x][i] ] = true;
					}
			}
		}
	}

	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
	puts("");
	
	return 0;
}
