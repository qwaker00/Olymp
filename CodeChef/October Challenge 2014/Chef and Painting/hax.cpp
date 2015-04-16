#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

typedef vector< vector<bool> > matr;
matr a;
int n, m;

int paint(matr& a, int mxx, int mxy, int mxd) {
	int c =0;
		if (mxd == 1) {
			int xx = mxx - 1, yy = mxy;
			while (xx > 0 && a[xx][yy] == 0) {
				a[xx][yy] = 2;
				--xx;
				++c;
			}
			xx = mxx, yy = mxy;
			while (xx <= n && a[xx][yy] == 0) {
				a[xx][yy] = 2;
				++xx;
				++c;
			}
		} else {
			int xx = mxx, yy = mxy - 1;
			while (yy > 0 && a[xx][yy] == 0) {
				a[xx][yy] = 2;
				--yy;
				++c;
			}
			xx = mxx, yy = mxy;
			while (yy <= m && a[xx][yy] == 0) {
				a[xx][yy] = 2;
				++yy;
				++c;
			}
		}
	return c;
}

vector<string> solve(matr a, int k) {
	vector<string> ans;
	int ready = k;
	while (ready != n * m) {
		int mx = -1;
		int mxx = 0, mxy = 0, mxd = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] == 0) {
					int x1 = i;
					while (x1 - 1 > 0 && a[x1 - 1][j] == 0) --x1;
					int x2 = i;
					while (x2 + 1 <= n && a[x2 + 1][j] == 0) ++x2;

					if (x2 - x1 + 1 > mx) {
						mx = x2 - x1 + 1;
						mxx = i;
						mxy = j;
						mxd = 1;
					}
								
					int y1 = j;
					while (y1 - 1 > 0 && a[i][y1 - 1] == 0) --y1;
					int y2 = j;
					while (y2 + 1 <= m && a[i][y2 + 1] == 0) ++y2;

					if (y2 - y1 + 1 > mx) {
						mx = y2 - y1 + 1;
						mxx = i;
						mxy = j;
						mxd = 0;
					}						
				}
			}		
		assert(mx != -1);
		ready += paint(a, mxx, mxy, mxd);
		{
			stringstream out;
			out << mxx << " " << mxy << " " << mxd;
			ans.push_back(out.str());
		}
	}
	return ans;
}

size_t solveC(matr a, int k) {
	int ans = 0;
	int ready = k;
	while (ready != n * m) {
		int mx = -1;
		int mxx = 0, mxy = 0, mxd = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (a[i][j] == 0) {
					int x1 = i;
					while (x1 - 1 > 0 && a[x1 - 1][j] == 0) --x1;
					int x2 = i;
					while (x2 + 1 <= n && a[x2 + 1][j] == 0) ++x2;

					if (x2 - x1 + 1 > mx) {
						mx = x2 - x1 + 1;
						mxx = i;
						mxy = j;
						mxd = 1;
					}
								
					int y1 = j;
					while (y1 - 1 > 0 && a[i][y1 - 1] == 0) --y1;
					int y2 = j;
					while (y2 + 1 <= m && a[i][y2 + 1] == 0) ++y2;

					if (y2 - y1 + 1 > mx) {
						mx = y2 - y1 + 1;
						mxx = i;
						mxy = j;
						mxd = 0;
					}						
				}
			}		
		assert(mx != -1);
		ready += paint(a, mxx, mxy, mxd);
		++ans;
	}
	return ans;
}

inline bool timeout() {
	return clock() > 2.7 * CLOCKS_PER_SEC;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);
    
    int k;
	cin >> n >> m >> k;
	a.assign(n + 1, vector<bool>(m + 1));
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}

	vector< pair<int, int> > fr;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 0)
				fr.push_back(make_pair(i, j));

	int iters = 0;
	vector<string> ans = solve(a, k);
	while ( !timeout() ) {
		++iters;
		int ri = ((rand() << 15) ^ rand()) % fr.size();
		int x = fr[ri].first;
		int y = fr[ri].second;
		int rj = ((rand() << 15) ^ rand()) % fr.size();
		int x2 = fr[rj].first;
		int y2 = fr[rj].second;
		if (ri == rj) continue;
		for (int d1 = 0; d1 < 2; ++d1) {
			{
				matr b(a);
				int kk = k + paint(b, x, y, d1);
				if (solveC(b, kk) + 1 < ans.size()) {
					vector<string> sol = solve(b, kk);
					stringstream out;
					out << x << " " << y << " " << d1;
					sol.insert(sol.begin(), out.str());
					ans = sol;
				}
			}
			if (timeout()) break;

			for (int d2 = 0; d2 < 2; ++d2) {
				matr b(a);
				int kk = k + paint(b, x, y, d1);
				if (b[x2][y2] == 0) {
					kk += paint(b, x2, y2, d2);				
					if (solveC(b, kk) + 2 < ans.size()) {
						vector<string> sol = solve(b, kk);
						{
							stringstream out;
							out << x2 << " " << y2 << " " << d2;
							sol.insert(sol.begin(), out.str());
						}
						{
							stringstream out;
							out << x << " " << y << " " << d1;
							sol.insert(sol.begin(), out.str());
						}
						ans = sol;
					}
				}
				if (timeout()) break;
			}
			if (timeout()) break;
		}
	}

	cout << ans.size() << "\n";
	for (size_t i = 0; i < ans.size(); ++i)
		cout << ans[i] << "\n";

//	cerr << iters << endl;
    
    return 0;
}
