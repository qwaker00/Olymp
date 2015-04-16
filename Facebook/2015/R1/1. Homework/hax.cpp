#include <bits/stdc++.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;

const int N = 10000111;
int pr[N], cnt[11][N];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int mx = 0;
    for (int i = 2; i < N; ++i)
    	if (pr[i] == 0)
	    	for (int j = i; j < N; j += i) {
    			++pr[j];
    			if (pr[j] > mx) {
    				mx = pr[j];
    			}
    		}
	assert(mx < 11);
	for (int i = 1; i <= mx; ++i) {
		for (int j = 1; j < N; ++j)
			cnt[i][j] = cnt[i][j - 1] + (pr[j] == i);
	}

    int T;
    cin >> T;
	for (int __case = 1; __case <= T; ++__case) {
		int l, r, x;
		cin >> l >> r >> x;		
		cout << "Case #" << __case << ": " << cnt[x][r] - cnt[x][l - 1] << endl;
	}

    return 0;
}
