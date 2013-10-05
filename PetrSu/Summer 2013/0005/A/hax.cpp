#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>


typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const LD PI = acos(-1.);
using namespace std;


#define N 55

typedef bool TBM[N][N];

char mp[N][N];
TBM fl[1025];
bool was[1025];
char s[N][N], ts[N][N];
int k, n, m, stx, sty, fix, fiy;

int D[1025][55][55][2];

struct Tp {
	int msk;
	int x, y, z;
	Tp(int msk, int x = 0, int y = 0, int z = 0): msk(msk), x(x), y(y), z(z) {}
};
queue<Tp> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
//	freopen(".in", "r", stdin);

	scanf("%d%d\n", &m, &n);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '#') {
				mp[i][j] = '#';
			} else
			if (s[i][j] == '|') {
				mp[i][j] = '|';
			} else {
				if (s[i][j] == '_') fl[0][i][j] = 0;else
				if (s[i][j] == '^') fl[0][i][j] = 1;else
				if (s[i][j] == '%') {
					stx = i;
					sty = j;
					fl[0][i][j] = 0;
				}else
				if (s[i][j] == '&') {					
					fix = i;
					fiy = j;
					fl[0][i][j] = 0;
				} else
				if (s[i][j] >= 'a' && s[i][j] <= 'z') {
					mp[i][j] = s[i][j];
					fl[0][i][j] = 0;
				} else
				if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
					mp[i][j] = s[i][j] - 'A' + 'a';
					fl[0][i][j] = 1;
				}
			}
		}
	}
	scanf("%d\n", &k);
	was[0] = 1;
	for (int it = 0; it < k; ++it) {
		for (int i = 0; i < n; ++i) gets(ts[i]);
		for (int msk = (1 << k) - 1; msk >= 0; --msk)
			if (was[msk]) {
				TBM& fl1 = fl[msk];
				TBM& fl2 = fl[msk | (1 << it)];
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j)
						fl2[i][j] = fl1[i][j] ^ (ts[i][j] == '*');
				was[msk | (1 << it)] = 1;
			}
	}

	memset(D, 63, sizeof(D));

	q.push(Tp(0, stx, sty, 0));
	D[0][stx][sty][0] = 0;
	while (!q.empty()) {
		Tp t = q.front(); q.pop();
		int d = D[t.msk][t.x][t.y][t.z];		

//		cerr << t.msk << " " << t.x << " " << t.y << " " << t.z << endl;

		if (mp[t.x][t.y] == '|') {
			if (D[t.msk][t.x][t.y][!t.z] > d + 1) {
				D[t.msk][t.x][t.y][!t.z] = d + 1;
				q.push(Tp(t.msk, t.x, t.y, !t.z));

//				cerr << t.msk << " " << t.x << " " << t.y << " " << t.z << " -> " 
//				     << t.msk << " " << t.x << " " << t.y << " " << !t.z << endl;
			}
		}
		for (int i = 0; i < 4; ++i) {
			int xx = t.x + dx[i];
			int yy = t.y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || mp[xx][yy] == '#' || (t.z != fl[t.msk][xx][yy] && mp[xx][yy] != '|')) continue;
			if (D[t.msk][xx][yy][t.z] > d + 1) {
				D[t.msk][xx][yy][t.z] = d + 1;
				q.push(Tp(t.msk, xx, yy, t.z));

//				cerr << t.msk << " " << t.x << " " << t.y << " " << t.z << " -> " 
//				     << t.msk << " " << xx << " " << yy << " " << t.z << endl;
			}
		}
		if (mp[t.x][t.y] >= 'a' && mp[t.x][t.y] <= 'z') {
			int sw = mp[t.x][t.y] - 'a';
			if (D[t.msk ^ (1 << sw)][t.x][t.y][ fl[t.msk ^ (1 << sw)][t.x][t.y] ] > d + 1) {
				D[t.msk ^ (1 << sw)][t.x][t.y][ fl[t.msk ^ (1 << sw)][t.x][t.y] ] = d + 1;
				q.push(Tp(t.msk ^ (1 << sw), t.x ,t.y ,fl[t.msk ^ (1 << sw)][t.x][t.y]));

//				cerr << t.msk << " " << t.x << " " << t.y << " " << t.z << " -> " 
//				     << (t.msk ^ (1 << sw)) << " " << t.x << " " << t.y << " " << fl[t.msk ^ (1 << sw)][t.x][t.y] << endl;
			}
		}
	}
	int ans = 2e9;
	for (int i = 0; i < (1 << k); ++i) {
		ans = min(ans, D[i][fix][fiy][ fl[i][fix][fiy] ]);
//		cerr << i << " " << D[i][fix][fiy][0] << endl;
	}
	if (ans > 1e9)
		cout << -1 << endl;else
		cout << ans << endl;
	
	return 0;
}
