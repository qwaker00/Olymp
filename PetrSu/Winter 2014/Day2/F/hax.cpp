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

const int N = 2222;

int n;
int a[N];
int s[N];
ll f[N][N];
bool alive[N];

ll point = -2000000;

struct cell {
	ll first, second, value;

	cell(ll a, ll b) {
		first = a;
		second = b;
		value = a * point + b;
	}	

	bool operator<(const cell& A) const {
		return value < A.value;
	}
};

int l[N], r[N];

priority_queue< pair<ld, pair<int, int> > > q;
vector< cell > g;
ld cur;

void doit(int x, int y) {
	if (g[x].first == g[y].first) return;
	ld t = ld(g[x].second - g[y].second) / (g[y].first - g[x].first);
	if (t >= cur) q.push(make_pair(-t, make_pair(x, y)));	
}

int main() {
	//freopen("in","r", stdin);
	//freopen(".out","w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		s[i] = s[i - 1] + a[i];
	}

	memset(f, 63 + 128, sizeof(f));
	for (int i = 1; i <= n; ++i) f[1][i] = 0;

	for (int i = 2; i <= n; ++i) {
		memset(alive, true, sizeof(alive));
		g.clear();
		while (!q.empty()) q.pop();
		cur = point;
		for (int k = 1; k < i; ++k) {
			g.push_back(cell(ll(s[i - 1] - s[k - 1]), f[k][i - 1]));
		}
		sort(g.begin(), g.end());

		int m = g.size();
		for (int j = 0; j < m; ++j) {
			l[j] = j - 1;
			r[j] = j + 1;
		}
		
		for (int j = 1; j < m; ++j) {
			doit(j, l[j]);
		}
		
		vector< pair<ld, int> > cans;
		
		int best = m - 1;
		while (q.size()) {
			ld t = -q.top().first;
			int x = q.top().second.first;
			int y = q.top().second.second;
			q.pop();

			if (t < cur || !alive[x] || !alive[y]) continue;

			cans.push_back(make_pair(t, best));

			if (g[x].first < g[y].first) swap(x, y);
			int wasl = l[x];
			int wasr = r[x];
			
			if (l[y] != -1) r[ l[y] ] = r[y];
			if (r[y] != m) l[ r[y] ] = l[y];
			else best = l[y];
			alive[y] = false;

			if (l[x] != wasl && l[x] != -1) {
				doit(x, l[x]);
			}
			if (r[x] != wasr && r[x] != m) {
				doit(x, r[x]);
			}
		}
		ld t = max(ld(-point), cur + 100);
		cans.push_back(make_pair(t, best));

		ll S = 0;
		for (int j = i; j <= n; ++j) {
			S += a[j];

		    int pos = lower_bound(cans.begin(), cans.end(), make_pair(ld(S), -1000)) - cans.begin();
			int delta = 2;
			for (int k = max(0, pos - delta); k < min(int(cans.size()), pos + delta); ++k) {
				int who = cans[k].second;
				f[i][j] = max(f[i][j], S * g[who].first + g[who].second);
			}
		}

	}   
	    /*
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j) cerr << i << " " << j << ": " << f[i][j] << endl;  
		  */
	ll ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, f[i][n]);
	cout << ans << endl;
	//cerr << clock() << endl;

	return 0;
}