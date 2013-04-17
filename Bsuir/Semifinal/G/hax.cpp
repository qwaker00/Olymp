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

const int N = 10111;

vector<vector<int> > a, rght, down, where;

pair<int, int> posa[N];
int cnt[N], n, m, k;

char w[N];

int was[111];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
	scanf("%d%d\n", &n, &m);
    
    

    a.resize(n + 2);
    for (int i = 0; i <= n + 1; ++i) a[i].resize(m + 2);
    where = rght = down = a;
    
    
    
    for (int i = 0; i <= n + 1; ++i) a[i][0] = a[i][m + 1] = 1;
    for (int i = 0; i <= m + 1; ++i) a[0][i] = a[n + 1][i] = 1;
 
    
    
    for (int i = 1; i <= n; ++i) {
   		gets(w);
   		for (int j = 1; j <= m; ++j) a[i][j] = w[j - 1] - '0'; 
    }

    for (int i = 0; i <= n + 1; ++i)  {
    	int cur = m + 1;
    	for (int j = m + 1; j >= 0; --j) {
    		if (a[i][j] == 1) cur = j; 
			rght[i][j] = cur;  
    	}
    }

    for (int i = 0; i <= m + 1; ++i)  {
    	int cur = n + 1;
    	for (int j = n + 1; j >= 0; --j) {
    		if (a[j][i] == 1) cur = j; 
			down[j][i] = cur;  
    	}
    }

    

    
    if (n + 10 < m) {
    	for (int i = 1; i <= n; ++i)
    		for (int j = 1; j <= m; ++j) 
    			if (a[i][j] == 0) {
					posa[k++] = make_pair(i, j);
					int& ans = cnt[k - 1];
					ans = 0;

					int len = rght[i][j] - j;
					for (int q = i; q <= n && len; ++q) {
						ans += len;
						len = min(len, rght[q + 1][j] - j);
					}	
	    		}
    } else {
        for (int i = 1; i <= n; ++i)
    		for (int j = 1; j <= m; ++j) 
    			if (a[i][j] == 0) {
					posa[k++] = make_pair(i, j);
					int& ans = cnt[k - 1];
					ans = 0;

					int len = down[i][j] - i;
					for (int q = j; q <= m && len; ++q) {
						ans += len;
						len = min(len, down[i][q + 1] - i);
					}	
	    		}

 		for (int y = 1; y <= m; ++y) {
 			memset(was, 63, sizeof(was));

 			for (int x = n + 1; x; --x) {
 				int lim = rght[x][y] - y;
 				int ans = 1e9;
 				for (int i = 0; i < lim; ++i) {
 					ans = min(ans, was[i]); 
 				}
 				was[ lim ] = x;

 				where[x][y] = ans;
 			}
 		}	
    }

    


    for (int i = 1; i < k; ++i) cnt[i] += cnt[i - 1];
    
    int q;
    scanf("%d", &q);
    while (q--) {
    	int num; scanf("%d", &num); --num; 
		
		int pos = upper_bound(cnt, cnt + k, num) - cnt;

		printf("%d %d ", posa[pos].first, posa[pos].second);

		if (pos)
			num -= cnt[pos - 1];

		int x = posa[pos].first; 
		int y = posa[pos].second;

		if (n + 10 < m) {
			int len = rght[x][y] - y;
			while (len <= num) {
				num -= len;
				len = min(len, rght[++x][y] - y);					
			}

			printf("%d %d\n", x, y + num);
		} else {
			int width = rght[x][y] - y;
			int height = where[x][y] - x;

			while (width * height < num) {
				num -= width * height;
				x += height;
				width = rght[x][y] - y;
				height = where[x][y] - x;
			}

			printf("%d %d\n", x + (num / width), y + (num % width));
		}
    }
    

    return 0;
}
