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

const int L = 22222;
char s[L], s1[L], s2[L], s3[L];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d\n", &T);
	while (T--) {
		set<string> fob;
		gets(s);
		do {
			scanf("%s %s %s", s1, s2, s3);
			if (strcmp(s1, "what") == 0 && strcmp(s2, "does") == 0) {
				gets(s1);
				break;
			}
			fob.insert(s3);
		} while(true);
		istringstream ss(s);
		string word;
		while (ss >> word) {
			if (!fob.count(word)) {
				cout << word << " ";
			}
		}
		cout << "\n";
	}

    return 0;
}
