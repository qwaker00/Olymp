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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, m, s, g, d;
    int a[255][255];

    cin >> n;
    for (int i = 0; i < n; ++i) {	
    	for (int j = 0; j < n; ++j) {
    		cin >> a[i][j];
    	}
    }

    for (int k = 0; k < n; ++k) {
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			if (a[i][k] + a[k][j] < a[i][j]) {
    				a[i][j] = a[i][k] + a[k][j];
    			}
    		}
    	}
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
    	cin >> s >> g >> d;
    	cout << a[s][g] + a[g][d] << " " << a[s][g] + a[g][d] - a[s][d] << endl;
    }

    return 0;
}
