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

int n, a[1111], b[1111], m;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    cin >> n;
    for (int i =0 ; i < n; ++i) {
    	cin >> a[i];
    }
    sort(a, a + n);
    for (int i=  0; i < n; ++i) {
    	int best = m;
    	for (int j = 0; j < m; ++j) if (a[i] >= b[j] && (best == m || b[best] > b[j]))
    		best = j;
		++b[best];
        if (best == m) {
        	++m;
        }
    }
    cout << m << endl;

    return 0;
}
