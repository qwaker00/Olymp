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

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	LL a, b, c;
   	cin >> a >> b >> c; 

   	if (b <= a) {
   		LL ans = (c + b - 1) / b;
   		cout << ans << " " << ans << endl;
   		return 0;
   	}

   	LL disk = (c + a - 1) / a;
   	LL right = disk;
   	LL left = (c + b - 1) / b;
   	while (left < right) {
   		LL cont = (left + right) / 2;

   		LL dperc1 = disk / cont;
   		LL dperc2 = dperc1 + 1;
   		LL c2 = disk % cont;
   		LL c1 = cont - c2;
   		if (c1 * min(b, dperc1 * a) + c2 * min(b, dperc2 * a) >= c) {
   			right = cont;
   		} else {
   			left = cont + 1;
   		}
   	}

   	cout << disk << " " << left << endl;
    
    return 0;
}
