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

string f[55][55];

inline bool eq(char x, char y) {
	return x == y || x == '?';
}

void maximize(string& a, const string& b) {
	if (b.length() > a.length() ||
		(a.length() == b.length() && b > a))
		{
			a = b;
		}
		
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    string s;
	cin >> s;
	int n = s.length();

	for (int l = 0; l < n; ++l) {
		for (int i = 0; i + l < n; ++i) {
			int j = i + l;

			// number
			{
				bool ok = true;
				string num;
				for (int k = i; k <= j; ++k) {
					if (s[k] >= '0' && s[k] <= '9') {
						if (s[k] == '0' && k == i && i != j) {
							ok = false;
							break;
						}
						num += s[k];
					} else
					if (s[k] == '?') {
						num += '9';
					} else {
						ok = false;
						break;
					}
				}
				if (ok) {
					maximize(f[i][j], num);
				}
			}
			if (l >= 5) {
				// L
				if (eq(s[i], 'L') && eq(s[i + 1], '(') && eq(s[j], ')')) {
					for (int k = i + 3; k + 1 < j; ++k) 
						if (eq(s[k], ',') && !f[k + 1][j - 1].empty()) {
							maximize(f[i][j], f[i + 2][k - 1]);
						}
				}
				// R
				if (eq(s[i], 'R') && eq(s[i + 1], '(') && eq(s[j], ')')) {
					for (int k = i + 3; k + 1 < j; ++k) 
						if (eq(s[k], ',') && !f[i + 2][k - 1].empty()) {
							maximize(f[i][j], f[k + 1][j - 1]);
						}
				}
			}
		}
	}

	if (f[0][n - 1].empty())
		puts("invalid");
	else
		cout << f[0][n - 1] << endl;
	
    return 0;
}
