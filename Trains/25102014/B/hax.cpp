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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}   	 
	sort(a.rbegin(), a.rend());

	vector<int> v;
	for (int i = 0; i < n - 1; ++i) {
		vector<int> vv(v.size());
		for (size_t j = 0; j < v.size(); ++j) {
			vv[j] = v[j] % a[i];
		}
		vv.push_back(a[i]);

		v.insert(v.end(), vv.begin(), vv.end());
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}
	set<int> ans;
	for (int i = 0; i < v.size(); ++i) ans.insert(v[i] % a[n - 1]);

	int x = a[n - 1];
	for (int i = n - 2; i >= 0; --i) x %= a[i];
	ans.insert(x);

	cout << ans.size() << endl;
    
    return 0;
}
