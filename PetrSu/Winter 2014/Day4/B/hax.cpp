#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <vector>

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
using namespace std;

#define N 222222

struct Tp{
	int x, y, z;
	bool operator<(const Tp& t)const{
		return z > t.z;
	}
} a[555555];
int n, m;
LL sum = 0;
int pr[N];

int fs(int x) {
	if (x != pr[x]) pr[x] = fs(pr[x]);
	return pr[x];
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) pr[i] = i;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		sum += a[i].z;
	}
	sort(a, a + m);
	for (int i = 0; i < m; ++i) {
		if (a[i].z <= 0) break;
		int x = fs(a[i].x);
		int y = fs(a[i].y);
		if (x != y) {
			pr[x] = y;
			sum -= a[i].z;
		}
	}
	cout << sum << endl;	
	
//	cerr << "Time: " << clock() << endl;
	return 0;
}