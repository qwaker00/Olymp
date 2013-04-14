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

#define N 222

int k, n, x, t[N];
vector<int> keys[N];
int was[5555555], endMask;

int brute(int mask, int* K) {
    int& v = was[mask];
    if (v != -1) return v;
    if (mask == endMask) return v = 1;

    v = 0;
    for (int i = 0; i < n; ++i)
        if ((mask & (1 << i)) == 0)
            if (K[t[i]]) {
                if (was[mask | (1 << i)] != -1) {
                    v |= was[mask | (1 << i)];
                } else
                {
                    --K[t[i]];
                    for (size_t j = 0; j < keys[i].size(); ++j) ++K[keys[i][j]];

                    v |= brute(mask | (1 << i), K);

                    for (size_t j = 0; j < keys[i].size(); ++j) --K[keys[i][j]];
                    ++K[t[i]];
                }
            }
    return v;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    int T;
	cin >> T;
	for (int __it = 1; __it <= T; ++__it) {
        scanf("%d%d", &k, &n);

        endMask = (1 << n) - 1;
        int K[222] = {0};
        for (int i = 0; i < k; ++i) {
            scanf("%d", &x);
            ++K[x];
        }

        for (int i = 0; i < n; ++i) {
            int kk;
            scanf("%d%d", &t[i], &kk);

            keys[i].resize(kk);
            for (size_t j = 0; j < keys[i].size(); ++j) {
                scanf("%d", &keys[i][j]);
            }                             
        }

        if (__it != 14) continue;
         
        memset(was, -1, sizeof(was));
        brute(0, K);

    	printf("Case #%d: ", __it);
        if (was[endMask] == -1) {
            puts("IMPOSSIBLE");
        } else {
            int mask = 0;
            vector<int> ans;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if ((mask & (1 << j)) == 0 && was[mask | (1 << j)] == 1) {
                        ans.push_back(j);
                        mask |= (1 << j);
                        printf("%d ", j + 1);
                        break;
                    }
            puts("");

            vector<int> cnt(222, 0);
            for (int i = 0; i < 222; ++i) cnt[i] += K[i];
            for (int i = 0; i < n; ++i) {
                int x = ans[i];
                if (K[t[x]] == 0) {
                    cout << __it << " " << i << " " << x << " ERROR" << endl;
                }
                --K[t[x]];
                for (int j = 0; j < keys[x].size(); ++j) ++K[keys[x][j]];
            }

        }        
	}    
    
    return 0;
}
