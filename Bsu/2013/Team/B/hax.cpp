#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

const int N = 1000111;

char w[N];

int a[255];

int main() {
    freopen("dna.in", "r", stdin);
    freopen("dna.out", "w", stdout);
    
    int n;
    scanf("%d\n", &n);
	gets(w);

	int ans = 0;
	memset(a, -1,sizeof(a));
	for (int i = 0; i < n; ++i) {
		a[ w[i] ] = i;

		vector<int> b;
		for (int j = 'A'; j <= 'Z'; ++j) b.push_back(a[j]);

		sort(b.begin(), b.end());

		if (b[b.size() - 2] == -1) { 
			continue;
		}
		ans = max(ans, i - b[b.size() - 3]);
	}

	cout << ans << endl;
    
    return 0;
}
