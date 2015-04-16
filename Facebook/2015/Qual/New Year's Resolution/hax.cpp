#include <bits/stdc++.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;

bool rec(size_t i, int x, int y, int z, vector<int>& X, vector<int>& Y, vector<int>& Z) {
	if (x == 0 && y == 0 && z == 0) return true;
	if (i == X.size() || x < 0 || y < 0 || z < 0) return false;
	return rec(i + 1, x, y, z, X, Y, Z) ||
		   rec(i + 1, x - X[i], y - Y[i], z - Z[i], X, Y, Z);
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
   	cin >> T;
   	for (int __case = 1; __case <= T; ++__case) {
   		int X, Y, Z, n;
   		cin >> X >> Y >> Z >> n;
   		vector<int> x(n), y(n), z(n);
   		for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];
   		cout << "Case #" << __case << ": " << (rec(0, X, Y, Z, x, y, z) ? "yes" : "no") << endl;
   	}
    
    return 0;
}
