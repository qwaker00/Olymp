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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

typedef long double LD;

int n;

LD star[5][2] = {
{3.830127018922193, 3.366025403784439},
{-3.601321235851749, 10.057331467373021},
{0.466045194906253, 19.192786043799030},
{10.411264148588986, 18.147501411122495},
{12.490381056766580, 8.366025403784439}
};

LD ans[555][2];
int r[555][555], deg[555], out[555], st[555], stn = 0, on = 0;

void Add(int x, int y) {
	r[x][y] = r[y][x] = 1;
	deg[x]++;
	deg[y]++;
}

int main() {
//    freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);

    cin >> n;
    LD offx = 0, offy = 0;
    int an = 0;
    for (int i = 0; i < n; i++) {    	
    	for (int j = 0; j < 5; j++)  {
    		ans[an][0] = star[j][0] + offx;
    		ans[an][1] = star[j][1] + offy;
    		for (int k = 1; k < 3 && k < j; k++) Add(an, an - k - 1);
    		an++;
    	}
    	if (i != n - 1) {
    		--an;
    		for (int i = 0; i < an; i++) if (r[an][i]) {
    			r[an][i] = r[i][an] = 0;
    			deg[an]--;
    			deg[an + 1]++;
    			r[an + 1][i] = r[i][an + 1] = 1;
    		}
    	}
    	offx += star[4][0] - star[1][0];
    	offy += star[4][1] - star[1][1];
    }

    cout.precision(20);
    cout << fixed;
    cout << an << endl;
    for (int i = 0; i < an; i++) {
    	cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    int off = 0;
    for (int i = 0; i < n; i++) {
    	if (i == n - 1) {
	    	for (int j = 0; j < 5; j++) cout << off + j + 1 << " ";
	    } else {
	    	for (int j = 0; j < 4; j++) cout << off + j + 1 << " ";
			cout << off + 5 + 1 << " ";
	    }
    	cout << endl;
    	off += 4;
    }

    st[stn++] = 0;
    while (stn > 0) {
    	int x = st[stn - 1];
    	if (deg[x] == 0) {
    		out[on++] = x + 1;
    		stn--;
    	} else {
    		for (int j = 0; j < an; j++) if (r[x][j]) {
    			r[x][j] = 0;
    			r[j][x] = 0;
    			deg[x]--;
    			deg[j]--;
    			st[stn++] = j;
    			break;
    		}
    	}
    }

    for (int i = 0; i < on; i++) cout << out[i] << " ";
    cout << endl;

    return 0;
}
