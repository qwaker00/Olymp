#include <cstdio>
#include <algorithm>
#include <iostream>
const int N = 30000333;

int n, m, k, a, b, c, A[N], B[N], C[N];

int main() {
	freopen("minima.in", "r", stdin);
	freopen("minima.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d%d", &a, &b, &c);

	for (int i = 0; i < k; ++i) {
		scanf("%d", &A[i]);
		}
	for (int i = k; i < n; ++i) {
		A[i] = a * A[i - 2] + b * A[i- 1] + c;
	}
	for (int i = 0; i < n; ++i) {
		if (i % m == 0) {
			B[i] = A[i];		
		} else {
			B[i] = std::min(B[i - 1], A[i]);
		}
	}
	long long ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (i + 1 == n-1 || (i + 1) % m == 0) {
			C[i] = A[i];
		}else {
			C[i] = std::min(C[i+1], A[i]);
		}
		if (i + m <= n) {
			ans += std::min(C[i], B[i + m - 1]);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}
