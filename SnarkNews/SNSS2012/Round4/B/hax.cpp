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
int la, lb, l;
char a[111111], b[111111], c[111111];


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> a >> b;
    la = strlen(a);
    lb = strlen(b);
    reverse(a, a + la);
    reverse(b, b + lb);
    for (int i = 0; i < la; i++) a[i] -= 48;
    for (int i = 0; i < lb; i++) b[i] -= 48;
    for (int i = 0; i < max(la, lb); i++) c[i] = a[i] + b[i];
    l = max(la, lb) - 1;

    bool ch = true;
    while(ch) {
    	ch = false;
	    for (int i = l; i >= 0; i--) {	
    		if (c[i] > 1) {
    			c[i] -= 2;
				++c[i + 1];
				if (i + 1 > l) l = i + 1;
				if (i > 1) {
					++c[i - 2];
				}
				ch = true;
	    	}
    	}
	    for (int i = l; i >= 0; i--)
	    	if (i && c[i]  && c[i - 1]) {
	    		c[i + 1]++;
	    		c[i]--;
	    		c[i - 1]--;
				if (i + 1 > l) l = i + 1;
				ch = true;
	    	}
    }
    for (int i = l; i >= 0; i--) cout << char(c[i] + '0');
    cout << endl;

    return 0;
}
