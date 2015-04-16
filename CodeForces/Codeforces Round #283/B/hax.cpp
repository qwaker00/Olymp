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

const int N = 111111;
int g1[N], g2[N];
int n;

int find_next(int x, int t) {
	int gs1 = g1[x], gs2 = g2[x];
	int left = x, right = n;
	while (left < right) {
		int center = (left + right + 1) / 2;
		if (g1[center] - gs1 >= t ||
		    g2[center] - gs2 >= t) 
		    right = center - 1;
	   else
	   		left = center;
	}
	if (g1[left+1] - gs1 >= t ||
	    g2[left+1] - gs2 >= t)
		return left + 1;
	else
		return n + 1;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		g1[i] = g1[i - 1] + (x == 1);
		g2[i] = g2[i - 1] + (x == 2);
	}
	vector< pair<int, int> > ans;
	for (int t = 1; t <= n; ++t) {
		int s1 = 0, s2 = 0, x = 0, last = 0;
		while (x < n) {
			int nx = find_next(x, t);
			if (g1[nx] - g1[x] >= t) {
				++s1;
				last = 1;
			} else {
				++s2;
				last = 2;
			}
			x = nx;
		}
		if (x != n + 1 && (s1 > s2 && last == 1 || s2 > s1 && last == 2))
			ans.push_back(make_pair(max(s1, s2), t));
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i= 0; i < ans.size(); ++i)
		printf("%d %d\n", ans[i].first, ans[i].second);
    
    return 0;
}