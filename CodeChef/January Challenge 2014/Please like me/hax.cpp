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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    int T;
   	cin >> T;
   	while (T--) {
   		LL L, D, S, C;
   		cin >> L >> D >> S >> C;

   		bool yes = false;
   		for (int i = 1; i < D; ++i) {
   			if (LD(S) * (C + 1) > L * 2) {
   				yes = true;
   				break;
   			}
   			S *= (C + 1);
   		}
   		if (S >= L) yes = true;

   		puts(yes ? "ALIVE AND KICKING" : "DEAD AND ROTTING");
   	}
    
    return 0;
}
