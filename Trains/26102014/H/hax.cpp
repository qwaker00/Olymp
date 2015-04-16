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
vector<int> g[N];
int was[N];

inline int divup(int x, int y) {
	if (x < 0) return 0;
	return (x + y - 1) / y;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, m, k, mx = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    	if (g[x].size() > g[mx].size()) {
    		mx = x;
    	}
    	if (g[y].size() > g[mx].size()) {
    		mx = y;
    	}
    }

    vector<int> cycle;
    vector<int> chain;

    if (g[mx].size() <= 2) {
    	for (int i = 1; i <= n; ++i) if (g[i].size() == 1) {
    		mx = i;
    		chain.push_back(n - 1);
    		break;
    	}
    	if (chain.empty()) {
    		mx = 1;
    		cycle.push_back(n - 1);
    	}
    } else {
	    was[mx] = 1;
    	for (size_t i = 0; i < g[mx].size(); ++i) if (!was[g[mx][i]]) {    
			int x = g[mx][i], prev = mx;
			int l = 0;
			bool fnd;
			do {
				was[x] = 1;
				++l;
				fnd = 0;
				for (size_t j = 0; j < g[x].size(); ++j)
					if (g[x][j] != prev) {
						prev = x;
						x = g[x][j];
						fnd = 1;
						break;
					}
			   if (!fnd) break;
			   if (was[x]) break;
			} while(true);

			if (fnd)
				cycle.push_back(l);
			else
				chain.push_back(l);
	    }
    }

    int left = 0;
    int right = n;
    while (left < right) {
    	int d = (right + left) / 2;
    	int sum = 0;

    	int maxprof = 0;
    	int maxneed = 0;
    	for (size_t i = 0; i < chain.size(); ++i) {
    		int c1 = chain[i] / (2 * d + 1);
    		sum += c1;
    		int rest = chain[i] - c1 * (2 * d + 1);
    		if (rest > d) {
    			sum += 1;
	    		maxprof = max(maxprof, 2 * d + 1 - rest);
    		} else {
    			maxneed = max(maxneed, rest);
    		}
    	}
    	if (maxprof < maxneed + 1) {
    		sum += 1;
    		maxprof = d + 1;
    	}

    	int sum1 = sum;
    	int sum2 = sum;

    	for (size_t i = 0; i < cycle.size(); ++i) {
    		sum1 += divup(cycle[i] - (maxprof - 1) * 2, 2 * d + 1);
    	}
    	maxprof = d + 1;
    	sum2 += 1;
    	for (size_t i = 0; i < cycle.size(); ++i) {
    		sum2 += divup(cycle[i] - (maxprof - 1) * 2, 2 * d + 1);
    	}

    	sum = min(sum1, sum2);

    	if (sum <= k) {
    		right = d;
    	} else {
    		left = d + 1;
    	}
    }
    cout << left << endl;
    
    return 0;
}
