#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

const int maxlen = 1000111;
int p[maxlen], cnt[maxlen], c[maxlen], n;
char s[maxlen];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    gets(s);
    n = strlen(s);
	memset (cnt, 0, 256 * sizeof(int));
	for (int i=0; i<n; ++i) ++cnt[s[i]];
	for (int i=1; i<256; ++i) cnt[i] += cnt[i-1];
    for (int i=0; i<n; ++i) p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i=1; i<n; ++i) {
		if (s[p[i]] != s[p[i-1]])  ++classes;
		c[p[i]] = classes-1;
	}
	int pn[maxlen], cn[maxlen];
	for (int h=0; (1<<h)<n; ++h) {
		for (int i=0; i<n; ++i) {
			pn[i] = p[i] - (1<<h);
			if (pn[i] < 0)  pn[i] += n;
		}
		memset (cnt, 0, classes * sizeof(int));
		for (int i=0; i<n; ++i)	++cnt[c[pn[i]]];
		for (int i=1; i<classes; ++i) cnt[i] += cnt[i-1];
 		for (int i=n-1; i>=0; --i) p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (int i=1; i<n; ++i) {
			int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
			if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2]) ++classes;
			cn[p[i]] = classes-1;
		}
		memcpy (c, cn, n * sizeof(int));
	}

	for (int i = 0; i < n; ++i) {
		cout << s + p[i] << endl;
	}
    
    return 0;
}
