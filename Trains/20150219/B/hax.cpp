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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const double PI = 3.1415926535897932384626433832795;
template<typename T>
T sqr(T x) { return x * x; }

using namespace std;

inline ll getsum(const vector<ll>& s, int l, int r) {
	const int n = s.size();
	l = ((l % n + n) % n);
	r = ((r % n + n) % n);
	if (l <= r) 
		return s[r] - ((l == 0) ? 0 : s[l - 1]);
	return s.back() - (s[l - 1] - s[r]);
}

vector<ll> expand(const vector<ll>& a, int maxx, int x) {
 	 const int n = a.size();
	 vector<ll> ans(a);
	 vector<ll> s(a);
	 for (int i = 1; i < n; ++i) s[i] += s[i - 1];
 	 ll ts = s.back();

 	 int c = maxx - x - 1;
 	 if (c > 0) {
 	 	 int c1 = c / n;
 	 	 int c2 = c % n;
	 	 for (int i = 0; i < n; ++i) {
 	 		ans[i] += ts * c1;
 	 		if (c2 > 0)
 	 			ans[i] += getsum(s, i - c2, i - 1);
 		 }
 	 }
 	 c = x;
 	 if (c > 0) {
 	 	 int c1 = c / n;
 	 	 int c2 = c % n;
	 	 for (int i = 0; i < n; ++i) {
 	 		ans[i] += ts * c1;
 	 		if (c2 > 0)
 	 			ans[i] += getsum(s, i - c2, i - 1);
 		 }
 	 }
 	 return ans;
}

vector<ll> solve1(int x, int a, int n) {
	vector<ll> A(n, 0);
	A[0] = 1;
	return expand(A, x, a);
}

vector<ll> solve2(int x, int y, int a, int b, int n) {
	vector<ll> A = solve1(x, a, n);
	return expand(A, y, b);
}

vector<ll> solve3(int x, int y, int z, int a, int b, int c, int n) {
	vector<ll> A = solve2(x, y, a, b, n);
	return expand(A, z, c);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int x, y, z, a, b, c, n;
	cin >> x >> y >> z >> a >> b >> c >> n;

	vector<ll> A = solve3(x, y, z, a, b, c, n);
	for (int i = 0; i < A.size(); ++i)
		cout << A[i] << " ";
	cout << "\n";
		
    return 0;
}
