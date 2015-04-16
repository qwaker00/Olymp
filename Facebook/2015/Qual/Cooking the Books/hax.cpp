#include <bits/stdc++.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;


int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
   	cin >> T;
   	for (int __case = 1; __case <= T; ++__case) {
   		string x;
   		cin >> x;
   		LL mi, ma;
   		mi = ma = strtoll(x.c_str(), 0, 10);
   		for (int i = 0; i < (int)x.size(); ++i) {
   			for (int j = i + 1; j < (int)x.size(); ++j) {
	   			if (i == 0 && x[j] == '0') continue;
   				swap(x[i], x[j]);
   				LL val = strtoll(x.c_str(), 0, 10);
   				if (val < mi) mi = val;
	   			if (val > ma) ma = val;
   				swap(x[i], x[j]);
   			}
   		}
   		assert(mi <= ma);
   		cout << "Case #" << __case << ": " << mi << " " << ma << endl;
   	}
    
    return 0;
}
