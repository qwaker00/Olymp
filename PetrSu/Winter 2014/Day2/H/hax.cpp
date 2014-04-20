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

pair<int, int> st[2222*2222];
int stn;
int n, k;
char s[6222];
int z[6222];

int zzz[2222][6444];

inline bool str_less(const pair<int, int>& a, const pair<int, int>& b) {
	int t = min(zzz[a.first][b.first + n + 1], min(b.second, a.second));
	return ((t == a.second && t < b.second) || (t < a.second  && t < b.second && s[a.first + t] < s[b.first + t]));
}
inline bool str_less_eq(const pair<int, int>& a, const pair<int, int>& b) {
	int t = min(zzz[a.first][b.first + n + 1], min(b.second, a.second));
	return ((t == a.second && t < b.second) || (t == a.second && t == b.second) || (t < a.second  && t < b.second && s[a.first + t] < s[b.first + t]));
}

void Z(const char * s, int n, int* z) {
	int l = 0, r = -1;
	z[0] = 0;
	for (int i = 1; i < n; ++i) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);else z[i] = 0;
		while (i + z[i] < n && s[ z[i] ] == s[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}

int f[2][2222];
bool ff[2222][2222];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    gets(s);
    n = strlen(s);
    memcpy(s + n, s, n);
    scanf("%d", &k);

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		st[stn++] = make_pair(i, j + 1);
    	}
    	Z((string(s + i, n) + "$" + s).c_str(), n + 1 + n + n, zzz[i]);
    }
    sort(st, st + stn, str_less);
//    cerr << clock() << endl;

//    for (int i = 0; i < stn; ++i) {
//    	cerr << string(s + st[i].first, st[i].second) << endl;
//    }

    int left = 0, right = stn - 1;
    while (left < right) {
//    	cerr << "Left: " << left << ", Right: " << right << endl;
    	int center = (left + right) >> 1;
    	int spatternl = st[center].second;
    	char * spattern = s + st[center].first;

    	string prez = string(spattern, spatternl) + "$" + string(s, n + n);
    	Z(prez.c_str(), prez.length(), z);

		bool ok = false;
    	int iters = n * 5 / k;
    	for (int it = 0; it < iters; ++it) {
    		int delta = rand() % n;
    		char * ss = s + delta;			
			memset(f[0], 0, sizeof(f[0][0]) * (n + 3));
			memset(f[1], 0, sizeof(f[0][0]) * (n + 3));
			f[0][0] = 1;
			int * zz = z + spatternl + 1 + delta;
			for (int j = 0; j < k; ++j) {
				for (int i = 0; i < n; ++i) if (f[0][i]) {
					int ll = zz[i];
					if (ll < spatternl && ss[i + ll] < spattern[ll]) ll = n - i;
					if (ll > 0) {
						f[1][i + 1] += 1;
						f[1][i + ll + 1] -= 1;
					}
				}
				int sum = 0;
				for (int i = 0; i <= n; ++i) {
					sum += f[1][i];
					f[0][i] = sum > 0;
					f[1][i] = 0;
				}
			}	    	             
			if (f[0][n]) ok = true;
			if (ok) break;
    	}
    	if (ok)
			right = center;else
			left = center + 1;
    }

    pair<int, int> pattern = st[left];
    //cerr << string(s + st[left].first , st[left].second) << endl;

    while (true) {
    	int spatternl = st[left].second;
    	char * spattern = s + st[left].first;
    	string prez = string(spattern, spatternl) + "$" + string(s, n + n);
    	Z(prez.c_str(), prez.length(), z);
		int delta = rand() % n;
		char * ss = s + delta;			
		ff[0][0] = 1;
		int * zz = z + spatternl + 1 + delta;
		for (int j = 0; j < k; ++j) {

//			for (int i = 0; i < n; ++i) cerr << ff[j][i] << " ";
//			cerr << endl;

			for (int i = 0; i < n; ++i) if (ff[j][i]) {
				int ll = zz[i];
				if (ll < spatternl && ss[i + ll] < spattern[ll]) ll = n - i;
				if (ll > 0) {
					f[1][i + 1] += 1;
					f[1][i + ll + 1] -= 1;
				}
			}
			int sum = 0;
			for (int i = 0; i <= n; ++i) {
				sum += f[1][i];
				ff[j + 1][i] = sum > 0;
				f[1][i] = 0;
			}
		}
		if (ff[k][n]){
			//cerr << "Here" << endl;
			vector<int> ans;
			int last = n;
			for (int j = k; j > 0; --j) {
				for (int i = last - 1; i >= 0; --i) {
					if (ff[j - 1][i] && str_less_eq(make_pair((i + delta) % n, last - i), pattern)) {
						ans.push_back((i + delta) % n);
						last = i;
						break;
					}
				}
			}
			sort(ans.begin(), ans.end());
			for (int i = 0; i < (int)ans.size(); ++i) {
				printf("%d ", ans[i] + 1);
			}
			puts("");
			return 0;
		}
	}

	puts("oops");

    return 0;
}
