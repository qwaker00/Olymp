#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

int ans = 0;

void rec(int l, int left) {
	if (left < l) return;
	if (left == 0) {
		++ans;
		return;
	}

	for (int i = l; i <= left; ++i) {
		rec(i, left - i);
	}
}


int main() {
	//freopen("in", "r", stdin);

	int n;
	cin >> n;
	rec(1, n);
	cout << ans << endl;	
	
	return 0;
}
