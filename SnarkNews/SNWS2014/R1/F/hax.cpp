#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

    vector<int> ans;
    int x;
	cin >> x;

	ans.push_back(x - 1);
	for (int i = 2; i < x; ++i) {
		int xx = x, an = 0, a[66];
		while (xx) {	
			a[an++] = xx % i;
			xx /= i;
		}
		if (an == 2) break;

		bool pal = true;
		for (int j = 0; j < an; ++j) if (a[j] != a[an - j - 1]) {
			pal = false;
			break;
		}

		if (pal) {
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(ans.end(), unique(ans.begin(), ans.end()));

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	cout << endl;
	

    return 0;
}
