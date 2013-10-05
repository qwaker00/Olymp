#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const ll b = 279470273ll;
const ll c = 4294967291ll;

const int N = 100011;
const int M = 10001;

int x[N], y[N], pos1[N], pos2[N], pos3[N], pos4[N];
struct Tp {
	int x, y, i;
	bool operator<(const Tp& b) const {
		return x < b.x || x == b.x && y < b.y;
	}
} A[N], B[N], C[N], D[N];

ll d[N];
 
inline ll sqr(int x) {
	return ll(x) * x;
}
inline ll dist(int i, int j) {
	return sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
}

bool used[N];
int n; ll seed;


ll brute() {
	used[0] = 1;
	for (int i = 0; i < n; ++i) {
		d[i] = dist(0, i);
	}

	ll ans = 0;
	for (int q = 1; q < n; ++q) {
		int cand = -1;
		for (int i = 0; i < n; ++i)
			if (!used[i] && (cand == -1 || d[i] < d[cand])) {
				cand = i;
			}

		ans = max(ans, d[cand]);
	    used[cand] = true;
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				d[i] = min(d[i], dist(cand, i));
			}
		}
	}

	return ans;
}

#define NEI 170
int q[N], pq[N], hn = 0;

void Up(int i) {
	int p = pq[i];
	while (p > 1 && d[i] < d[q[p >> 1]]) {
		q[p] = q[p >> 1];
		pq[q[p]] = p;
		p >>= 1;
	}
	q[p] = i;
	pq[i] = p;
}

void Down(int i) {
	int p = pq[i];
	while (p + p <= hn) {
		int nxt = p + p + (p + p < hn && d[ q[p + p + 1] ] < d[ q[p + p] ]);
		if (d[i] <= d[q[nxt]]) break;
		q[p] = q[nxt];
		pq[q[p]] = p;
		p = nxt;
	}
	q[p] = i;
	pq[i] = p;
}

void Add(int i) {
	q[++hn] = i;
	pq[i] = hn;
	Up(i);
}

void Del(int i) {
	int p = pq[i];
	if (p != hn) {
		q[p] = q[hn];
		pq[ q[p] ] = p;
		--hn;
		Down(q[p]);
		Up(q[p]);
	} else --hn;
}

ll brute2() {
	ll ans = 0;

	memset(used, 0, sizeof(used));
	used[0] = 1;

	for (int i = 0; i < n; ++i) {
		d[i] = dist(0, i);
		Add(i);
	}

	while (hn) {
		int x = q[1];
		ll dd = d[x];

		Del(x);

		if (used[x]) continue;
		used[x] = 1;

		ans = max(ans, dd);

		for (int i = max(pos1[x] - NEI, 0); i < pos1[x]; ++i) {
			int y = A[i].i;
			if (used[y]) continue;
			ll ddd = dist(y, x);
			if (ddd < d[y]) {
				d[y] = ddd;
				Up(y);
			}
		}
    	for (int i = max(pos2[x] - NEI, 0); i < pos2[x]; ++i) {
			int y = B[i].i;
			if (used[y]) continue;
			ll ddd = dist(y, x);
			if (ddd < d[y]) {
				d[y] = ddd;
				Up(y);
			}
		}
    	for (int i = max(pos3[x] - NEI, 0); i < pos3[x]; ++i) {
			int y = C[i].i;
			if (used[y]) continue;
			ll ddd = dist(y, x);
			if (ddd < d[y]) {
				d[y] = ddd;
				Up(y);
			}
		}
    	for (int i = max(pos4[x] - NEI, 0); i < pos4[x]; ++i) {
			int y = D[i].i;
			if (used[y]) continue;
			ll ddd = dist(y, x);
			if (ddd < d[y]) {
				d[y] = ddd;
				Up(y);
			}
		}

    	for (int i = min(pos1[x] + NEI, n) - 1; i > pos1[x]; --i) {
			int y = A[i].i;
			if (used[y]) continue;
			ll ddd = dist(y, x);
			if (ddd < d[y]) {
				d[y] = ddd;
				Up(y);
			}
		}
		for (int i = min(pos2[x] + NEI, n) - 1; i > pos2[x]; --i) {
			int y = B[i].i;
			if (used[y]) continue;
			ll ddd = dist(y, x);
			if (ddd < d[y]) {
				d[y] = ddd;
				Up(y);
			}
		}
    	for (int i = min(pos3[x] + NEI, n) - 1; i > pos3[x]; --i) {
			int y = C[i].i;
			if (used[y]) continue;
			ll ddd = dist(y, x);
			if (ddd < d[y]) {
				d[y] = ddd;
				Up(y);
			}
		}
		for (int i = min(pos4[x] + NEI, n) - 1; i > pos4[x]; --i) {
			int y = D[i].i;
			if (used[y]) continue;
			ll ddd = dist(y, x);
			if (ddd < d[y]) {
				d[y] = ddd;
				Up(y);
			}
		}
	}

//	for (int i = 0; i < n; ++i) assert(used[i]);

    return ans;
}


int main() {
//	freopen(".in", "r", stdin);

  	cin >> n >> seed;
	for (int i = 0; i < n; ++i) {
    	seed = (seed * b) % c;
		x[i] = seed % 1000000;
		seed = (seed * b) % c;
		y[i] = seed % 1000000;
	}

	if (n < M) {
		cout << brute() << endl;
	} 
	else{
    	for (int i = 0; i < n; ++i) {
			A[i].x = x[i];
			A[i].y = y[i];
			A[i].i = i;
		}
		sort(A, A + n);
		for (int i = 0; i < n; ++i) pos1[A[i].i] = i;

		for (int i = 0; i < n; ++i) {
			B[i].x = y[i];
			B[i].y = x[i];
			B[i].i = i;
		}
		sort(B, B + n);
		for (int i = 0; i < n; ++i) pos2[B[i].i] = i;

    	for (int i = 0; i < n; ++i) {
			C[i].x = x[i] + y[i];
			C[i].y = x[i] - y[i];
			C[i].i = i;
		}
		sort(C, C + n);
		for (int i = 0; i < n; ++i) pos3[C[i].i] = i;

		for (int i = 0; i < n; ++i) {
			D[i].x = x[i] - y[i];
			D[i].y = x[i] + y[i];
			D[i].i = i;
		}
		sort(D, D + n);
		for (int i = 0; i < n; ++i) pos4[D[i].i] = i;

		cout << brute2() << endl;
	}
	cerr << clock() << endl;

	return 0;
}