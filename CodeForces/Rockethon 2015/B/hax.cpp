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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const double PI = 3.1415926535897932384626433832795;
template<typename T>
T sqr(T x) { return x * x; }

using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
	
	int n, m;
	cin >> n >> m;	
	vector< vector<int> > ans;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) a[i] = i + 1;
	ll masu = 0;
	do {
		ll su = 0;
		for (int i = 0; i < n; ++i) {
			int mi = a[i];
			for (int j = i; j < n; ++j) {
				mi = min(a[j], mi);
				su += mi;
			}
		}
		if (su > masu) {
			masu = su;			
			ans.clear();
			ans.push_back(a);
		} else
		if (su == masu)
			ans.push_back(a);
	} while(next_permutation(a.begin(), a.end()));

/*	cerr << ans.size() << endl;
	for (int j = 0; j < ans.size(); ++j) {
		for (int i = 0; i < n; ++i) {
			cerr << ans[j][i] << " ";
		}
		cerr << endl;
	}
*/	
	for (int i = 0; i < n; ++i) {
		cout  << ans[m - 1][i] << " ";
	}
	cout << endl;
	
    return 0;
}
