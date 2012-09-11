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

queue<pair<int,int> > q;
int T, n, m, d[555][555];
char s[555][555];

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d", &T);
    while (T--) {	
    	memset(d, 127, sizeof(d));
    	scanf("%d%d\n", &n, &m);
    	for (int i = 1; i <= n; i++) {
    		gets(s[i] + 1);
    		for (int j = 1; j <= m; j++) if (s[i][j] == 'L') {	
    			d[i][j] = 0;
    			q.push(make_pair(i, j));
    		}
    	}

    	while (!q.empty()) {
    		pair<int, int> t = q.front(); q.pop();
    		int D = d[t.first][t.second];

    		for (int i = 0; i < 4; i++) {
    			int x = t.first + dx[i];
    			int y = t.second + dy[i];
    			if (x < 1 || y <1 || x > n || y > m) continue;
    			if (d[x][y] > D + 1) {
    				d[x][y] = D + 1;
    				q.push(make_pair(x, y));
    			}
    		}
    	}

    	int ans = 0;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			if (s[i][j] == 'B') {
    				ans += d[i][j] * 2;
    			}
    		}
    	}
    	cout << ans << endl;
    }

    return 0;
}
