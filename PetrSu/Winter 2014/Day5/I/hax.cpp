#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <memory.h>


typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
using namespace std;

const int N = 400222;
pair<int, int> a[N];

ll sqr(ll x) {return x * x;}
ll dist(int x, int y) {	
	return sqr(a[x].first - a[y].first) + sqr(a[x].second - a[y].second);
}

int bx = 0, by = 1;
ll bestd = 0;

bool cmpx(int A, int B) {
	return a[A].first < a[B].first;
}
bool cmpy(int A, int B) {
	return a[A].second < a[B].second;
}

vector<int> cands;
int b[N];
int c[N];
ll rec(int l, int r) {
	if (r - l < 10) {
		ll res = 2e18;
		for (int i = l; i < r; ++i)
			for (int j = i + 1; j < r; ++j) {
				ll cand = dist(b[i], b[j]);
				if (cand < res) {
					res = cand;
					if (res < bestd) {
						bestd = res;
						bx = b[i];
						by = b[j];
					}
				}
			}
		sort(b + l, b + r, cmpy);
		return res;
	}

	int l1 = l, r1 = (l + r) >> 1;
	int l2 = r1, r2 = r;
	ll res = min(rec(l1, r1), rec(l2, r2)); 

	int border = a[b[r1]].first;
	int pos = l;
	while (l1 < r1 && l2 < r2) {
		if (a[b[l1]].second < a[b[l2]].second) {
			c[pos++] = b[l1++];	
		} else {
			c[pos++] = b[l2++];	
		}
	}
	while (l1 < r1) c[pos++] = b[l1++];
	while (l2 < r2) c[pos++] = b[l2++];
	memcpy(b + l, c + l, (r - l) * sizeof(int));

	cands.clear();
	for (int i = l; i < r; ++i) {
		if (sqr(ll(a[ b[i] ].first - border)) < res) {
			cands.push_back(b[i]);	
		}
	}

	for (int i = 0; i < cands.size(); ++i)
		for (int j = 1; j < 10; ++j)
			if (i >= j) {
				ll cand = dist(cands[i], cands[i - j]);
				if (cand < res) {
					res = cand;
					if (res < bestd) {
						bestd = res;
						bx = cands[i];
						by = cands[i - j];
					}
				}
			}
	return res;
}

int main() {
	freopen("illegal.in", "r", stdin);
	freopen("illegal.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].first, &a[i].second);
		b[i] = i;
	}
	bestd = dist(0, 1);
	sort(b, b + n, cmpx);

	rec(0, n);
	cout << bx + 1 << " " << by + 1 << endl;
	
	return 0;
}
