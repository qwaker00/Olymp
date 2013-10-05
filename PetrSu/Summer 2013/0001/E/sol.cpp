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

map< pair<int, int>, int > q;
map< int, int > D; 

int gcd(int a, int b) {
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a < b) swap(a, b);
	if (c > a) {
		cout << -1 << endl;
		return 0;
	}

	int d = gcd(a, b);
	if (c % d) {
		cout << "-1" << endl;
		return 0;
	}
	a /= d; b /= d; c /= d;
		
	typedef pair<int, int> pii;

	queue< pii> Q;
	Q.push(pii(0, 0));
	q[pii(0,0)] = 0;

	while (!Q.empty()) {
		pii x = Q.front(); Q.pop();
		int d = q[x];

		int C;
		C = x.first;
		if (D.find(C) == D.end()) {
			D[C] = d;
		}
		C = x.second;
		if (D.find(C) == D.end()) {
			D[C] = d;
		}

		//cerr << x.first << " " << x.second << ": " << d << endl;

		pii t;
		t = make_pair(0, x.second);
		if (q.find(t) == q.end()) {
			q[t] = d + 1;
			Q.push(t);
		}
		t = make_pair(x.first, 0);
		if (q.find(t) == q.end()) {
			q[t] = d + 1;
			Q.push(t);
		}
		t = make_pair(a, x.second);
		if (q.find(t) == q.end()) {
			q[t] = d + 1;
			Q.push(t);
		}
		t = make_pair(x.first, b);
		if (q.find(t) == q.end()) {
			q[t] = d + 1;
			Q.push(t);
		}

		int lim;
		
		lim = min(a - x.first, x.second);
		t = make_pair(x.first + lim, x.second - lim);
		if (q.find(t) == q.end()) {
			q[t] = d + 1;
			Q.push(t);
		}

		lim = min(x.first, b - x.second);
		t = make_pair(x.first - lim, x.second + lim);
		if (q.find(t) == q.end()) {
			q[t] = d + 1;
			Q.push(t);
		}
	}

	for (map<int, int>::iterator it = D.begin(); it != D.end(); ++it)
		cerr << it->first << " " << it->second << endl;
	
	return 0;
}
