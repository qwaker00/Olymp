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
    
    int n, m;
	cin >> n >> m;
	vector<string> s(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	bool ch = true;
	while (ch) {
		ch = false;
		for (int i = 1; i < n; ++i) {
			for (size_t j = 0; j < s[i].length(); ++j) {
				if (s[i][j] < s[i - 1][j]) {
					for (int k = 0; k < n; ++k) s[k].erase(s[k].begin() + j);
					++ans;
					ch = true;
					break;
				} else
				if (s[i][j] > s[i - 1][j]) break;
			}
		}
	}
	cout << ans << endl;
    
    return 0;
}
