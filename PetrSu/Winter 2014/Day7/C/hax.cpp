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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 1111

int n, k;
int a[N][N / 32], b[N];
vector<int> g[N];
int was[N], wasy[N], IT = 0, pr[N], nx[N];

bool kuhn(int x) {
	if (was[x] == IT) return false;
	was[x] = IT;
	for (int i = 0, y = 0; i < (int)g[x].size(); ++i) {
		wasy[y = g[x][i]] = IT;
		if (pr[y] == -1 || kuhn(pr[y])) {
			pr[y] = x;
			nx[x] = y;
			return true;
		}
	}
	return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) {
    	int l;
    	char buf[5];

    	scanf("%d", &l);
    	for (int j = 0; j < l; ++j) {
    		int x;
    		scanf("%d", &x);
    		--x;
    		a[i][x >> 5] |= (1 << (x & 31));
    	}

    	scanf("%s", buf);
    	b[i] = (strcmp(buf, "Girl") == 0);
    }

	int nn = ((n + 31) >> 5) + 1;
    for (int i = 0; i < k; ++i) if (b[i] == 1) {
    	for (int j = 0; j < k; ++j) if (b[j] == 0) {
			bool isin = true;
			for (int l = 0; l < nn; ++l)
				if ((a[i][l] | a[j][l]) != a[i][l]) {
					isin = false;
					break;
				}
			if (isin) {
				g[i].push_back(j);
	//			cerr << i << " " << j << endl;
			}
    	}
    }


    vector<int> ans;
    memset(pr, -1, sizeof(pr));
    memset(nx, -1, sizeof(nx));

/*    for (int i = 0; i < k; ++i) {
    	for (int j = 0; j < g[i].size(); ++j)
    		if (pr[g[i][j]] == -1) {
    			pr[g[i][j]] = i;
    			nx[i] = g[i][j];
    			break;
    		}
    }
*/
    for (int i = 0; i < k; ++i) if (nx[i] == -1) {
    	++IT;
    	kuhn(i);
    }

    ++IT;
    for (int i = 0; i < k; ++i) if (nx[i] == -1) kuhn(i);

    for (int i = 0; i < k; ++i) if (was[i] != IT) ans.push_back(i + 1);
    for (int i = 0; i < k; ++i) if (wasy[i] == IT) ans.push_back(i + 1);

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); ++i) {
    	cout << ans[i] << endl;
    }

    return 0;
}
