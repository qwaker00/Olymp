#include <stdio.h>
#include <iostream>
#include <math.h>
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
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

int main() {

	ll H, L, W;
	cin >> H >> L >> W;
	if (((L - W) &1ll) || (L-W) < 0ll) {
		cout << "impossible" << endl;
		return 0;
	}
	ll X = (L - W) / 2ll;
	if ((X-W)&1ll) {
		cout << "impossible" << endl;
		return 0;
	}	
	ll y = (X - W) / 2ll;
	
	ll p = W;
	ll q = H + y;
	ll r = y;


	ll mc = (q - 2ll * r) / 2ll;
	mc = min(mc, p/2ll);

	if (mc < 0ll) {
		cout << "impossible" << endl;
		return 0;
	}

	ll a = p - 2ll * mc;
	ll b = q - 2ll * r - 2ll * mc;

	ll c = mc;
	ll d = c + r;

	if (a < 0 || b < 0 || c < 0 || d < 0) {
		cout << "impossible" << endl;
		return 0;
	}
	cout << a << " " << b << " " << c << " " << d << endl;
	return 0;
                 
}
