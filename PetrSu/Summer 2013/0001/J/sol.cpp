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

const int N = 1000111;

int f[N];

vector<int> p;
vector<ll> p2;

vector<ll> dels;

int calc(ll x) {
	if (x == 0) return 1;

	vector<int> ps;
	ps.reserve(100);

	if (x >= N) {
		for (int i = 0; i < p.size(); ++i) {
			if (p2[i] > x) break;

			if (!(x % p[i])) {
				do {
					x /= p[i];
					ps.push_back(p[i]);
				} while (!(x % p[i]));

				if (x < N) break;
			}
		}
	}

	if (x < N) {
		while (f[x]) {
			ps.push_back(f[x]);
			x /= f[x];
		}
	}
	if (x > 1) ps.push_back(x);

	sort(ps.begin(), ps.end());

	int ans = 1;
	int cnt = 1;
	ps.push_back(-1);
	for (int i = 1; i < ps.size(); ++i)
		if (ps[i] != ps[i - 1]) {
			ans *= (cnt + 1);
			cnt = 1;
		} else {
			++cnt;
		}
	return ans;
}

int main() {
	freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);

	
	for (int i = 2; i < N; ++i)
		if (!f[i]) {
			p.push_back(i);
			p2.push_back(ll(i) * ll(i));
			for (int j = i + i; j < N; j += i)
				f[j] = i;
		}			

	ll n; cin >> n;
 	for (ll i = 1; i * i <= n; ++i)
 		if (!(n % i)) {
 			dels.push_back(i);
 			if (i * i != n) dels.push_back(n / i);
 		}

	ll ans = 0;
	for (int i = 0; i < dels.size(); ++i) ans += calc((n / dels[i]) - 1);

	cout << ans << endl;
		
	return 0;
}
