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

    int T;
    string s;
    int op;
    cin >> T;
    while (T--) {
    	cin >> s;
    	op = 2;
    	cerr << s << endl;
    	for (int i = 1; i < s.length(); ++i) {
    		if (s[i] >= s[i - 1]) {
    			op += s[i] - s[i - 1];
    		} else
    			op += 'z' - s[i - 1] + 1 + s[i] - 'a';
			op += 1;
//			cerr << op << endl;
    	}
    	if (op <= 11 * s.length()) {
    		cout << "YES" << endl;
    	}
    	else
    		cout << "NO" << endl;
    }

    return 0;
}
