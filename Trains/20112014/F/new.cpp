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


bool check(const char * s, int n) {
	int gamma = 0;
	for (int i = 0; i < n; ++i) {
		int k = 1;
		while (i + k + k <= n) {
			if (strncmp(s + i, s + i + k, k) == 0) {
				break;
			}
			++k;
		}
		if (i + k + k > n) {
			++gamma;
		}
		if (gamma * 2 < (i + 1)) return false;
	}
	return true;
}
bool check(const string& s) {
	return check(s.c_str(), s.length());
}

int main() {
    freopen("free.in", "r", stdin);
    freopen("free.out", "w", stdout);

    int N;
    cin >> N;

    vector<string> ans;
    ans.push_back("");
   	for (int n = 1; n <= N; ++n) {   		
//   		cout << "For length: " << n << endl;
		vector<string> oldans;
		oldans.swap(ans);
   		for (int i = 0; i < oldans.size(); ++i) {
   			string s = oldans[i] + "0";
   			if (check(s)) {
   				ans.push_back(s);
//   				cout << s << endl;
   			}
   			s = oldans[i] + "1";
   			if (check(s)) {
   				ans.push_back(s);
//   				cout << s << endl;
   			}
   		}
//   		cout << "Count: " << ans.size() << endl;

//   		puts("");
  // 		puts("");
   	}

   	cout << ans.size() << "\n";
   	sort(ans.begin(), ans.end());
   	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << "\n";
   	

    return 0;
}
