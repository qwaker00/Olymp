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
#include <cassert>
#include <unordered_map>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

char s[55][22];
int n, m;
int eda[666666];


struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ (std::hash<U>()(x.second) << 3);
  }
};

unordered_map< pair<int, ULL>, LD, pairhash> mem;

int ed(int msk) {
	return eda[msk >> 16] + eda[msk & 65535];
}
int ed(ULL msk) {
	return eda[(msk >> 48) & 65535]
		   + eda[(msk >> 32) & 65535] 
		   + eda[(msk >> 16) & 65535] 
	       + eda[msk & 65535];
}

LD rec(int mask, ULL maskw, LD prob) {
	if (prob < 1e-12) return 0;
	if ((maskw & (maskw - 1)) == 0) return prob * ed(mask);
	if (mem.count(make_pair(mask, maskw))) return mem[make_pair(mask, maskw)];

	LD ans = 0;
	LD p1 = LD(1) / (m - ed(mask));
	for (int j = 0; j < m; ++j) if (((1 << j) & mask) == 0) {
//		map<char, ULL> newmsk;
		ULL newmsk[56];
		memset(newmsk, 0, sizeof(newmsk));
		for (int i = 0; i < n; ++i) if ((1ull << i) & maskw) {
			newmsk[s[i][j]] |= 1ull << i;
		}
		for (int i = 1; i < 'Z' - 'A' + 'z' - 'a' + 2; ++i) {
//		for (const auto& i : newmsk) {
//			const ULL v = i.second;
			const ULL v = newmsk[i];
			if (v) {
				const LD p2 = LD(ed(v)) / ed(maskw);
				ans += rec(mask | (1 << j), v, prob * p1 * p2);
			}
		}
	}
	return mem[make_pair(mask, maskw)] = ans;
//	return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 1; i < 66666; ++i) eda[i] = eda[i & (i - 1)] + 1;

    cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		m = strlen(s[i]);
		for (int j = 0; j < m; ++j) {
			if (s[i][j] >= 'a' && s[i][j] <= 'z') 
				s[i][j] = s[i][j] - 'a' + 1;
			else
				s[i][j] = s[i][j] - 'A' + 'z' - 'a' + 2;
		}
	}

	cout.precision(18);
	cout << fixed;
	cout << double(rec(0, (1ull << n) - 1, 1)) << endl;
	cerr << clock() << endl;

    return 0;
}
