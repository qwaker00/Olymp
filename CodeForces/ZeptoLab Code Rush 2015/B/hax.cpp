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

typedef long long ll;
using namespace std;

int a[4444], nn;

pair<ll, ll> calc(int x) {
	if (x + x + 1 <= nn) {
		pair<ll, ll> p1 = calc(x + x);
		pair<ll, ll> p2 = calc(x + x + 1);
		ll v = max(p1.second, p2.second);
		return {p1.first + p2.first + (v - p1.second) + (v - p2.second), v + a[x]};
	}
	return {0, a[x]};
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n;
	cin >> n;
	nn = ((1 << (n + 1)) - 1);
	for (int i = 2; i <= nn; ++i) {
		cin >> a[i];
	}
	pair<ll, ll> ans = calc(1);
	cout << ans.first << endl;
    
    return 0;
}
