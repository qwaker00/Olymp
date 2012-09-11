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

int n, n1, n2;
LL l, r, w[33], v[33];

struct Tp {
	int m;
	LL w, v;

	bool operator<(const Tp& B)const {
		return w < B.w;
	}
} a[211111], b[211111], t;
int an = 0, bn = 0;
int ans[211111][22], outi, outj;
LL out;

int main() {
    freopen("dowry.in", "r", stdin);
    freopen("dowry.out", "w", stdout);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    n1 = n >> 1;
    for (int i = 0; i < (1 << n1); ++i) {
    	LL sumw = 0, sumv = 0;
    	for (int j = 0; j < n1; j++) if (i & (1 << j)) {
    		sumw += w[j];
    		sumv += v[j];
    	}
    	a[an].m = i;
    	a[an].w = sumw;
    	a[an++].v = sumv;
    }
    sort(a, a + an);

    n2 = n - n1;
    for (int i = 0; i < (1 << n2); ++i) {
    	LL sumw = 0, sumv = 0;
    	for (int j = 0; j < n2; j++) if (i & (1 << j)) {
    		sumw += w[j + n1];
    		sumv += v[j + n1];
    	}
    	b[bn].m = i;
    	b[bn].w = sumw;
    	b[bn++].v = sumv;
    }
    sort(b, b + bn);

    for (int i = bn - 1; i >= 0; i--) {
    	ans[i][0] = i;
    	for (int j = 1; j <= 16; j++) {
    		if (b[ans[i][j - 1]].v >= b[ans[i + (1 << (j - 1))][j - 1]].v) {
    			ans[i][j] = ans[i][j - 1];
    		} else {
	    		ans[i][j] = ans[i + (1 << (j - 1))][j - 1];
	    	}
    	}
    }    

    for (int i = 0; i < an; i++) {
    	t.w = l - a[i].w;
    	int p = lower_bound(b, b + bn, t) - b;
    	if (p >= bn) continue;
    	if (a[i].w + b[p].w > r) break;

    	int off = 0, step = 16, best = ans[p][0];
    	while (step >= 0) {
    		if (p + off + (1 << step) < bn && a[i].w + b[p + off + (1 << step)].w <= r) {
    			if (b[ans[p + off + 1][step]].v > b[best].v) {
    				best = ans[p + off + 1][step];
    			}
    			off += (1 << step);
    		}
    		--step;
    	}
    	if (b[best].v + a[i].v > out) {
    		out = b[best].v + a[i].v;
    		outi = a[i].m;
    		outj = b[best].m;
    	}
    }
    vector<int> outv;
//    cout << out << endl << outi << endl << outj << endl;
    for (int i = 0; i < n1; i++) if (outi & (1 << i)) outv.push_back(i + 1);
    for (int i = 0; i < n2; i++) if (outj & (1 << i)) outv.push_back(i + 1 + n1);
    cout << outv.size() << endl;
    for (int i =0 ; i < outv.size(); i++) cout << outv[i] << " ";
    if (outv.size()) cout << endl;

    return 0;
}
