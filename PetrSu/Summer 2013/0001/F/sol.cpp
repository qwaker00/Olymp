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

int f(int x) {
	return x - (x - 4) / 2; 
}

typedef pair<int, int> pii;
#define mp make_pair

int main() {
	freopen("foss.in", "r", stdin);
	freopen("foss.out", "w", stdout);


	int T;
	scanf("%d", &T);
	
	while (T--) {
		int n; scanf("%d", &n);

		if (n & 1) {
			printf("%d\n", (n / 4) + 1);
			
			deque<pii> a;
			a.push_back(pii(5002, 0));
			a.push_front(pii(5000, 0));
			int st = 0;
			for (int i = 2; i <= n; i += 2) {
				if (st & 1) {
					pii c = a.front();
					a.push_front(pii(c.first, c.second + 1));
					c = a.back();
					a.push_back(pii(c.first, c.second + 1));
				} else {
					pii c = a.front();
					a.push_front(pii(c.first - 1, c.second));
					c = a.back();
					a.push_back(pii(c.first + 1, c.second));
				}
				st++;
			}
			a.push_back(pii(5001, a.back().second + (a.back().first - a.front().first) / 2));

			for (deque<pii>::iterator it = a.begin(); it != a.end(); ++it)
				cout << it->first << " " << it->second << endl;
		} else {
			printf("%d\n", f(n));

			int m = n - 1;
			vector<pii> a;
			int st = 0;
			pii cur(0, 0);
			a.push_back(cur);
			for (int i = 1; i < m; ++i) {
				if (i & 1) {
					cur.first++;
				} else {
					cur.second++;
				}
				a.push_back(cur);
			}
			for (int i = 1; i < a.size(); ++i) {
				a[i].first += 2000;
			}
			a.back().second += 2000;
            
            a.push_back(mp(a[0].first, a.back().second));
            for (int i = 0; i < n; ++i) printf("%d %d\n", a[i].first, a[i].second);
		}
	}	
	
	return 0;
}
