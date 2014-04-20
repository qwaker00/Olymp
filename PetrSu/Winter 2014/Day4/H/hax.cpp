#include <iostream>
#include <cstdio>
#include <string>
#include <assert.h>
#include <queue>
#include <algorithm>

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
using namespace std;

const int N = 1000111;

int n, k;
int a[N];

priority_queue< pair<int, int> > q;

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	
 	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	bool done = false;
	for (int i = 0; i < n; ++i) {
		q.push(make_pair(-a[i], i));
		if (i + 1 >= k) {
			while (q.top().second <= i - k) q.pop();

			if (-q.top().first < a[i - k + 1]) {
				sort(a + i - k + 1, a + i + 1);
				done = true;
				break;
			}
		}
	}
	if (!done) {
		sort(a + n - k, a + n);
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	puts("");
	
	return 0;
}
