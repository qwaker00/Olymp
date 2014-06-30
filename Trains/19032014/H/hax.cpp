#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i) {
		cout << i <<  " " << i + 1 << "  " << 1 << endl;
		--m;
	}
	int inf = 1000002;
	for (int i = 1; i <= n && m; ++i) {
		for (int j = i + 2; m && j <= n; ++j) {
			cout << i << " " << j << " " << inf - i * 2 << endl;
			--m;
		}
	}


	return 0;
}
