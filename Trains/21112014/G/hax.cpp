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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int pr[1111], pn;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 2; i <= 1000; ++i) {
    	bool prime = true;
    	for (int j = 0; j < pn; ++j) 
    		if (i % pr[j] == 0) {
    			prime = false;
    			break;
	    	}
		if (prime) {
			pr[pn++] = i;
//			cerr << i << " ";
		}
    }
//	cerr << endl;
//	cerr << pn << endl;


	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);

		vector< vector<bool> > a(n, vector<bool>(pn));
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			for (int j = 0; j < pn; ++j)
				while (x % pr[j] == 0) {
					a[i][j] = a[i][j] ^ 1;
					x /= pr[j];
				}
		}

		/*
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < pn; ++j) {
				cout << int(a[i][j]);
			}
			cout << endl;
		}
		*/

		int rank = 0;
		for (int i = 0; i < pn && rank < n; ++i) {
			if (!a[rank][i]) {
				for (int j = rank + 1; j < n; ++j) if (a[j][i]) {
					swap(a[j], a[rank]);
					break;
				}
			}
			if (!a[rank][i]) {
				continue;
			}
			for (int j = rank + 1; j < n; ++j) if (a[j][i]) {
				for (int k = 0; k < pn; ++k) {
					a[j][k] = a[j][k] ^ a[rank][k];
				}
			}
			++rank;
		}

		int pw = n - rank;
		int num[1111], nl = 1;
		memset(num, 0, sizeof(num));
		num[0] = 1;
		while (pw--) {
			int carry = 0;
			for (int i = 0; i < nl; ++i) {
				carry += num[i] * 2;
				num[i] = carry % 10000;
				carry /= 10000;
			}
			if (carry) {
				num[nl++] = carry;
			}
		}
		--num[0];
		int j = 0;
		while (num[j] < 0) {
			num[j] += 10000;
			++j;
		}
		while (nl > 1 && num[nl - 1] == 0) --nl;

		printf("%d", num[nl - 1]);
		for (int j = nl - 2; j >= 0; --j)
			printf("%04d", num[j]);
	    puts("");
	}

    return 0;
}

