#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> a;

int main() {
	for (int i = 1; ; ++i) {
		ll x = ll(3) * ll(i) * ll(i) - ll(3) * ll(i) + 1; 
		if (x > 1e12) break;
		a.push_back(x);
	}
	
	while (true) {
		ll x; cin >> x;
		if (x == 0) break;
		int md = x % 6;

		if (md == 0) {
			puts("6");
		} else if (md == 1) {
			int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
			if (a[pos] == x) {
				puts("1");
			} else {
				puts("7");
			}
		} else if (md == 2) {
			int l = 0;
			int r = a.size() - 1;

			bool cool = false;
			while (l <= r) {
				while (l <= r && a[l] + a[r] > x) --r;
				if (a[l] + a[r] == x) {
					cool = true;
					break;
				}
				++l;
			}
			if (cool) puts("2");
			else puts("8");
		} else {
			printf("%d\n", md);
		}
	}

	
	return 0;
}