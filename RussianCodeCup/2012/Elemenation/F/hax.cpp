#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct Tp {
	int t1, t2, l, r;
	bool operator<(const Tp& B)const{
		return t1 < B.t1;
	}
} a[2222];
struct Tb {
	int t, l;
	bool operator<(const Tb& B)const{
		return t < B.t || t==B.t && l < B.l;
	}
} b[2222];
int n, x, dt, bn, can[2222];

int Process(int t, int x, int id) {
	if (!can[id]) return 0;
	for (int i = 0; i < n; i++) {
		if (t >= a[i].t1 && t <= a[i].t2 && x > a[i].l && x < a[i].r) return 0;
	}

	int hi = ((i&1)==0) ? (a[(id - 1)>>1].t2 - a[(id - 1)>>1].t1 + 1) : 0;
	int lo = 0;

	for (int i = 0; i < n; i++) {
		if (a[i].t1 > t) {
			if (a[i].l >= x) {
				if ( (a[i].l - x) + hi <= a[i].t1 - t) {
					can[i + i + 1] = true;
				}
			} else  {
				if ( (x - a[i].l))
			}
		}
	}
}

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	cin >> n >> x;
	for (int i = 0; i < n ;i++) {
		cin >> a[i].t1 >> dt >> a[i].l >> a[i].r;
		a[i].t2 = a[i].t1 + dt - 1;

		b[bn].t = a[i].t1;
		b[bn].l = a[i].l;
		bn++;

		b[bn].t = a[i].t2;
		b[bn].l = a[i].l;
		bn++;
	}
	sort(a, a + n);
	sort(b, b + bn);

	int t;
	can[0] = true;
	if (t = Process(0, 0, 0)) {
		cout << t << endl;
	}
	for (int i = 0; i < bn; i++) {
		if (t = Process(b[i].t, b[i].l, i + 1)) {
			cout << t << endl;
		}
	}

	return 0;
}
