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

int dig[4][3] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{0, 0, 0}
};

vector<int> nums;

void rec(int cnt, int x, int y, int num) {
	if (cnt > 4) return;
	if (y > 2) return;
	if (x == 3 && y != 1) return;
	if (x > 3) return;
	nums.push_back(num);
//	cerr << num << endl;
	rec(cnt, x + 1, y, num);
	rec(cnt, x, y + 1, num);
	rec(cnt + 1, x, y, num * 10 + dig[x][y]);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    rec(0, 0, 0, 0);
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int T;
    cin >> T;
    while (T--) {
    	int x;
    	cin >> x;
    	int i = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
    	int ans = 100500;
    	if (i != nums.size()) {
    		ans = nums[i];
    	}
    	if (i != 0 && abs(nums[i - 1] - x) <= abs(ans - x)) {
    		ans = nums[i - 1];
    	}
    	cout << ans << "\n";
    }

    return 0;
}
