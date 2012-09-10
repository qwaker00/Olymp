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
#include <deque>
#include <map>
#include <functional>
#include <numeric>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 211111

struct Tp {
	LL x, i;

	Tp(LL x = 0, LL i = 0) :x(x), i(i) { };

	bool operator<(const Tp& B)const {
		return x < B.x || (x == B.x && i < B.i);
	}
};
LL ans[N];
set<Tp> aa, cc;
LL L, x;
int n, m;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> L >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		aa.insert(Tp(x, i));
		cc.insert(Tp(x, i));
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		cc.insert(Tp(x, i + n));
		aa.insert(Tp(L - x, i + n));
	}

	LL dt = 0, t = 0;
	int it = 0;
	while(aa.size()) {
//		for (set<Tp>::iterator j = aa.begin(); j != aa.end(); j++) cout << j->x << " " << j->i << endl;
//		cout << endl;
		if (it & 1) {
			LL d1 = aa.begin()->x + dt;
			int right;
			{
				t += d1;
				dt -= d1;
				right = aa.begin()->i < n; 
				if (!right) {
					ans[cc.rbegin()->i] = t;
					cc.erase(*cc.rbegin());
				} else {
					ans[cc.begin()->i] = t;
					cc.erase(*cc.begin());
				}
				aa.erase(*aa.begin());

				if (aa.size() && (aa.begin()->x + dt) == 0) {
					right = aa.begin()->i < n; 
					if (!right) {
						ans[cc.rbegin()->i] = t;
						cc.erase(*cc.rbegin());
					} else {
						ans[cc.begin()->i] = t;
						cc.erase(*cc.begin());
					}
					aa.erase(*aa.begin());
					++it;
				}
			}
		} else {
			LL d1 = L - (aa.rbegin()->x + dt);
			//int d2 = 1e9;
			int right;
			{
				t += d1;
				dt += d1;
				right = aa.rbegin()->i < n; 
				if (right) {
					ans[cc.rbegin()->i] = t;
					cc.erase(*cc.rbegin());
				} else {
					ans[cc.begin()->i] = t;
					cc.erase(*cc.begin());
				}
				aa.erase(*aa.rbegin());

				if (aa.size() && L - (aa.rbegin()->x + dt) == 0) {
					right = aa.rbegin()->i < n; 
					if (right) {
						ans[cc.rbegin()->i] = t;
						cc.erase(*cc.rbegin());
					} else {
						ans[cc.begin()->i] = t;
						cc.erase(*cc.begin());
					}
					aa.erase(*aa.rbegin());
					
					++it;
				}
			}
		}
		++it;
	}
	for (int i = 0; i < n; ++i) cout << ans[i] << " ";
	cout << endl;
	for (int i = n; i < n + m; ++i) cout << ans[i] << " ";
	cout << endl;
 
	return 0;
}
