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

#define N 100011

int h[4*N], hn;
struct Tp {
	int x, y;
} a[N];
struct Tb {
	int x, y, d1, d2;
} b[N];
set<int> X[4*N], Y[4*N], D1[4*N], D2[4*N];
int n;

bool Check(set<int>& S, int l, int r) {
	set<int>::iterator j = S.find(l);
	if (r < l) {
		return *(--j) == r;
	} else {
		return *(++j) == r;
	}		
}

int main() {
    freopen("queen2.in", "r", stdin);
    freopen("queen2.out", "w", stdout);
//    cerr << sizeof(X) + sizeof(Y) + sizeof(D1) + sizeof(D2) << endl;

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
    	scanf("%d%d", &a[i].x, &a[i].y);
    	h[hn++] = a[i].x;
    	h[hn++] = a[i].y;
    	h[hn++] = a[i].x + a[i].y;
    	h[hn++] = a[i].x - a[i].y;
    }
    h[hn++] = 0;

    sort(h, h + hn);
    hn = unique(h, h + hn) - h;

    for (int i = 0; i <= n; ++i) {
    	b[i].x = lower_bound(h, h + hn, a[i].x) - h;
    	b[i].y = lower_bound(h, h + hn, a[i].y) - h;
    	b[i].d1 = lower_bound(h, h + hn, a[i].x + a[i].y) - h;
    	b[i].d2 = lower_bound(h, h + hn, a[i].x - a[i].y) - h;
		X[b[i].x].insert(a[i].y);
		Y[b[i].y].insert(a[i].x);
		D1[b[i].d1].insert(a[i].x);
		D2[b[i].d2].insert(a[i].x);
    }

    int x = 0, y = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
//    	for (set<int>::iterator j = D1[3].begin(); j != D1[3].end(); ++j)
  //  		cout << *j << " ";
    //		cout << endl;

    	Tb B = b[i - 1];
    	if (x == a[i].x && Check(X[B.x], y, a[i].y) || 
    	    y == a[i].y && Check(Y[B.y], x, a[i].x) ||
    	    x + y == a[i].x + a[i].y && Check(D1[B.d1], x, a[i].x) ||
    	    x - y == a[i].x - a[i].y && Check(D2[B.d2], x, a[i].x)
    	   )
    	{
			X[B.x].erase(y);
			Y[B.y].erase(x);
			D1[B.d1].erase(x);
			D2[B.d2].erase(x);
    		x = a[i].x;
    		y = a[i].y;
			ans = i;
    	} else break;
    }
    cout << ans << endl;

    return 0;
}
