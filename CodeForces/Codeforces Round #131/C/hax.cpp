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

int dx[] = {0, 1};
int dy[] = {1, 0};

vector<int> f[606][303];
bool was[606][303][303];
int a[333][333], c[333], cx[333][333], cy[333][333],  revx[606][303], revy[606][303];
int n;

bool ch(int x, int y) {
	return (x > 0 && x <= n && y > 0 && y <= n);
}

void Max(int i, int j, int k, int val) {
	if (j < k) swap(j, k);
	was[i][j][k] = true;

	int v = val + a[revx[i][j]][revy[i][j]] + ((j != k) ? (a[revx[i][k]][revy[i][k]]) : (0));
	if (f[i][j][k] < v) {
		f[i][j][k] = v;
	}
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

//	int mem = sizeof(was) + sizeof(f) + sizeof(a) + sizeof(cx) + sizeof(revx) * 2;


    cin >> n;

    for (int i = 1; i < n + n; i++) {
    	if (i <= n) {
    		c[i] = i;
    	} else {
	    	c[i] = n + n - i;
        }
        for (int j = 1; j <= c[i]; j++) {
	        f[i][j].resize(j + 1, -1e9);
//	        mem += (j + 1) * 4;
		}
	}
//	cerr << mem << endl;


    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
    		cx[i][j] = i + j - 1;
    	}
    }
    for (int i = 1; i < n + n; i++) {	
    	int x = 0, y = 0;
    	if (i <= n) x = i, y = 1;else
    			    x = n, y = i - n + 1;
    	for (int j = 1; j <= c[i]; j++) {
    		cy[x][y] = j;
    		x--;
    		y++;
    	}
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		revx[cx[i][j]][cy[i][j]] = i;
    		revy[cx[i][j]][cy[i][j]] = j;
    	}
    }

    
/*    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <=n; j++) {	
	    	fprintf(stderr, "(%d,%d) ", cx[i][j], cy[i][j]);
    	}
	   	fprintf(stderr, "\n");
    }
*/

    f[1][1][1] = a[1][1];
    was[1][1][1] = true;
    for (int i = 1; i < n + n - 1; i++) {
    	for (int j = 1; j <= c[i]; j++) {
    	    int x1 = revx[i][j];
    		int y1 = revy[i][j];

    		for (int d1 = 0; d1 < 2; d1++) if (ch(x1 + dx[d1], y1 + dy[d1])) {

    			for (int k = 1; k <= j; k++) if (was[i][j][k]) {
    				int x2 = revx[i][k];
	    			int y2 = revy[i][k];
		    		for (int d2 = 0; d2 < 2; d2++) if (ch(x2 + dx[d2], y2 + dy[d2])) {
		    			Max(i + 1, cy[x1 + dx[d1]][y1 + dy[d1]], cy[x2 + dx[d2]][y2 + dy[d2]], f[i][j][k]);
		    		}

    	        }

            }
    	}
    }
    cout << f[n + n - 1][1][1];


    return 0;
}
