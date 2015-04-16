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

void one(int n) {
	int c = 0;
	for (int len = 2; len * (len + 1) <= 2 * n; ++len) {
		int s = n - (len * (len + 1)) / 2;
		if (s % len == 0) {
			++c;
			cerr << len << " ";
		}
	}
	cerr << endl;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
	
	one(21);

	set<int> was;
	int n = 1;
	while (1) {
		int c = 0;
		vector<int> l;
		for (int len = 2; len * (len + 1) <= 2 * n; ++len) {
			int s = n - (len * (len + 1)) / 2;
			if (s % len == 0) {
				++c;
				l.push_back(len);
			}
		}
		if (!was.count(c)) {	
			was.insert(c);
			cerr << c << ": " << n << ", len: ";
			for (int j = 0; j < l.size(); ++j)
				cerr << l[j] << ", ";
			cerr << "\n";
		}
		++n;
	}
    
    return 0;
}
