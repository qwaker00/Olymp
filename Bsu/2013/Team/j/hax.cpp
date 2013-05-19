#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, m;
char s[2222][2222];
int d[2222][2222];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

int main() {
    freopen("vampires.in", "r", stdin);
    freopen("vampires.out", "w", stdout);
    
	scanf("%d%d\n", &n, &m);

	queue< pair<int, int> > q;

	memset(d, 63, sizeof(d));
	for (int i= 0; i < n; ++i) {
		gets(s[i]);
		for (int j =0; j < m; ++j) if (s[i][j] == 'V') {
			q.push(make_pair(i, j));
			d[i][j] = 0;
		}
	}    

	int ans = 0;
	while (!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		int dd = d[t.first][t.second] + 1;
		for (int i = 0; i < 4; ++i) {
			int xx = t.first + dx[i];
			int yy = t.second + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (s[xx][yy] == '#') continue;
			if (d[xx][yy] > dd) {
				d[xx][yy] = dd;
				q.push(make_pair(xx, yy));
				if (dd > ans) ans = dd;
			}
		}
	}

//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cerr << d[i][j] << " ";
//		}
//		cerr << endl;
//	}

	cout << ans << endl;

    
    return 0;
}
