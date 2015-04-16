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

int sum(int x, int y) {
	if (x == -1 || y == -1) return -1;
	return x + y;
}

int solve(int n, int s, int f) {
	if (n < 1) return -1;
	if (n == 1) {
		if (s == f && s == 1) return 0;
		return -1;
	}
	if (s == f) {
		return -1;
	}

	if (s > f) return solve(n, f, s);
	if (s > 1) {
		return sum(solve(s, s, s - 1), solve(n - s, 1, f - s));
	}
	if (f < n) {
		if (f < n - 1) {
			return sum(solve(f - s, 1, f - s), solve(n - f, 1, 2));
		} else {
			return sum(solve(f - s, 1, f - s), 1);
		}
	}

	assert(s == 1);
	assert(f == n);
	if (n >= 4) {
		int t = (n - 1) / 3;
		return sum(solve(n - t * 3, 1, n - t * 3), t);
	} else {
		return n - 1;
	}
}

int brute(int n, int s, int f) {
	deque< pair<int, int> > q;
	map< pair<int, int>, int> d;
	--s; --f;

	q.push_back(make_pair(s, 1 << s));
	d[make_pair(s, 1 << s)] = 0;
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop_front();

		if (t.first == f) {
			if (t.second + 1 == (1 << n)) {
				return d[t];
			}
			continue;
		}

		int x = t.first;
		int msk = t.second;
		if (x > 0 && !(msk & (1 << (x - 1)))) {
			pair<int, int> to = make_pair(x - 1, msk | (1 << (x - 1)));
			if (d.count(to) == 0 || d[to] > d[t] + 1) {
				d[to] = d[t] + 1;
				q.push_back(to);
			}							
		}
		if (x < n - 1 && !(msk & (1 << (x + 1)))) {
			pair<int, int> to = make_pair(x + 1, msk | (1 << (x + 1)));
			if (d.count(to) == 0 || d[to] > d[t] + 1) {
				d[to] = d[t] + 1;
				q.push_back(to);
			}							
		}
		if (x > 1 && !(msk & (1 << (x - 2)))) {
			pair<int, int> to = make_pair(x - 2, msk | (1 << (x - 2)));
			if (d.count(to) == 0 || d[to] > d[t]) {
				d[to] = d[t];
				q.push_back(to);
			}							
		}
		if (x < n - 2 && !(msk & (1 << (x + 2)))) {
			pair<int, int> to = make_pair(x + 2, msk | (1 << (x + 2)));
			if (d.count(to) == 0 || d[to] > d[t]) {
				d[to] = d[t];
				q.push_back(to);
			}							
		}
	}
	return -1;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n, s,f ;
	cin >> n >> s >> f;   	 
	cout << solve(n, s, f) << endl;

/*	for (int n = 2; n <= 20; ++n) {
		cerr << n << endl;
		for (int s = 1; s <= n; ++s)
			for (int f = 1; f <= n; ++f)
				if (solve(n, s, f) != brute(n, s, f)) {
					cerr << n << " " << s << " " << f << endl;
					cerr << solve(n, s, f) << endl;
					cerr << brute(n, s, f) << endl;
				}
	}
*/    
    return 0;
}
