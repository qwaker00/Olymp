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

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);

    int T;
	cin >> T;   	
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		set<int> a1, a2;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a2.insert(a[i]);
		}
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
			a2.insert(b[i]);
		}
		for (int i = 0; i < n; ++i) {
			if (find(b.begin(), b.end(), a[i]) != b.end()) {
				a1.insert(a[i]);
			}
		}
		cout << a2.size() << " " << a1.size() << "\n";
	}

    return 0;
}
