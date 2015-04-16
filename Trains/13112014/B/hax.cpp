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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 111111;
int req[N][32], c[N][32];
int s[32];
int ans[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, m;
   	scanf("%d%d", &n, &m);
   	vector< pair<int, pair<int, int> > > z;
   	for (int i = 0; i < m; ++i) {
   		int l, r, q;
   		scanf("%d%d%d", &l, &r, &q);
   		for (int j = 0; j < 30; ++j) if ((1 << j) & q) {
   			++req[l][j];
   			--req[r + 1][j];
   		} else {
   			z.push_back(make_pair(j, make_pair(l, r)));
   		}
   	}
   	for (int i = 1; i <= n; ++i) {
   		int x = 0;
   		for (int j = 0; j < 30; ++j) {
   			s[j] += req[i][j];
   			if (s[j] > 0) {
   				x |= (1 << j);
   				c[i][j] = c[i - 1][j] + 1;
   			} else {
   				c[i][j] = c[i - 1][j];
   			}
   		}
   		ans[i] = x;
   	}

   	for (size_t i = 0; i < z.size(); ++i) {
//   		cerr << z[i].first << " " << z[i].second.first << " " << z[i].second.second << endl;
  // 		if (z[i].first == 0) {
   	//		++i;
   	//		--i;
   	//
   	//	}
   		if (c[z[i].second.second][z[i].first] - c[z[i].second.first - 1][z[i].first] == z[i].second.second - z[i].second.first + 1) {
   			puts("NO");
   			return 0;
   		}
   	}

   	puts("YES");
   	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
   	puts("");

    return 0;
}
