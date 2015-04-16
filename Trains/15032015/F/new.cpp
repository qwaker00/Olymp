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

int pr[11111], pn = 0;
int n;
int st[11111], stn = 0;
int bst[11111], bsn = 0;
LD blogs = 0;

const int MOD = 1000000009;

void rec(int mul, int last) {
	if (mul == n) {
		LD logs = 0;
		for (int i = 0; i < stn; ++i) {
			logs += log(pr[stn - i - 1]) * st[i];
		}
		if (bsn == 0 || (bsn != 0 && logs < blogs)) {
			memcpy(bst, st, sizeof(st[0]) * stn);
			bsn = stn;
			blogs = logs;
		}
		return;
	} 
	for (int j = last; ; ++j) {
		if (LL(mul) * (j + 1) > n) break;

		st[stn++] = j;
		rec(mul * (j + 1), j);
		--stn;
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 3; pn < 10000; i += 2) {
    	bool bad = 0;
    	for (int j = 0; j < pn; ++j) if (i % pr[j] == 0) {
    		bad = 1;
    		break;
    	}
    	if (!bad) {
    		pr[pn++] = i;
    	}
    }

	rec(1, 1);

	LL ans = 1;
	for (int i = bsn - 1, pi = 0; i >= 0; --i, ++pi) {
		for (int j = 0; j < bst[i]; ++j)
			ans = (ans * pr[pi]) % MOD;
	} 
	cout << ans << endl;
	
    return 0;
}
