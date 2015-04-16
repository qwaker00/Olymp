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
	
	int n;
	string s;
	cin >> n; 
	cin >> s;
	for (int i = 0; i < s.length(); ++i) if (s[i] == '*') {
		for (int j = 1; i + j * 4 < s.length(); ++j) {
			
			if (s[i+j] == '*' &&
			    s[i+2*j] == '*' &&
			    s[i+3*j] == '*' &&
			    s[i+4*j] == '*')
			    {
			    	cout << "yes\n";
			    	return 0;
			    }

		}		
	}
	cout << "no\n";
    
    return 0;
}
