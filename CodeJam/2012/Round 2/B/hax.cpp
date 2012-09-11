#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
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


int n, w, l, T;
vector< pair<int, int> > p;

struct Tp {
	int r, i;

	bool operator<(const Tp& B)const {
		return r > B.r;
	}
} a[1111111];
int ansx[111111], ansy[111111];

bool ByI(const Tp& A, const Tp & B){
	return A.i < B.i;
}

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	cin >> T;
	for (int _ = 1; _ <= T; _++) {
		cin >> n >> w >> l;
		for (int i = 0; i < n; i++) {
			cin >> a[i].r;
			a[i].i = i;
		}
		sort(a, a + n);
		p.clear();

		p.push_back(make_pair(a[0].r, a[0].r));
		ansx[a[0].i] = 0;
		ansy[a[0].i] = 0;
		for (int i = 1, j = 1; i < n;) {
			if (j >= (int)p.size()) {
				int ri = p.back().first; 
				if (ri + a[i].r <= l) {
					p.push_back(make_pair(ri + a[i].r + a[i].r, a[i].r));
					ansx[a[i].i] = 0;
					ansy[a[i].i] = ri + a[i].r;
					i++;
					continue;
				} else {
					j = 0;
					continue;
				}
			} else {
				if ( (j == 0 && p[j].second + a[i].r  + a[i].r > w) || (j != 0 && p[j].second + a[i].r + a[i].r > p[j - 1].second) ) {
					j++;
					continue;
				} else {
					int pr = ((j == 0)? 0 : (p[j-1].first));
					if (pr + a[i].r * (j != 0) > l) {
						j++;
						continue;
					}

					int ll = p[j].first - pr;
					ansx[a[i].i] = p[j].second + a[i].r;
					ansy[a[i].i] = pr + a[i].r * (j != 0);
					if (a[i].r == ll) {
						p[j].second += a[i].r + a[i].r;
					} else {
						p.insert(p.begin() + j, make_pair(pr + a[i].r + a[i].r * (j != 0), p[j].second + a[i].r + a[i].r));
					}
					i++;
					continue;
				}
			}
			throw 666;
		}

		sort(a, a + n, ByI);
		printf("Case #%d:", _);
		for (int i = 0; i < n; i++) {
			printf(" %d %d", ansx[i], ansy[i]);

			for (int j = 0; j < i; j++) {
				LL r1 = sqr(LL(ansx[i]) - ansx[j]) + sqr(LL(ansy[i]) - ansy[j]);
				if (r1 < sqr(LL(a[i].r) + a[j].r)) {
					cout << endl << endl;
					cout << i << " " << j << endl;
					cout << ansx[i] << " " << ansy[i] << " " << a[i].r << endl;
					cout << ansx[j] << " " << ansy[j] << " " << a[j].r << endl;
					cout << r1 << endl;
					throw 555;
				}
			}
			if (ansx[i] < 0 || ansx[i] > w || ansy[i] < 0 || ansy[i] > l) {
				cout << endl;
				cout << w << " " << l << endl;
				throw 666;
			}
		}
		puts("");
	}

	return 0;
}
