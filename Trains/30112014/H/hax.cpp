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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


struct rect {
	int p1[3];
	int p2[3];

	rect() {}

	rect(int x1, int y1, int z1,
	     int x2, int y2, int z2)
	 {
	 	p1[0] = x1;
	 	p1[1] = y1;
	 	p1[2] = z1;

	 	p2[0] = x2;
	 	p2[1] = y2;
	 	p2[2] = z2;
	 }
} rects[2111111];

struct treq {
	int t, x, y, z;
	treq(int t, int x, int y, int z)
		: t(t), x(x), y(y), z(z)
		{}

	bool operator<(const treq& b) const {
		return x < b.x || x == b.x && t < b.t;
	}
};

void add_sum(vector<int>& S, int x, int y) {
	++x;
	while (x < S.size()) {
		S[x] += y;
		x = (x | (x - 1)) + 1;
	}
}

int get_sum(vector<int>& S, int x) {
	++x;
	int ans = 0;
	while (x > 0) {
		ans += S[x];
		x &= x - 1;
	}
	return ans;
}

bool solve(vector<rect>& a, vector<rect>& b, int axis, int hs) {
	if (a.size() == 0 || b.size() == 0) return true;

	vector<treq> req;
	int ax1 = 0;
	int ax2 = 0;
	if (ax1 == axis) ++ax1;
	while (ax2 <= ax1 || ax2 == axis) ++ax2;

	int minx = 2e9;
	int maxx = -2e9;
	for (int i = 0; i < a.size(); ++i) {
		minx = min(minx, a[i].p1[axis]);
		maxx = max(maxx, a[i].p2[axis]);
		req.push_back(treq(1,  a[i].p1[ax1], a[i].p1[ax2], a[i].p2[ax2]));
		req.push_back(treq(-1, a[i].p2[ax1] + 1, a[i].p1[ax2], a[i].p2[ax2]));
	}

	for (int i = 0; i < b.size(); ++i) {
		if (b[i].p1[axis] >= minx || b[i].p2[axis] <= maxx) {
			return false;
		}
		req.push_back(treq(2, b[i].p1[ax1], b[i].p1[ax2], i));
		req.push_back(treq(2, b[i].p2[ax1], b[i].p2[ax2], i));
	}
	vector<char> ch1(b.size()), ch2(b.size());
	sort(req.begin(), req.end());
	vector<int> S(hs + 2);
	for (int i = 0; i < req.size(); ++i) {
		if (req[i].t == 2) {
			int t = get_sum(S, req[i].y);
			if (t == a.size()) ch1[req[i].z] = 1;else
			if (t == 0) ch2[req[i].z] = 1;
		} else {
			add_sum(S, req[i].y, req[i].t);
			add_sum(S, req[i].z + 1, -req[i].t);
		}
	}
	for (int i = 0; i < b.size(); ++i)
		if (!ch1[i] || !ch2[i])
			return false;

	return true;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);

	while (T--) {
		int n;
		scanf("%d", &n);
		vector< vector<rect> > g(3);
		vector< vector<int> > h(3);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d%d%d%d", &rects[i].p1[0], &rects[i].p1[1], &rects[i].p1[2], &rects[i].p2[0], &rects[i].p2[1], &rects[i].p2[2]);
			for (int j = 0; j < 3; ++j) {
				h[j].push_back(rects[i].p1[j]);
				h[j].push_back(rects[i].p2[j]);
			}
		}
		for (int j = 0; j < 3; ++j) {
			sort(h[j].begin(), h[j].end());
			h[j].erase(unique(h[j].begin(), h[j].end()), h[j].end());
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				rects[i].p1[j] = lower_bound(h[j].begin(), h[j].end(), rects[i].p1[j]) - h[j].begin();
				rects[i].p2[j] = lower_bound(h[j].begin(), h[j].end(), rects[i].p2[j]) - h[j].begin();
				if (rects[i].p2[j] < rects[i].p1[j]) {
					swap(rects[i].p1[j], rects[i].p2[j]);
				}
			}
			if (rects[i].p1[0] == rects[i].p2[0]) {
				g[0].push_back(rects[i]);
			} else 
			if (rects[i].p1[1] == rects[i].p2[1]) {
				g[1].push_back(rects[i]);
			} else {
				g[2].push_back(rects[i]);
			}
		}

		int solved[3][3];
		memset(solved, 0, sizeof(solved));
		for (int i = 0; i < 3; ++i)
			for (int j = i + 1; j < 3; ++j)
				solved[i][j] = solved[j][i] = solve(g[i], g[j], i, max(h[0].size(), max(h[1].size(), h[2].size())));

		string ans = "NO";
		for (int i = 0; i < 3; ++i) if (g[i].size()) {
			bool ok = true;
			int c = 0;
			for (int j = 0; j < 3; ++j) if (i != j) {
				if (!solved[i][j]) {
					ok = false;
					break;
				} else {
					c += g[j].size();
				}
		   }
		   if (ok && c > 0) {
		   		ans = "YES";
		   		break;
		   }
		}
		
	   puts(ans.c_str());
	}


    return 0;
}
