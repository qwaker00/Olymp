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

    int n;
	cin >> n;

	vector< vector<int> > c(3, vector<int>(n + 1));

	for (int it = 0; it < 3; ++it) {

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<int> was(n + 1);
	for (int i = 1; i <= n; ++i) if (!was[i]) {
		int x= i;
		int l = 0;
		do {
			was[x] = 1;
			x = a[x];
			++l;
		} while(x != i);
		++c[it][l];
	}
	}

	vector< vector< pair<int,int> > > cc(3);
	for (int it = 0; it < 3; ++it) {
		for (int j = 1; j <= n; ++j) if (c[it][j]) {
			cc[it].push_back(make_pair(j, c[it][j]));
//			cerr << it << " " << j << endl;
		}
	}

	LL ans = 0;
	for (int i = 0; i < cc[0].size(); ++i)
		for (int j =0; j< cc[1].size(); ++j)
			for (int k = 0; k < cc[2].size(); ++k) {
				LL g = LL(__gcd(cc[0][i].first, cc[1][j].first)) * __gcd(cc[1][j].first, cc[2][k].first) * __gcd(cc[0][i].first, cc[2][k].first);
//				int g = __gcd(cc[0][i].first, __gcd(cc[1][j].first, cc[2][k].first));
				ans += LL(g) * cc[0][i].second * cc[1][j].second * cc[2][k].second;
			}
	cout << ans << endl;
    
    return 0;
}
