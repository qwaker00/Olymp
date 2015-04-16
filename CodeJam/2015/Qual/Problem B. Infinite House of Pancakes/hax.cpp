#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
	
	int T, __it = 0;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int mx = 0;
		for (int i =0; i < n; ++i) {
			cin >>a[i];
			if (a[i] > mx) mx = a[i];
		}

		int ans = 2e9;
		for (int t = 1; t <= mx; ++t) {
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				sum += (a[i] - 1) / t;
			}
			if (sum + t < ans) ans = sum + t;
		}

		__it++;
		cout << "Case #" << __it << ": " << ans << endl;
	}
	   	
    
    return 0;
}
