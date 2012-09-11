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

int A[111][111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    string s;
    int allno = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0 ; j < n; j++) {
    		cin >> s;
    		A[i][j] = s[0] == 'Y';
    	}
    }

    for (int i = 0; i < n; i++) {
    	if (A[i][i] != 1) {
    		continue;
    	}
    	bool good = true;
    	for (int j = 0; j < n; j++) if (j != i) {
    		int eq = true;
    		for (int k = 0; k < n; j++) if (A[i][k] != A[j][k]) {
    			eq = false;
    			break;
    		}
    		if (eq) {
    			if (A[i][j] == 1) {
    			} else {
    				good = false;
    				break;
    			}    			
    		} else {
    			if (A[i][j] == 1) {
    				good = false;
    				break;
    			} else {
    			}    			
    		}
    	}

    	if (good) {
    		for (int j = 0; j < n; j++) {
    			if (A[i][j]) puts("YES");else puts("NO");
    		}
    		return 0;
    	}
    }

    for (int i = 0; i < n; i++) cout << "NO\n";

    return 0;
}
                                                