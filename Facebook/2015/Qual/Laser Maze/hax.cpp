#include <bits/stdc++.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
   	cin >> T;
   	for (int __case = 1; __case <= T; ++__case) {
   		int n, m;
		cin >> n >> m;		

		vector<string> f(n);
		queue< pair< pair<int, int>, int> > q;
		vector< vector< vector<bool> > > wall(n, vector< vector<bool> >(m, vector<bool>(4, false)));
		vector< vector< vector<int> > > D(n, vector< vector<int> >(m, vector<int>(4, 1e9)));
		int gi, gj;

		for (int i = 0; i < n; ++i) cin >> f[i];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) 
				if (f[i][j] == 'S') {
					D[i][j][0] = 0;
					q.push({{i, j}, 0});
				} else
				if (f[i][j] == 'G') {
					gi = i;
					gj = j;
				} else
				if (f[i][j] == '#') {
					for (int k = 0; k < 4; ++k) wall[i][j][k] = true;
				} else
				if (f[i][j] != '.') {
					int d = 0;
					if (f[i][j] == '>') d = 0;else
					if (f[i][j] == '<') d = 2;else
					if (f[i][j] == 'v') d = 1;else d = 3;
					for (int dir = 0; dir < 4; ++dir) {
						int x = i, y = j;													
						do {
							wall[x][y][dir] = true;
							x += dx[d];
							y += dy[d];
						} while(x >= 0 && y >=0 && x < n && y < m && (f[x][y] == '.' || f[x][y] == 'S' || f[x][y] == 'G'));
						d = (d + 1) & 3;
					}
				}
		int ans = -1;
		while (!q.empty()) {
			pair< pair<int, int>, int> t = q.front(); q.pop();
			int x = t.first.first;
			int y = t.first.second;
			int z = t.second;
			int d = D[x][y][z];

			if (x == gi && y == gj) {
				ans = D[x][y][z];
				break;
			}

			for (int i = 0; i < 4; ++i) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				int zz = (z + 1) & 3;
				if (xx >= 0 && yy >=0 && xx < n && yy < m && !wall[xx][yy][zz]) {
					if (D[xx][yy][zz] > d + 1) {
						D[xx][yy][zz] = d + 1;
						q.push({ {xx, yy}, zz});
					}
				}
			}
		}	
   		cout << "Case #" << __case << ": ";
   		if (ans == -1)
   			cout << "impossible\n";else
   			cout << ans << "\n";
   	}
    
    return 0;
}
