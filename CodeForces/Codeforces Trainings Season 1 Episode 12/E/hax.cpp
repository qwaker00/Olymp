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

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

	for (int s = 2; s <= 100; ++s) {
		double best = -100;
		int who = -1;
		for (int x = 1; x <= s - x; ++x) {
			int y = s - x;
			double cand = sin(double(x)) + sin(double(y));
			if (cand > best) {
				best = cand;
				who = x;
			}
		}

		cout << s << ": " << who << endl;
	}
    
    return 0;
}
