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

int ans;
vector<string> f(10);
int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};

inline bool black(int x, int y) {
	return (x >= 0 && x < 10 && y >= 0 && y < 10 && f[x][y] == 'B');
}
inline bool  fr(int x, int y) {
	return (x >= 0 && x < 10 && y >= 0 && y < 10 && f[x][y] == '#');
}

void rec(int x, int y, int c) {
	if (c > ans) ans = c;
	for (int i = 0; i < 4; ++i) {
		if (black(x + dx[i], y + dy[i]) && fr(x + dx[i] + dx[i], y + dy[i] + dy[i])) {
			f[x][y] = '#';
			f[x + dx[i]][y + dy[i]] = '#';
			f[x + dx[i] + dx[i]][y + dy[i] + dy[i]] = 'W';

			rec(x + dx[i] + dx[i], y + dy[i] + dy[i], c + 1);

			f[x + dx[i] + dx[i]][y + dy[i] + dy[i]] = '#';
			f[x + dx[i]][y + dy[i]] = 'B';
			f[x][y] = 'W';
		}
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	cin >> T;   	
	while (T--) {
		for (int i = 0; i < 10; ++i) {
			cin >> f[i];
//			cout << f[i] << endl;
		}
		ans = 0;
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j) if (f[i][j] == 'W') {
				rec(i, j, 0);
			}
		cout << ans << "\n";
	}

    return 0;
}
