#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long long LL;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;


LL mulm(LL x, LL y, LL m) {
	LL res = 0;
	while (y) {
		if (y & 1) res = (res + x) % m;
		x = (x + x) % m;
		y >>= 1;
	}
	return res;
}

LL powm(LL x, LL y, LL m) {
	LL res = 1;
	while (y) {
		if (y & 1) res = mulm(res, x, m);
		x = mulm(x, x, m);
		y >>= 1;
	}
	return res;
}

ll w[66];

int main() {
	//freopen("in", "r", stdin);

	while (true) {
		int n; ll q, r, c;
		scanf("%d", &n);
		if (n == 0) break;
		scanf("%I64d%I64d", &q, &r);

		ll invr = powm(r, q - 2, q);
		for (int i = 0; i < n; ++i) {
			scanf("%I64d", w + i);
			w[i] = mulm(w[i], invr, q);
		}
        scanf("%I64d", &c);
		c = mulm(c, invr, q);
	    
	    ll sm = w[0];
	    for (int i = 1; i < n; ++i) {
	    	assert(w[i] > sm);
	    	sm += w[i];
	    }
		reverse(w, w + n);

		vector<ll> ans;
		for (int i = 0; i < n; ++i) {
			if (c >= w[i]) {
				ans.push_back(mulm(w[i], r, q));
				c -= w[i]; 
			}
		}

		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i) printf("%I64d ", ans[i]);
		puts("");
	}
		
	return 0;
}
