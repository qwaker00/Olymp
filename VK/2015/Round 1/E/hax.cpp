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
#include <unordered_set>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

namespace std {
	template<>
	struct hash< pair<int, int> > {
		std::hash<int> hasher;

		size_t operator()(const pair<int, int>& p) const {
			return (hasher(p.first) >> 1) ^ hasher(p.second);
		}
	};
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n, m, k, q;
	unordered_set<pair<int, int> > l;

	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		l.insert({x, y});
	}
	for (int i = 0; i < q; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		unordered_set<int> okx;
		unordered_set<int> oky;
		for (int x = x1; x <= x2; ++x)
		for (int y = y1; y <= y2; ++y) {
			if (l.count({x, y})) {
				okx.insert(x);
				oky.insert(y);
			}
		}
		if (okx.size() == x2 - x1 + 1 || oky.size() == y2 - y1 + 1) {
			cout << "YES\n";
		} else
			cout << "NO\n";
	}
    
    return 0;
}
