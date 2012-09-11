#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
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

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
char s[2222][2222];
int n, m, was[2222][2222], wx[2222][2222], wy[2222][2222], xx, yy, xxm, yym;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	scanf("%d%d\n", &n, &m);
	queue< pair<int,int> > q;
	for (int i = 0; i < n; i++) {
		gets(s[i]);
		for (int j = 0; j < m; j++) if (s[i][j] == 'S') {
			q.push(make_pair(i, j));
			was[i][j] = true;
			wx[i][j] = i;
			wy[i][j] = j;
		}
	}


	while (!q.empty()) {
		pair<int,int> t = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			xx = t.first + dx[i];
			yy = t.second + dy[i];
			xxm = (xx + m * n * 10) % n;
			yym = (yy + m * n * 10) % m;

			if (s[xxm][yym] == '#') continue;
			if (was[xxm][yym]) {
				if (wx[xxm][yym] == xx && wy[xxm][yym] == yy) {
					continue;
				}
				puts("Yes");
				return 0;
			}

			q.push(make_pair(xx, yy));
			was[xxm][yym] = true;
			wx[xxm][yym] = xx;
			wy[xxm][yym] = yy;
		}
	}
	puts("No");

	return 0;
}
