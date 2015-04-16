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

char s[222222];
int d1[222222], d2[222222];

void setd1(const char * s, int n) {
	int k;
	int l=0, r=-1;
	for(int i = 0; i < n; i++) {
		if(i > r) k = 1;else k = min(d1[l + r - i], r - i);
		while(0 <= i-k && i+k < n && s[i - k] == s[i + k]) k++;
		d1[i] = k;
		if (i + k - 1 > r)
			r = i + k - 1, l = i - k + 1;
	}
}

void setd2(const char * s, int n) {
	int k;
	int l=0, r=-1;
	for (int i = 0; i < n; i++) {
		if(i > r) k = 0;else k = min(d2[l + r - i + 1], r - i + 1);
		while(i + k < n && i - k - 1 >= 0 && s[i+k] == s[i - k - 1]) k++;
		d2[i] = k;
		if(i + k - 1 > r)
			l = i - k, r = i + k - 1;
	}
}

inline int center(int l, int r) {
	return (r + l + 1) / 2;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d\n", &T);
	while (T--) {
		gets(s);
		int l = strlen(s);

		if (l & 1)
			setd2(s, l);
		else
			setd1(s, l);

		int found = 0;
		for (int i = 0; i < l; ++i) {
			if (l & 1) {
				if (d2[center(i + 1, l - i - 1)]*2 >= l-2*i-1 ||
					d2[center(i, l - i - 2)]*2 >= l-2*i-1) {
					found = 1;
					break;
				}
			} else {
				if (d1[center(i + 1, l - i - 1)]*2-1 >= l-2*i-1 ||
					d1[center(i, l - i - 2)]*2-1 >= l-2*i-1) {
					found = 1;
					break;
				}
			}

			if (s[i] != s[l - i - 1]) break;
		}

		puts(found ? "YES" : "NO");
	}

    return 0;
}
