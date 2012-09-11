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

    int T, ans, n;
    char s[1111];

    cin >> T;
    while (T--) {
    	cin >> n >> s;
    	ans = (s[0] != '1' && s[1] != '1');
		for (int i = 1; s[i]; ++i) ans += (s[i - 1] != '1' && s[i] != '1' && s[i + 1] != '1');
		cout << ans << endl;
    }
    
    return 0;
}
