#include <cstdio>
#include <algorithm>

const int N = 111111;
int S[N+N], S2[N+N];
int pos[N];
int n, x, h[N], hn, a[N];

void add(int* S, int x, int y) {
	while (x < N+N) {
		S[x] += y;
		x = (x | (x - 1)) + 1	;
	}
}

int sum(int* S, int x) {
	int s = 0;
	while (x) {
		s += S[x];
	 	x = x & (x - 1);	
	}
	return s;
}

int main() {
	freopen("mtf.in", "r", stdin);
	freopen("mtf.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		h[hn++] = a[i]; 
	}
	std::sort(h, h + hn);
	hn = std::unique(h, h + hn) - h;

	for (int i = 1; i <= 100000; ++i) {
		pos[i] = i + N;
		add(S, pos[i], 1);
	}
	int ptr = N;
	for (int i= 0; i < n; ++i) {
		int x = std::lower_bound(h, h + hn, a[i]) - h + 1;
		if (sum(S2, x) - sum(S2, x - 1) == 0) {
			printf("%d ", sum(S2, hn) - sum(S2, x) + a[i]);
			add(S2, x, 1);
		} else {
			printf("%d ", sum(S, pos[x]));
		}
		add(S, pos[x], -1);
		pos[x]= ptr;
		add(S, pos[x],1);
		--ptr;
	}
	puts("");
	return 0;
}
