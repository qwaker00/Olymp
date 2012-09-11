#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
//#include <math.h>
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

#define N 505

int A[N][9][N], L[N][9][N], R[N][9][N], lg[N], next[N], prev[N];
int n, m, q, x1, y1, x2, y2, t1, t2;

int main() {
    freopen("rmq2.in", "r", stdin);
    freopen("rmq2.out", "w", stdout);
//    cerr << ((sizeof(f) + sizeof(lg))) << endl;

    scanf("%d%d", &n, &m);

	lg[1] = 0;
	for (int i = 2; i <= n || i <= m; ++i) lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n || i <= m; ++i) {
		next[i] = (i | (i - 1)) + 1;
		prev[i] = (i & (i - 1));
	}

//	cerr << lg[n] << endl;

    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= m; ++j)
    		scanf("%d", &A[i][0][j]);

    for (int i1 = 0; i1 < 9; ++i1)
    	for (int i = 1; i <= n; ++i) {
    		int* LL = L[i][i1], *RR = R[i][i1], *AA = A[i][i1];
    		for (int j = 1; j <= m; ++j) LL[j] = RR[j] = 2147483647;
    		for (int j = 1; j <= m; ++j) {
    				if (i1 != 0) {
    					if (i + (1 << (i1 -1)) <= n)
	    					AA[j] = min(A[i][i1 - 1][j], A[i + (1 << (i1 - 1))][i1 - 1][j]);else
	    					AA[j] = A[i][i1 - 1][j];
    				}
    				int k = j;
    				while (k > 0)  {
    					LL[k] = min(LL[k], AA[j]);
    					k = prev[k];
    				}
    				k = j;
    				while (k <= m)  {
    					RR[k] = min(RR[k], AA[j]);
    					k = next[k];
    				}
	    	}
	    }

	scanf("%d", &q);	 
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		t1 = lg[x2 - x1 + 1];
		x2 = x2 - (1 << t1) + 1;

		int ans = A[x1][0][y1], t, *R1 = R[x1][t1], *L1 = L[x1][t1], *R2 = R[x2][t1], *L2 = L[x2][t1];
		t = y2;
		while ( prev[t] >= y1 ) {
			ans = min(ans, min(R1[t], R2[t]));
			t = prev[t];
		}
		ans = min(ans, min(A[x1][t1][t], A[x2][t1][t]));
		t = y1;
		while (next[t] <= y2) {
			ans = min(ans, min(L1[t], L2[t]));
			t = next[t];
		}

		printf("%d\n", ans);
	}                   
    return 0;
}
