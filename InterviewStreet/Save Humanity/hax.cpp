#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

vector<size_t> p1, p2;
string P, V;
int T;

vector<size_t> ZFunc(const string& s) {
	size_t n = s.length();
	vector<size_t> z(n);
	for (size_t i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)	z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> T;
	while (T--) {
		cin >> P >> V;
		p1 = ZFunc(V + "#" + P);
		reverse(P.begin(), P.end());
		reverse(V.begin(), V.end());
		p2 = ZFunc(V + "#" + P);
		int vl = V.length(), pl = P.length();
		int fin = pl - vl + 1;
		for (int i = 0; i < fin; ++i) {
			if ( (p1[i + vl + 1] >= vl) ||
			     (p1[i + vl + 1] + 1 + p2[1 + pl - i] >= vl)
			   )
			{
				cout << i << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
