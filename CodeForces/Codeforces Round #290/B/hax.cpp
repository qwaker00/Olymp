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
#include <unordered_map>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int a[333], c[333];
unordered_map<int, int> D;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> c[i];

	priority_queue< pair<int, int> > q;
	for (int i = 0; i < n; ++i) {
		q.push(make_pair(-c[i], a[i]));
		if (D.count(a[i]) == 0)
			D[a[i]] = c[i];
		else
			D[a[i]] = min(D[a[i]], c[i]);
    }
	while (!q.empty()) {
 		pair<int, int> t = q.top(); q.pop();
 		int d = -t.first;
 		int x = t.second;
 		if (x == 1) {
	 		cout << d << endl;
	 		return 0;
 		}
 		if (D[x] != d) continue;
 		for (int i = 0; i < n; ++i) {
 			int g = __gcd(x, a[i]);
 			if (g < x && (D.count(g) == 0 || d + c[i] < D[g])) {
 				D[g] = d + c[i];
 				q.push(make_pair(-(d + c[i]), g));
 			}
 		}
	}
	cout << -1 << endl;

    return 0;
}
