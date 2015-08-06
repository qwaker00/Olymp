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

int b[22];
struct Tp {
	int x, y;
} a[22];
int k, n, c[222], hx[22*111], hy[22*111], hxn = 0, hyn = 0;
vector< pair<int, int> > v[22];

const int INF = 1e9;

int venger(int n, int m, vector< vector<int> >& a) {
	vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
	for (int i=1; i<=n; ++i) {
		p[0] = i;
		int j0 = 0;
		vector<int> minv (m+1, INF);
		vector<char> used (m+1, false);
		do {
			used[j0] = true;
			int i0 = p[j0],  delta = INF,  j1;
			for (int j=1; j<=m; ++j)
				if (!used[j]) {
					int cur = a[i0][j]-u[i0]-v[j];
					if (cur < minv[j])
						minv[j] = cur,  way[j] = j0;
					if (minv[j] < delta)
						delta = minv[j],  j1 = j;
				}
			for (int j=0; j<=m; ++j)
				if (used[j])
					u[p[j]] += delta,  v[j] -= delta;
				else
					minv[j] -= delta;
			j0 = j1;
		} while (p[j0] != 0);
		do {
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0);
	}
	return -v[0];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    set< pair<int, int> > was;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y;
		was.insert(make_pair(a[i].x, a[i].y));
		for (int it = -30; it <= 30; ++it) {
			if (a[i].x + it >= 0 && a[i].x + it <= 5000)
				hx[hxn++] = a[i].x + it;
			if (a[i].y + it >= 0 && a[i].y + it <= 5000)
				hy[hyn++] = a[i].y + it;
		}
	}
	sort(hx, hx + hxn);
	hxn = unique(hx, hx + hxn) - hx;
	sort(hy, hy + hyn);
	hyn = unique(hy, hy + hyn) - hy;
//	cerr << "here " << clock() << endl;

	for (int i = 0; i < k; ++i) cin >> c[i];

	for (int i = 0; i < hxn; ++i) {
		for (int j = 0; j < hyn; ++j) {
			if (was.count(make_pair(hx[i], hy[j]))) continue;

			for (int t = 0; t < n; ++t) b[t] = abs(hx[i] - a[t].x) + abs(hy[j] - a[t].y);
			sort(b, b + n);
			int s = 0;
			for (int t = 0; t < n; ++t) {
				s += b[t];
				v[t+1].push_back(make_pair(s, i*hyn+j));
			}
		}
	}
//	cerr << "here " << clock() << endl;

	map<int, int> id;
	int idn = 0;

	for (int i = 1; i <= n; ++i) {
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < k && j < v[i].size(); ++j) {
			int x = v[i][j].second;
			if (!id.count(x))
				id[x] = idn++;
		}			
	}
//	cerr << "here " << clock() << endl;

	vector< vector<int> > a(k + 1, vector<int>(idn + 1, INF));
	for (int i = 0; i < k; ++i) {
		int cc = c[i];
		for (int j = 0; j < v[cc].size() && j < k; ++j) {
			int x = i + 1;
			int y = id[v[cc][j].second] + 1;
			a[x][y] = v[cc][j].first;

//			cerr << "table: " << i << ", people: " << cc << ", position: " << hx[(v[cc][j].second / hyn)] << " " << hy[(v[cc][j].second % hyn)] << ", cost: " << v[cc][j].first << endl;
		}
	}
//	cerr << "here " << clock() << endl;

	int t = venger(k, idn, a);
	cout << t << endl;
//	cerr << "here " << clock() << endl;
    
    return 0;
}