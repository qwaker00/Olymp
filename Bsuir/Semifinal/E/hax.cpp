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


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	ULL x = 0;    
    ULL sum = 0;
	int next = 0, first = 0;
	vector<ULL> ans;
	while (cin >> x) {
		sum += x;
		ans.push_back(x);
	}
	for (int i = 0; i < ans.size(); ++i) {
		if (ans[i] == 1) {
			if (i == 0) {
				next = 1;
				break;
			}
			--ans[i - 1];

			ULL s = 1;
			for (int j = i; j < ans.size(); ++j) s += ans[j];

			ans.erase(ans.begin() + i, ans.end());

			while (s) {
				int x = min(ans.back(), s);
				ans.push_back(x);
				s -= x;
			}
			first = true;
			break;
		}
	}
	if (!first) {
		--ans.back();
		ans.push_back(1);
	}
	if (sum == 0) next = 1;
	if (next) {
		ans.clear();
		ans.push_back(sum + 1);
	}

	for (int i = 0; i < ((int)ans.size()) - 1; ++i) {
		cout << ans[i] << '+';
	}
	cout << ans.back() << endl;
    
    return 0;
}
