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

#define N 5555

int n, l, r;
char s[N];
int f[N], pr[N];

int main() {
    freopen("language.in", "r", stdin);
    freopen("language.out", "w", stdout);

    cin >> n >> l >> r >> s;
    memset(f, 127 + 63, sizeof(f));
    f[0] = 0;
	for (int i = 1; i <= n; i++) {
		int ma = 'a' - 1, mi = 'z' + 1;
		for (int j = i; j > 0; j--) {
			if (s[j - 1] > ma) ma = s[j - 1];
			if (s[j - 1] < mi) mi = s[j - 1];
			if (i - j + 1 >= l && i - j + 1 <= r && f[j - 1] + ma - mi > f[i]) {
				f[i] = f[j - 1] + ma - mi;
				pr[i] = j - 1; 
			}
		}
	}
	if (f[n] < 0)  {
		cout << "NO SOLUTION" << endl;
	} else {
		cout << f[n] << endl;
		vector<string> ans;
		int k = n;
		while (k > 0) {
			s[k] = 0;
			ans.push_back(s + pr[k]);
			k = pr[k];
		}
		cout << ans.size() << endl;
		for (int i = ans.size() - 1; i>=0; i--) cout << ans[i] << endl;
	}

    return 0;
}
