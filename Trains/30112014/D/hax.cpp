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
#include <unordered_map>
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct hasher {
	std::hash<int> h;
	size_t operator()(const pair<int, int>& p) const {
		return h(p.first) ^ (h(p.second) << 1);
	}
};


inline int get_vertex(unordered_map< pair<int, int>, int, hasher>& vertex, vector<int>& sid, int x, int y) {
	int& t = vertex[make_pair(x, y)];
	if (!t) {
		t = vertex.size();
		sid.push_back(x);
	}	
	return t;
}
char kw[111], start[111], finish[111];
char lines[33333333];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);
	while (T--) {
		vector<int> sid(1);
		unordered_map<string, int> stop;
		unordered_map< pair<int, int>, int, hasher> vertex;
		vector< vector< pair<int, pair<int, int> > > > g;

		int stopc = 0;
		{
			scanf("%s", kw);
			gets(lines);

			char* word = strtok(lines, ", ");
			while (word != 0) {
				stop[word] = stopc++;
				word = strtok(0, ", ");
			}
		}

		int linec = 0;
		{
			scanf("%s", kw);
			gets(lines);

			char* word = strtok(lines, ", ");
			while (word != 0) {
				linec++;
				word = strtok(0, ", ");
			}
		}

		for (int lid = 0; lid < linec; ++lid) {
			scanf("%s", kw);
			scanf("%s", kw);

			vector<int> stops;
			{
				gets(lines);
				char* word = strtok(lines, ", ");
				while (word != 0) {
					stops.push_back(stop[word]);
					word = strtok(0, ", ");
				}
			}
			for (int i = 0; i < stops.size(); ++i) {
				if (i + 1 < stops.size()) {
					int x = get_vertex(vertex, sid, stops[i], lid + lid);
					int y = get_vertex(vertex, sid, stops[i + 1], lid + lid);
					if (x >= g.size()) g.resize(x + 1);
					g[x].push_back(make_pair(y, make_pair(0, -1)));
				}
				if (i - 1 < stops.size()) {
					int x = get_vertex(vertex, sid, stops[i], lid + lid + 1);
					int y = get_vertex(vertex, sid, stops[i - 1], lid + lid + 1);
					if (x >= g.size()) g.resize(x + 1);
					g[x].push_back(make_pair(y, make_pair(0, -1)));
				}
				{
					int x = get_vertex(vertex, sid, stops[i], lid + lid);
					int y = get_vertex(vertex, sid, stops[i], -1);
					if (x >= g.size()) g.resize(x + 1);
					if (y >= g.size()) g.resize(y + 1);
					g[x].push_back(make_pair(y, make_pair(1, 0)));
					g[y].push_back(make_pair(x, make_pair(0, 0)));

					x = get_vertex(vertex, sid, stops[i], lid + lid + 1);
					if (x >= g.size()) g.resize(x + 1);
					g[x].push_back(make_pair(y, make_pair(1, 0)));
					g[y].push_back(make_pair(x, make_pair(0, 0)));
				}
			}
		}

		scanf("%s", kw); scanf("%s", kw); scanf("%s", kw);
		scanf("%s", start);
		scanf("%s", kw); scanf("%s", kw); scanf("%s", kw);
		scanf("%s", finish);

		cerr << clock() << endl;

		vector<int> st(vertex.size() + 1);
		deque<int> q;
		vector< pair<int, int> > D(vertex.size() + 1, make_pair(1e9, 1e9));
		int x = vertex[make_pair(stop[start], -1)];
		q.push_back(x);
		D[x] = make_pair(1, 0);
		st[x] = 1;
		while (!q.empty()) {
			int x = q.front(); q.pop_front();
			st[x] = 2;
			for (int i = 0; i < g[x].size(); ++i) {
				int y = g[x][i].first;
				pair<int, int> d = make_pair(D[x].first + g[x][i].second.first, D[x].second + g[x][i].second.second);
				if (d < D[y]) {
					D[y] = d;
//					cerr << x << " " << y << " " << d.first << " " << d.second << endl;
					if (st[y] == 2) {
						q.push_front(y);						
					} else
					if (st[y] == 0) {
						q.push_back(y);
					}
					st[y] = 1;
				}
			}
		}
		pair<int, int> ans = make_pair(1e9, 1e9);
		int fid = stop[finish];
		for (int i = 0; i < linec; ++i) {
			int x = vertex[make_pair(fid, i + i)];
			ans = min(ans, D[x]);
			x = vertex[make_pair(fid, i + i + 1)];
			ans = min(ans, D[x]);
		}
		string s1 = (ans.first > 1) ? "s" : "";
		string s2 = ((-ans.second) > 1) ? "s" : "";
		cout << "optimal travel from " << start << " to " << finish << ": " << ans.first << " line" << s1 << ", " << -ans.second << " minute" << s2 << "\n";

		cerr << clock() << endl;
	}

    return 0;
}
