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

const int N = 200222;

int n, m;
vector<int> g[N];
int A[N], B[N];
bool used[N];
int color[N];

void dfs(int x, int c) {
	color[x] = c;
	used[x] = true;

	for (int i = 0; i < g[x].size(); ++i)
		if (!used[ g[x][i] ]) {
			dfs(g[x][i], 3 - c);
		}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", A+i, B+i);
		g[ A[i] ].push_back(B[i]);
		g[ B[i] ].push_back(A[i]);
	}

	for (int i = 1; i <= n; ++i)
		if (!used[i]) dfs(i, 1);

	bool cool = true;
	for (int i = 0; i < m; ++i) {
		if (color[ A[i] ] == color[ B[i] ] ) {
			cool = false;
			break;
		}
	}

	if (cool) {
		puts("DA");
		for (int i = 1; i <= n; ++i) printf("%d ", color[i]);
		cout << endl;
		return 0;
	}

	puts("NET");
	
	return 0;
}
