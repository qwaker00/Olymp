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

const int N = 222222;

struct Tp {
	int x, y;
	bool operator<(const Tp& t) const {
		return y < t.y || y == t.y && x < t.x;
	}
	bool operator==(const Tp& t) const  {
		return x == t.x && y == t.y;
	}
};

LL mul(const Tp& a, const Tp& b, const Tp& c) {
	return LL(c.x - a.x) * (b.y - a.y) - LL(c.y - a.y) * (b.x - a.x);
}

struct byangle {
	Tp x;

	byangle(Tp x) : x(x) {}

	bool operator()(const Tp& a, const Tp& b) const {
		return mul(x, a, b) > 0;
	}
};

vector<Tp> gethull(const vector<Tp>& a) {
	/*cerr << "GetHull:\n";
	for (int i = 0; i < a.size(); ++i) {
		cerr << a[i].x << " " << a[i].y << endl;
	}
	cerr << endl;
	*/

	vector<Tp> st1;
	vector<Tp> st2;
	for (int i = 0; i < a.size(); ++i) {
		while (st1.size() > 1 && mul(st1[st1.size() - 2], st1[st1.size() - 1], a[i]) <= 0) st1.pop_back();
		while (st2.size() > 1 && mul(st2[st2.size() - 2], st2[st2.size() - 1], a[i]) >= 0) st2.pop_back();
		st1.push_back(a[i]);
		st2.push_back(a[i]);
	}
	if (st2.size() > 2) {
		st1.insert(st1.end(), st2.rbegin() + 1, st2.rend() - 1);
	}
	return st1;
}

int subhullcount(const vector<Tp>& a, int l, int r, int skip) {
	vector<Tp> st1;
	st1.push_back(a[l]);
	for (int i = l + 1; i <= r; ++i) {
		if (i == skip) continue;
		while (st1.size() > 1 && mul(st1[st1.size() - 2], st1[st1.size() - 1], a[i]) <= 0) st1.pop_back();
		st1.push_back(a[i]);
	}
//	cerr << l << " " << r << " " << st1.size() << endl;
	return st1.size() - 2;
}

LL gcd(LL x, LL y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
    freopen("average.in", "r", stdin);
    freopen("average.out", "w", stdout);

    int n;
	scanf("%d", &n);

	vector<Tp> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a.begin(), a.end());

	vector<Tp> hull = gethull(a);

	vector<Tp> all;
	for (int i = 0; i < a.size(); ++i) if (!(a[i] == hull[0])) {
		all.push_back(a[i]);
	}
	sort(all.begin(), all.end(), byangle(hull.front()));

	/*
	cerr << hull.size() << endl;
	for (int i= 0; i < hull.size(); ++i) {
		cerr << hull[i].x << " " << hull[i].y << endl;
	}
	cerr << endl;
	for (int i= 0; i < all.size(); ++i) {
		cerr << all[i].x << " " << all[i].y << endl;
	}
	cerr << endl;
	*/

	vector<int> pos(hull.size());
	int j = 1;
	for (int i = 0; i < all.size() && j < hull.size(); ++i) {
		if (all[i] == hull[j]) {
			pos[j] = i;
			++j;
		}
	}
	assert(j == hull.size());


	LL ansa = LL(a.size() - hull.size()) * hull.size();
//	cerr << hull.size() << " x " << a.size() - hull.size() << endl;
	for (int i = 0; i < hull.size(); ++i) {
		if (i < 2 || i + 1 == hull.size()) {
			vector<Tp> b;
			b.reserve(a.size());
			for (int j = 0; j < a.size(); ++j) if (!(a[j] == hull[i])) {
				b.push_back(a[j]);
			}
			int t = gethull(b).size();
//			cerr << t << endl;
			ansa += t;
		} else {
			int t = subhullcount(all, pos[i - 1], pos[i + 1], pos[i]) + hull.size() - 1;
//			cerr << t << endl;
			ansa += t;
		}
	}

	LL ansb = n;
	LL g = gcd(ansa, ansb);
	cout << (ansa / g) << "/" << (ansb / g) << endl;

    return 0;
}
