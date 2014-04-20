#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define N 1111

int A[N][N], L[N], stn, st[N], MaxS[N][N], MaxW[N][N], Ans[N][N], V[N];

inline void maximize(int* x, int y) {
	if (*x < y) *x = y;
}
inline int max(int x, int y) {
	if (x < y) return y;
	return x;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    while (k--) {
    	int x, y;
    	scanf("%d%d", &x, &y);
    	A[x][y] = -1;
    }
    int i;
    for (i = 0; i <= n; ++i) A[0][i] = -1;
    for (i = 1; i <= n; ++i) {
    	int* a = A[i];
    	memset(V, 0, sizeof(V[0]) * (i + 2));
    	stn = 0;
    	int j;
    	for (j = 1; j <= m; ++j)  {
	    	if (a[j] != -1)
		   		a[j] = A[i - 1][j] + 1;
    		while (stn > 0 && a[st[stn - 1]] >= a[j]) --stn;
    		if (stn) {
    			L[j] = j - st[stn - 1];
    		} else {
    			L[j] = j;
    		}
    		st[stn++] = j;
    	}
    	stn = 0;
    	for (j = m; j >= 1; --j) {
    		while (stn > 0 && a[st[stn - 1]] > a[j]) --stn;
    		if (a[j] >= 0) {
	    		if (stn) {    			
	    			maximize(&V[a[j]], st[stn - 1] - j + L[j] - 1);
	    		} else {
	    			maximize(&V[a[j]], m - j + L[j]);
	    		}
	    	}
    		st[stn++] = j;
    	}
    	MaxS[i][1] = V[0];
    	for (j = 1; j <= i; ++j) MaxS[i][j + 1] = max(MaxS[i][j], (j + 1) * V[j]);
    	MaxW[i][i] = V[i];
   		for (j = i - 1; j >= 0; --j) MaxW[i][j] = max(MaxW[i][j + 1], V[j]);
    }
    for (i = 1; i <= n; ++i) {
    	int ans = 0;
    	int j;
    	for (j = i; j <= n; ++j) {
    		int p = j - i;
   			maximize(&ans, (j - i + 1) * MaxW[j][p]);
   			maximize(&ans, MaxS[j][p]);
    		Ans[i][j] = ans;
    	}
    }

    int q;
    scanf("%d", &q);
    while (q--) {
    	int x, y;
    	scanf("%d%d", &x, &y);
    	printf("%d\n", Ans[x][y]);
    }
    
    return 0;
}
