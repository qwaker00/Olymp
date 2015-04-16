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

int a[22], bonus[22];
double f[122][122][11];
double ans[22][122];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
	cin >> n;
	for (int it = 0; it < n; ++it) {
		int c, m;
		cin >> c >> m;
		for (int i = 0; i < m; ++i) {
			string s;
			cin >> s;
			if (s[0] == '+') {
				bonus[i] = 1;
				s = s.substr(1);
			} else
				bonus[i] = 0;
			a[i] = atoi(s.c_str());
		}

		memset(f, 0, sizeof(f));
		memset(ans[it], 0, sizeof(ans[it]));
		f[0][0][0] = 1;
		for (int i = 0; i + 1 < 122; ++i) {
			for (int sc = 0; sc < 122; ++sc) {
				for (int r = 0; r < c; ++r) {


				    for (int j = 0; j < m; ++j) {
						int sc2 = sc + a[j];
						if (sc2 >= 122) sc2 = 121;
						f[i + 1][sc2][r + 1 - bonus[j]] += f[i][sc][r] / m;
                    }


				}
				ans[it][sc] += f[i][sc][c];
			}
		}

		for (int j = 0; j < 122; ++j)
			for (int r = 0; r <= c; ++r)
				ans[it][j] += f[121][j][r];

		for (int j = 120; j >= 0; --j)
			ans[it][j] += ans[it][j + 1];
	}
	int k;
	cin >> k;

	for (int i = 1; i <= k; ++i) {
		double ma = -1;
		int out = -1;
		for (int it = 0; it < n; ++it) {
			if (ans[it][i + 1] > ma) {
				ma = ans[it][i + 1];
				out = it + 1;
			}
		}
		cout << out << "\n";
	}
    
    return 0;
}
