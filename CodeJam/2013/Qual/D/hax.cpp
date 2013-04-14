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

int f[1111111], kk[111], t[111], key[111][111], k, n;

int Calc(int msk, multiset<int>& k) {
	int& v = f[msk];
	if (v != -1) return v;

//	cerr << msk << ":";
//	for (multiset<int>::iterator i = k.begin(); i != k.end(); ++i) cerr << " " <<*i;
//	cerr << endl;


	if (msk + 1 == (1 << n)) return v = 1;
	v = 0;
	for (int i = 0; i < n; ++i)
		if ((msk & (1 << i)) == 0 && k.count(t[i]) > 0) {
			if (f[msk | (1 << i)] == -1) {
				k.erase(k.find(t[i]));
				for (int ii = 0; ii < kk[i]; ++ii) k.insert(key[i][ii]);

				if (Calc(msk | (1 << i), k)) v = 1;

				for (int ii = 0; ii < kk[i]; ++ii) k.erase(k.find(key[i][ii]));
				k.insert(t[i]);
			} else
			if (f[msk | (1 << i)] == 1) v = 1;
		}
	return v;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    int T;
	cin >> T;
	for (int __it = 1; __it <= T; ++__it) {
	    memset(f, -1, sizeof(f));
		
		scanf("%d%d", &k, &n);
//		cout << k << " " << n << endl;
		multiset<int> keys;

		for (int i = 0; i < k; ++i) {
			int x;
			scanf("%d", &x);
//			cout << x << " ";
			keys.insert(x);
		}
//		cout << endl;

		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &t[i], &kk[i]);
//			cout << t[i] << " " << kk[i];
			for (int j = 0; j < kk[i]; ++j) {
				scanf("%d", &key[i][j]);
//				cout << " " << key[i][j];
			}
//			cout << endl;
		}
		Calc(0, keys);

		printf("Case #%d: ", __it);

		if (f[(1 << n) - 1] != 1) {
			puts("IMPOSSIBLE");
		} else {
			int msk = 0, cnt = 0;
            vector<int> ans;
			for (int i = 0; i < n; ++i)	{
				for (int j = 0; j < n; ++j)
					if ( (msk & (1 << j)) == 0 && f[msk | (1 << j)] == 1) {
                        ans.push_back(j);
						printf("%d", j + 1);
						if (i + 1 != n) putchar(' ');
						msk |= (1 << j);
						++cnt;
						break;
					}
			}
			puts("");
			if (cnt != n) throw 1;
		}
	}    
    
    return 0;
}
