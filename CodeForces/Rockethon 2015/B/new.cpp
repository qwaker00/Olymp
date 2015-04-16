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

vector<int> solve(int n, ll m) {
	if (n == 1) {	
		vector<int> a(1, 1);
		return a;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (m >= (1ll << (n - i - 2))) {
			m -= (1ll << (n - i - 2));
			continue;
		}
		vector<int> subans = solve(n - i - 1, m);
		for (int j = 0; j < subans.size(); ++j) subans[j] += i + 1;
		subans.insert(subans.begin(), i + 1);
		for (int j = 0; j < i; ++j) subans.push_back(i- j);
		return subans;
	}
	vector<int> ans;
	for (int i = n; i > 0; --i) ans.push_back(i);
	return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n;
	ll m;
	cin >> n >> m;

	vector<int> ans = solve(n, m - 1);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	
    return 0;
}
