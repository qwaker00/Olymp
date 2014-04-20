#include <iostream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <climits>

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef long double ld;
const LD PI = 3.1415926535897932384626433832795;

template<typename T>
T sqr(const T& x) { return x * x; }

using namespace std;

bool good(const vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) if (a[i] != i) return false;
	return true;
}

bool solve(vector<int>& a, vector< pair<int, int> >& ans) {
	for (int i = 0; i + 4 < a.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) if (a[j] == i) {
			int p = j;
			while (i + 3 <= p) {
				ans.push_back(make_pair(1, p - 3));
				swap(a[p], a[p - 3]);
				swap(a[p - 1], a[p - 2]);
				p -= 3;
			}
			if (i + 1 == p) {
				ans.push_back(make_pair(1, i));
				swap(a[i], a[i + 3]);
				swap(a[i + 2], a[i + 1]);
				++p;
			}
			if (i + 2 == p) {
				ans.push_back(make_pair(1, i + 1));
				swap(a[i + 1], a[i + 4]);
				swap(a[i + 3], a[i + 2]);
				++p;
			}
			if (i + 3 == p) {
				ans.push_back(make_pair(1, p - 3));
				swap(a[p], a[p - 3]);
				swap(a[p - 1], a[p - 2]);
				p -= 3;
			}
			break;	
		}
	}
	if (good(a)) return true;

	ans.push_back(make_pair(1, a.size() - 4));
	swap(a[a.size() - 4], a[a.size() - 1]);
	swap(a[a.size() - 3], a[a.size() - 2]);

	if (good(a)) return true;
	return false;
}

int main() {
//	freopen(".in","r", stdin);
//	freopen(".out","w", stdout);

	int n;
	while (cin >> n) {
		n += n;
		vector<int> a(n);
		vector< pair<int, int> > ans;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			--a[i];
		}	
	    do {
	    	if (solve(a, ans)) {
		    	printf("%d\n", ans.size());
		    	for (int j = 0; j < ans.size(); ++j) {
	    			printf("%d %d\n", ans[j].first, ans[j].second + (ans[j].first == 1));
	    		}
	    		break;
	    	}
	    	for (int i = 0; i < 3; ++i) {
	    		int x = (rand() % n) + 1;
	    		ans.push_back(make_pair(2, x));
	    		rotate(a.begin(), a.begin() + x, a.end());

	    		if (good(a)) break;
	    	}
	    	for (int i = 0; i < 3; ++i) {
	    		int x = rand() % n;
	    		ans.push_back(make_pair(1, x));
	    		swap(a[x], a[(x + 3) % n]);
	    		swap(a[(x + 2) % n], a[(x + 1) % n]);

	    		if (good(a)) break;
	    	}
	    } while (true);
	}

	return 0;
}