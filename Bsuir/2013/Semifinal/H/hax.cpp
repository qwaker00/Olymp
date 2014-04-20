#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, m, k;
int x[222], y[222], dx[222], dy[222];
char ch;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
	scanf("%d%d%d", &n, &m, &k);
	for (int i =0; i < k; ++i)  {
		scanf("%d%d %c", &x[i], &y[i], &ch);

		x[i] *= 2;
		y[i] *= 2;
		
		if (ch == 'R') {
			dx[i] = 0;
			dy[i] = 1;
		} else 
		if (ch == 'L'){
			dx[i] = 0;
			dy[i] = -1;			
		} else 
		if (ch == 'U'){
			dx[i] = -1;
			dy[i] = 0;			
		} else 
		if (ch == 'D'){
			dx[i] = 1;
			dy[i] = 0;			
		}
	}

	int ans = 0;

	for (int i = 1; i <= 400; ++i) {
		for (int j = 0; j < k; ++j) {
			x[j] += dx[j];
			y[j] += dy[j];
		}
		for (int j = 0; j < k; ++j) 
			for (int l = j + 1; l < k; ++l)
				if (x[j] == x[l] && y[j] == y[l]) {
					ans = i;
				}
	}

	cout << (ans / 2) << "." << (ans % 2) * 5 << endl;
    
    return 0;
}
