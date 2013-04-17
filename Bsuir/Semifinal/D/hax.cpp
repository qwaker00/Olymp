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

int pr[2222];
vector< pair<int, int> > C[11111];
int n;

int fs(int x) {
	if (pr[x] != x) pr[x] = fs(pr[x]);
	return pr[x];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
	scanf("%d", &n);
	for (int i =0 ; i< n; ++i) {
		for (int j =0 ; j< n; ++j) {
			int c;
			scanf("%d", &c);
			if (c <= 10000)
				C[c].push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < n; ++i) pr[i] = i;

	printf("%d\n", n);
	for (int i = 1; i <= 10000; ++i) {
		for (int j = 0; j < C[i].size(); ++j) {
			int xx = fs(C[i][j].first);
			int yy = fs(C[i][j].second);
			if (xx != yy) {
				printf("%d %d %d\n", C[i][j].first + 1, C[i][j].second + 1, i);
				pr[xx] = yy;
			}
		}
	}
    
    return 0;
}
