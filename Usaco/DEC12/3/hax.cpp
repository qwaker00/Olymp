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

int n, c, m, was[555];

struct Tp {
	int x1, y1, x2, y2;

	Tp() {}
	Tp(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
} a[555];
vector< pair<int, int> > pp;
pair<int, int> cow[555];


inline bool InterLine(const Tp& s1, const Tp& s2) {
	LL A = s1.y2 - s1.y1;
	LL B = s1.x1 - s1.x2;
	LL C = -s1.x1 * A - s1.y1 * B;
	LL t1 = A * s2.x1 + B * s2.y1 + C;
	LL t2 = A * s2.x2 + B * s2.y2 + C;
	return t1 <= 0 && t2 >= 0 || t1 >= 0 && t2 <= 0;
}

inline bool Intersect(const Tp& s1, const Tp& s2) {
	return InterLine(s1, s2) && InterLine(s2, s1);
} 

int Point(int x, int y) {
	static int cpoints = 0;
	static map< pair<int, int>, int> points;
	if (points.count(make_pair(x, y)))
		return points[make_pair(x, y)];
	pp.push_back(make_pair(x, y));
	return points[make_pair(x, y)] = cpoints++;
}

vector< vector<int> > g, gg;  
vector< vector<int> > used;  

void add(int x, int y, int id) {
	if (x >= g.size()) g.resize(x + 1);
	if (x >= gg.size()) gg.resize(x + 1);
	g[x].push_back(y);
	gg[x].push_back(id);
}

set<int> ss[555];

int Ang(const pair<int, int>&a, const pair<int, int>&b) {
	if (a.first == b.first) {
		if (a.second > b.second) return 1;
		return 3;
	} else {
		if (a.first < b.first) return 0;
		return 2;
	}
}

int main() {
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);
	
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
		add(Point(a[i].x1, a[i].y1), Point(a[i].x2, a[i].y2), i);
		add(Point(a[i].x2, a[i].y2), Point(a[i].x1, a[i].y1), i);
	}
	for (int i = 0; i < c; ++i) {
		scanf("%d%d", &cow[i].first, &cow[i].second);
	}
	for (int i = 0; i < g.size(); ++i) {
		for (int j = 0; j < g[i].size(); ++j)
			for (int k = j + 1; k < g[i].size(); ++k)
				if (Ang(pp[i], pp[g[i][j]]) > Ang(pp[i], pp[g[i][k]])) {
					swap(g[i][j], g[i][k]);
					swap(gg[i][j], gg[i][k]);
				}
	}

	int facec = 0;
	used.resize(g.size());
	for (int i = 0; i < g.size(); ++i)
		used[i].resize(g[i].size());
	for (size_t i = 0; i < g.size(); ++i)
		for (size_t j = 0; j < g[i].size(); ++j) {
			if (!used[i][j]) {
				used[i][j] = true;
				int v = g[i][j], pv = i, id = gg[i][j];
				vector<int> face;
				while (true) {
					face.push_back(id);
					vector<int>::iterator it = find(g[v].begin(), g[v].end(), pv);
					if (++it == g[v].end())  it = g[v].begin();
					if (used[v][it - g[v].begin()])  break;
					used[v][it - g[v].begin()] = true;
					id = gg[v][it - g[v].begin()];
					pv = v, v = *it;
				}
//				for (int l = 0; l < face.size(); ++l)
//					cerr << a[face[l]].x1 << "," << a[face[l]].y1 << "," << a[face[l]].x2 << "," << a[face[l]].y2 << "  ";
//				cerr << endl;

				facec++;
				for (int k = 0; k < c; ++k) {
					int cnt = 0;		
					for (int l = 0; l < face.size(); ++l) {
						if (Intersect(Tp(cow[k].first, cow[k].second, cow[k].first + 1, 1000100),
									  a[face[l]])
						   )
							++cnt;
					}
					if ((cnt & 1) == 1)
						ss[k].insert(facec);
				}
			}
		}
	int out = 0;
	map< set<int>, int> ans;
	for (int i = 0; i < c; ++i)
		if (++ans[ss[i]] > out)
			out = ans[ss[i]];
	cout << out << endl;
    
    return 0;
}
