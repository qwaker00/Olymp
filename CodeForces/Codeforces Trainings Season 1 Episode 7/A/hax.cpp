#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111

int n;
int qual[N];
char s[111111];
char ch;
int x[N], y[N];
int q[N], pos[N];

int dist(int i, int j) {
    return sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d\n", &n);

        map<string, int> names;
        for (int i = 0; i < n; ++i) {
            scanf("%s %c\n", s, &ch);
            qual[i] = (ch == 'q');
            names[s] = i;

            scanf("%d%d%d", &x[i], &y[i], &q[i]);
            q[i] = n - q[i];
        }

        int r, t;
        scanf("%d", &r);
        scanf("%s", s);
        t = names[s];

        vector<int> p;
        for (int i = 0; i < n; ++i) if (i != t && !qual[i]) {
            int dti = dist(t, i);

            pos[i] = 0;
            for (int j = 0; j < n; ++j)
                if (j != i && dti > dist(i, j))
                    ++pos[i];
            p.push_back(pos[i]);
        }

        sort(p.begin(), p.end());
        int mx = 0;
        for (int s = 0; s < n; ++s) {
            int score = 0;

            for (int i = 0; i < n; ++i) if (i != t) {
                if (qual[i]) {
                    int p = r - s;
                    for (int j = 0; j < n; ++j)
                        if (j != i && q[j] > q[t])
                            --p;
                    if (p > 0)
                        score += p;
                }
            }
            int ss = s;
            for (int i = 0; i < p.size() && ss > 0; ++i) {
                if (p[i] == 0) {
                    score += r;
                    continue;
                } 
                if (p[i] >= r) {
                    ss -= p[i] - r + 1;
                    p[i] = r - 1;
                    if (ss <= 0) break;
                }
                if (p[i] < r) {
                    int tt = min(p[i], ss);
                    ss -= tt;
                    p[i] -= tt;
                }
                if (p[i] < r) {
                    score += r - p[i];
                }
            }

            if (score > mx) mx = score;
        }
        cout << mx << endl;
    }            
    
    return 0;
}
