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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


bool check(const char * s, int n) {
	int gamma = 0;
	for (int i = 0; i < n; ++i) {
		int k = 1;
		while (i + k + k <= n) {
			if (strncmp(s + i, s + i + k, k) == 0) {
				break;
			}
			++k;
		}
		if (i + k + k > n) {
			++gamma;
		}
		if (gamma * 2 < (i + 1)) return false;
	}
	return true;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    char s[111];
   	for (int n = 25; n <= 25; ++n) {
   		
	   	int c = 0;
   		cout << "For length: " << n << endl;
   		for (int i = 0; i < (1 << n); ++i) {
   			int x = i;
   			for (int j =0 ; j < n; ++j) {
   				s[j] = '0' + (x & 1);
   				x >>= 1;
   			}
   			s[n] = 0;

   			if (check(s, n)) {
   				puts(s);
   				++c;
   			}
   		}
   		cout << "Count: " << c << endl;

   		puts("");
   		puts("");
   	}
   	

    return 0;
}
