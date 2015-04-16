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

const int SH = 20;
LL f[22][44][2][2];
int dig[] = {4, 7, 3, 5, 6, 8};

LL solve(LL x) {
	int d[111], dn = 0;
	while (x > 0) {
		d[dn++] = x % 10;
		x /= 10;
	}
//	reverse(d, d + dn);

	memset(f, 0, sizeof(f));
	f[0][SH][1][0] = 1;
	for (int i = 0; i < dn; ++i) {
		for (int j = 0; j < 44; ++j) {
			for (int e = 0; e < 2; ++e) 
				for (int any = 0; any < 2; ++any)
				if (f[i][j][e][any]) {
					if (!any) {
						f[i + 1][j][0][0] += f[i][j][e][any];
					}
					for (int di = 0; di < 6; ++di) {
						if (e && dig[di] > d[dn - i - 1]) continue;
						if (di < 2)
							f[i + 1][j + 1][e && dig[di] == d[dn - i - 1]][1] += f[i][j][e][any];
						else
							f[i + 1][j - 1][e && dig[di] == d[dn - i - 1]][1] += f[i][j][e][any];
					}
				}
		}
	}
	LL ans = 0;
	for (int i = SH; i < 44; ++i) 
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				ans += f[dn][i][j][k];
	return ans;
}


bool good(int x) {
	int e1 = 0, e2 = 0;
	while (x) {
		int d = x % 10;
		if (d == 4 || d== 7) {
			e1++;
		} else
		if (d == 3 || d == 5 || d == 6 || d == 8) {
			e2++;
		} else return false;
		x /= 10;
	}
	return e1 >= e2;
}


int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

/*    int ans = 0;
    for (int i = 1; i <= 100000; ++i) {
    	ans += good(i);
    	int t = solve(i) - 1;
    	if (ans != t) {
    		cerr << i << endl;
    		break;
    	}
    }
*/
    int T;
	cin >> T;   	
	while (T--) {
		LL A, B;
		cin >> A >> B;
		cout << solve(B) - solve(A - 1) << endl;
	}


    return 0;
}
