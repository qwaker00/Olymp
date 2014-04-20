#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, m;
string s[111];

bool solve() {
	bool found = false;
	for (int i= 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) if (s[i][j] != '.') {
			if (found) return false;
			
			found = true;
			if (s[i][j] == '-') {
				for (int k = 0; j + k < m && s[i][j + k] == '-'; ++k)
					s[i][j + k] = '.';
			} else
			if (s[i][j] == '|') {
				for (int k = 0; i + k < n && s[i + k][j] == '|'; ++k)
					s[i + k][j] = '.';
			} else
			if (s[i][j] == '\\') {
				for (int k = 0; i + k < n && j + k < m && s[i + k][j + k] == '\\'; ++k)
					s[i + k][j + k] = '.';
			} else
			if (s[i][j] == '/') {
				for (int k = 0; j - k >= 0 && i + k < n && s[i + k][j - k] == '/'; ++k)
					s[i + k][j - k] = '.';
			} else
				return false;
		}
	}
	return found;
}

int main() {
//    freopen("PSEUDO.in", "r", stdin);
//    freopen("PSEUDO.out", "w", stdout);

    int T;
	cin >> T;	
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		puts(solve() ? "CORRECT" : "INCORRECT");
	}
    
    return 0;
}
