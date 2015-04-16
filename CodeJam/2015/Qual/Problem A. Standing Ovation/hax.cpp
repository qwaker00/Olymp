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
		int sum = 0;
		int ans = 0;
		string s;
		cin >> n >> s;
		for (int i = 0; i <= n; ++i) {
			if (sum < i) {
				ans += i - sum;
				sum += i - sum;
			}
			sum += s[i] - '0';			
		}
		__it++;
		cout << "Case #" << __it << ": " << ans << endl;
	}
	   	
    
    return 0;
}
