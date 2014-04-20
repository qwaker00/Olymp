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

int A[N][N], L[N], stn, st[N], MaxS[N][N], MaxW[N][N], Ans[N][N], VL[N];
pair<int, int> V[N][N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    while (k--) {
    	int x, y;
    	scanf("%d%d", &x, &y);
    	A[x - 1][y - 1] = -1;
    }
    for (int i = 0; i < n; ++i) {
    	int* a = A[i];
    	pair<int,int>* v = V[i];

    	for (int j = 0; j < m; ++j) if (a[j] != -1) {
    		if (i)
	    		a[j] = A[i - 1][j] + 1;else
	    		a[j] = 0;
    	}
    	stn = 0;
    	for (int j = 0; j < m; ++j) {
    		while (stn > 0 && a[st[stn - 1]] >= a[j]) --stn;
    		if (stn) {
    			L[j] = j - st[stn - 1];
    		} else {
    			L[j] = j + 1;
    		}
    		st[stn++] = j;
    	}
    	stn = 0;
    	for (int j = m - 1; j >= 0; --j) {
    		while (stn > 0 && a[st[stn - 1]] > a[j]) --stn;
    		if (stn) {    			
    			v[j] = make_pair(a[j] + 1, st[stn - 1] - j + L[j] - 1);
    		} else {
	    		v[j] = make_pair(a[j] + 1, m - j + L[j] - 1);
    		}
    		st[stn++] = j;
    	}

    	sort(v, v + m);

    	int& j = VL[i] = 1;
    	for (int it = 1; it < m; ++it) {
    		if (v[it].first == v[it - 1].first)
    			v[j - 1].second = v[it].second;
    		else
    			v[j++] = v[it];
    	}
    	if (VL[i] == 0) continue;

    	MaxS[i][0] = v[0].first * v[0].second;
    	for (int j = 1; j < VL[i]; ++j)
    		MaxS[i][j] = max(MaxS[i][j - 1], v[j].first * v[j].second);

    	MaxW[i][VL[i] - 1] = v[VL[i] - 1].second;
    	for (int j = VL[i] - 2; j >= 0; --j)
    		MaxW[i][j] = max(MaxW[i][j + 1], v[j].second);
    }
    for (int i = 0; i < n; ++i) {
    	int ans = 0;
    	for (int j = i; j < n; ++j) {
    		int p = upper_bound(V[j], V[j] + VL[j], make_pair(j - i + 1, (int)1e9)) - V[j];
    		if (p < VL[j])
    			ans = max(ans, (j - i + 1) * MaxW[j][p]);
    		if (p > 0)
    			ans = max(ans, MaxS[j][p - 1]);
    		Ans[i][j] = ans;
    	}
    }
    cerr << clock() << endl;

    int q;
    scanf("%d", &q);
    while (q--) {
    	int x, y;
    	scanf("%d%d", &x, &y);
    	printf("%d\n", Ans[x - 1][y - 1]);
    }

    
    return 0;
}
