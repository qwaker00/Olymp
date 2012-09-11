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


#define N 2222
#define M 111111

int n, m, a, b, c, D3[N], D2[N], D1[N], d[N][N], T, kk = 0, of, p1, p2;
int xx[N], yy[M+M], pp[M+M];

struct Tp{
	int x, d;
	Tp(int x = 0, int d = 0):x(x),d(d){}
	bool operator<(const Tp& B)const {
		return d > B.d;
	}
};

void Dist(int* D, int x) {
	priority_queue<Tp> q;
	memset(D, 127, sizeof(D[0]) * N);
	D[x] = 0;
	q.push(Tp(x, 0));
	while (!q.empty()) {
		Tp t = q.top();q.pop();
		x = t.x;
		if (t.d != D[x]) continue;
		for (int i = xx[x]; i; i = pp[i]) {
			int y = yy[i];
			if (D[y] <= D[x] + d[x][y]) continue;
			D[y] = D[x] + d[x][y];
			q.push(Tp(y, D[y]));
		}
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> T;
    while (T--) {
    	cin >> n >> m;
    	cin >> of >> p1 >> p2;
    	kk = 0;
    	memset(xx, 0, sizeof(xx));
    	for (int i = 0; i < m; i++) {
    		cin >> a >> b >> c;
    		d[a][b] = d[b][a] = c;
    		yy[++kk] = b, pp[kk] = xx[a], xx[a] = kk;
    		yy[++kk] = a, pp[kk] = xx[b], xx[b] = kk;
    	}
    	a = p1; b = p2; c = of;
    	Dist(D1, a);
    	Dist(D2, b);
    	Dist(D3, c);
    	int ans = 0;
    	for (int i = 0; i < n; i++) {
    		if (D1[i] + D3[i] == D1[c] && D2[i] + D3[i] == D2[c] && D3[i] > ans) {
    			ans = D3[i];
    		}
    	}
    	cout << ans << endl;
    }

    return 0;
}
