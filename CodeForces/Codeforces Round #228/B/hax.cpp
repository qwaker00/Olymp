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
#include <cassert>
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

int k, n;
char G[2222][2222];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    int k;
    cin >> k;

    memset(G, 'N', sizeof(G));
    int n = 2;
    int step = 0;
    while (k) {
    	int c = k % 3;

    	assert(step <= 18);

    	if (c) {
    		for (int i = 0; i < 18; ++i) {
    			if (i < step) {
	    			n += 3;
    				if (i == 0) {
    					G[1][n-0] = G[n-0][1] = 'Y';
    					G[1][n-1] = G[n-1][1] = 'Y';
    					G[1][n-2] = G[n-2][1] = 'Y';
    				} else {
    					G[n-3][n-0] = G[n-0][n-3] = 'Y';
    					G[n-3][n-1] = G[n-1][n-3] = 'Y';
    					G[n-3][n-2] = G[n-2][n-3] = 'Y';
    										
    					G[n-4][n-0] = G[n-0][n-4] = 'Y';
    					G[n-4][n-1] = G[n-1][n-4] = 'Y';
    					G[n-4][n-2] = G[n-2][n-4] = 'Y';

    					G[n-5][n-0] = G[n-0][n-5] = 'Y';
    					G[n-5][n-1] = G[n-1][n-5] = 'Y';
    					G[n-5][n-2] = G[n-2][n-5] = 'Y';    					
    				}
    			} else {
    				++n;
    				if (i == 0) {
    					G[n][1] = G[1][n] = 'Y';    					    					
    				} else
    				if (i - 1 < step) {
    					G[n][n-1] = G[n-1][n] = 'Y';
    					G[n][n-2] = G[n-2][n] = 'Y';
    					G[n][n-3] = G[n-3][n] = 'Y';    					
    				} else {
    					G[n][n-1] = G[n-1][n] = 'Y';    					    					
    				}
    			}
    		}
    		if (c == 1) {
    			++n;
    			if (step == 18) {
					G[n][n-1] = G[n-1][n] = 'Y';
					G[n][n-2] = G[n-2][n] = 'Y';
					G[n][n-3] = G[n-3][n] = 'Y';    					
    			} else {
    				G[n][n-1] = G[n-1][n] = 'Y';
    			}
    			G[n][2] = G[2][n] = 'Y';
    		} else {
    			n += 2;
    			if (step == 18) {
					G[n][n-2] = G[n-2][n] = 'Y';
					G[n][n-3] = G[n-3][n] = 'Y';
					G[n][n-4] = G[n-4][n] = 'Y';    					

					G[n-1][n-2] = G[n-2][n-1] = 'Y';
					G[n-1][n-3] = G[n-3][n-1] = 'Y';
					G[n-1][n-4] = G[n-4][n-1] = 'Y';    					
    			} else {
    				G[n][n-2] = G[n-2][n] = 'Y';
    				G[n-1][n-2] = G[n-2][n-1] = 'Y';
    			}
    			G[n][2] = G[2][n] = 'Y';
    			G[n-1][2] = G[2][n-1] = 'Y';
    		}
    	}

    	++step;
    	k /= 3;
    }

    cout << n <<  endl;
    for (int i = 1; i <= n; ++i) {
    	G[i][n + 1] =0;
		puts(G[i] + 1);
    }

    return 0;
}
