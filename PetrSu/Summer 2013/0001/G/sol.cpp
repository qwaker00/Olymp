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

const int N = 1000333;
int n;
int rght[N];
int lft[N];
int f[N];
int a[N];
int cnt[N], rcnt[N];
int num[N];
int prev[N], nxt[N];
int rnum[N];

vector<int> g[N];

int main() {
	freopen("gem.in", "r", stdin);
	freopen("gem.out", "w", stdout);
	
	memset(lft, -1, sizeof(lft));

	int ans = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		cnt[ a[i] ]++;
		num[i] = cnt[ a[i] ];
		g[ a[i] ].push_back(i);

		ans = max(ans, cnt[ a[i] ]);

		if (lft[ a[i] ] == -1) lft[ a[i] ] = i;
		rght[ a[i] ] = i;
	}
	prev[0] = -1;
	for (int i = 1; i < N; ++i)
		if (cnt[i - 1]) prev[i] = i - 1;
		else prev[i] = prev[i - 1]; 
    nxt[N - 1] = -1;
    for (int i = N - 2; i >= 0; --i)
    	if (cnt[i + 1]) nxt[i] = i + 1;
    	else nxt[i] = nxt[i + 1];

	for (int i = 0; i < n; ++i)
		if (i == rght[ a[i] ]) {
			f[i] = cnt[ a[i] ];

			int pos = lft[ a[i] ];
			int prv = prev[ a[i] ];
			if (prv != -1 && g[prv][0] < pos) {
		   		int l = 0, r = g[prv].size() - 1;
		   		while (l < r) {
		   			int mid = (l + r + 1) >> 1;
		   			if (g[prv][mid] >= pos) r = mid - 1;
		   			else l = mid;
		   		}
		   		if (l == g[prv].size() - 1) {
		   			f[i] += f[ rght[ prv ] ];
		   		} else {
		   			f[i] += l + 1;
		   		}
		   	}
				
		   	int cnext = nxt[ a[i] ];
		   	int cand = f[i];
            if (cnext != -1 && g[cnext].back() > i) {
            	int l = 0, r = g[cnext].size() - 1;
            	while (l < r) {
            		int mid = (l + r) >> 1;
            		if (g[cnext][mid] > i) r = mid;
            		else l = mid + 1;
            	}
            	cand += g[cnext].size() - l;
            }

            ans = max(ans, cand);
		}

	for (int i = n - 1; i >= 0; --i) {
		rcnt[ a[i] ]++;
		rnum[ i ] = rcnt[a[i]];
		if (nxt[ a[i] ] != -1)
		ans = max(ans, num[i] + rcnt[ nxt[ a[i] ]  ]);
	}

	cout << n - ans << endl;
	
	        
	return 0;
}
