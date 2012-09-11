#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int dx[] = {0, 0, -1, 1}, dy[]= {-1, 1, 0, 0};
int c[111][111], IT = 0;
int n, m, C[111];
string s[111];

void Dfs(int x, int y) {
	c[x][y] = IT;
	for (int k = 0; k < 4;k ++) {
		int xx = x + dx[k];
		int yy = y + dy[k];
		if (xx >= 0 && yy >=0 && xx < n && yy < m && s[xx][yy] == '#' && c[xx][yy] != IT) {
			Dfs(xx, yy);
		}
	}
}

bool good() {
	IT++;
	bool first = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (s[i][j]== '#' && c[i][j] != IT) {
			if (first) {
				return false;
			}
			first = true;
			Dfs(i, j);
		}
	}
	return true;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (s[i][j] == '#') {
			int ne = 0;
			for (int k = 0; k < 4;k ++) {
				int xx = i + dx[k];
				int yy = j + dy[k];
				if (xx >= 0 && yy >=0 && xx < n && yy < m && s[xx][yy] == '#') {
					ne++;
				}
			}
			C[ne]++;
			cnt++;

			s[i][j] = '.';
			if (!good()) {
				cout << 1 << endl;
				return 0;
			}
			s[i][j] = '#';
		}
	}
	if (C[2] > 0 && cnt > 3) {
		cout << 2 << endl;
		return 0;
	}
	if (C[3] > 0 && cnt > 4) {
		cout << 3 << endl;
		return 0;
	}
	if (C[4] > 0 && cnt > 5) {
		cout << 4 << endl;
		return 0;
	}
	cout << -1 << endl;

	return 0;
}
