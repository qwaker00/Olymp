#include <bits/stdc++.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
	for (int __case = 1; __case <= T; ++__case) {
		int n;
		cin >> n;

		vector< pair<int, vector<int> > > bor;
		int ans = 0;
		bor.push_back({0, vector<int>(26, 0)});

		while (n--) {
			string s;
			cin >> s;
			int cur = 0;
			int add = s.length();
			for (int i = 0; i < (int)s.length(); ++i) {
				assert(s[i] >= 'a' && s[i] <= 'z');
				if (bor[cur].second[s[i] - 'a'] == 0) {
					bor[cur].second[s[i] - 'a'] = bor.size();
					bor.push_back({0, vector<int>(26, 0)});
				}
				cur = bor[cur].second[s[i] - 'a'];
				if (i + 1 < add && bor[cur].first == 0) {
					add = i + 1;
				}
				++bor[cur].first;
			}
			ans += add;
		}
		cout << "Case #" << __case << ": " << ans << endl;
	}

    return 0;
}
