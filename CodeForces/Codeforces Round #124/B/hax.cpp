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
int n, m, was[2222][2222][2], wx[2222][2222][2], wy[2222][222][2], xx, yy, xxm, yym, ppm;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	scanf("%d%d\n", &n, &m);
	queue< pair<int,int> > q;
	for (int i = 0; i < n; i++) {
		gets(s[i]);
		for (int j = 0; j < m; j++) if (s[i][j] == 'S') {
			q.push(make_pair(i, j));
			was[i][j][0] = true;
			wx[i][j][0] = i;
			wy[i][j][0] = j;
		}
	}


	while (!q.empty()) {
		pair<int,int> t = q.front(); q.pop();
//		cerr << t.first << " " << t.second << endl;

		for (int i = 0; i < 4; i++) {
			xx = t.first + dx[i];
			yy = t.second + dy[i];
			xxm = (xx + m * n * 10) % n;
			yym = (yy + m * n * 10) % m;
			ppm = ( ((xx + m * n * 10) / n) ^ ((yy + m * n * 10) / m) ) & 1;


			if (s[xxm][yym] == '#') continue;
//			cerr << xxm << " " << yym << " " << ppm << endl;
			if (was[xxm][yym][ppm]) {
				if (wx[xxm][yym][ppm] == xx && wy[xxm][yym][ppm] == yy) {
					continue;
				}
				puts("Yes");
				return 0;
			}

			q.push(make_pair(xx, yy));
			was[xxm][yym][ppm] = true;
			wx[xxm][yym][ppm] = xx;
			wy[xxm][yym][ppm] = yy;
		}
	}
	puts("No");

	return 0;
}
