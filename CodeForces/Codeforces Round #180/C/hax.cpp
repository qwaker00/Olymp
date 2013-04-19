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


map<int, int> lastc;
map<int, int> lastt;
map<int, int> cnt;
int n;
int s[111111];
vector<int> a, b;

bool Check(vector<int> a) {
    sort(a.begin(), a.end());
    int bad = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == a[i]) {
            ++bad;
        }
    }
    return bad <= ((a.size() + 2) / 3);
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);

        int& c = lastc[s[i]];
        int& t = lastt[s[i]];
        int centr = s[i] >> 1;
        if (s[i] & 1) {
            int fnd = 0;
            for (;; ++c) {
                for (; t <= centr; ++t) {
                    if (cnt[centr - t] + cnt[centr + t + 1] == c) {
                        ++cnt[centr - t];
                        ++cnt[centr + t + 1];
                        a.push_back(centr - t);
                        b.push_back(centr + t + 1);
                        fnd = 1;
                        break;
                    }
                }
                if (fnd) break;
                t = 0;
            }
        } else {
            int fnd = 0;
            for (;; ++c) {
                for (; t <= centr; ++t) {
                    if (cnt[centr - t] + cnt[centr + t] == c) {
                        ++cnt[centr - t];
                        ++cnt[centr + t];
                        a.push_back(centr - t);
                        b.push_back(centr + t);
                        fnd = 1;
                        break;
                    }
                }
                if (fnd) break;
                t = 0;
            }
        }
    }
    if (Check(a) && Check(b)) {
        puts("YES");
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        puts("");
        for (int i = 0; i < n; ++i) {
            printf("%d ", b[i]);
        }
        puts("");
    } else puts("NO");
                           
    return 0;
}
