#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

int n, m, a[1111][1111];

#define CHKSECOND if (t.first.second < t.second.second)
#define CHKFIRST  if (t.first.first < t.second.first)
#define PUSH(t)  if (it + q.size() <= 20000000) q.push(t)

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    queue< pair< pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(n - 1, m - 1)));

    LL ans = 0;
    int it = 0;
    while (!q.empty() && ++it <= 20000000) {
        pair< pair<int, int>, pair<int, int> > t = q.front(); q.pop();
        int m = min(
            min(a[t.first.first][t.first.second], a[t.first.first][t.second.second]), 
            min(a[t.second.first][t.first.second], a[t.second.first][t.second.second])
        );
        if (m > ans) ans = m;

        if (a[t.first.first][t.first.second] == m) {
            if (a[t.first.first][t.second.second] == m) {
                ++t.first.first;
                CHKFIRST
                    PUSH(t);
            } else if (a[t.second.first][t.first.second] == m) {
                ++t.first.second;
                CHKSECOND
                    PUSH(t);
            } else {
                ++t.first.first;
                CHKFIRST
                    PUSH(t);
                --t.first.first;

                ++t.first.second;
                CHKSECOND
                    PUSH(t);
            }
        } else {
            if (a[t.first.first][t.second.second] == m) {
                if (a[t.second.first][t.second.second] == m) {
                    --t.second.second;
                    CHKSECOND
                        PUSH(t);
                } else {
                    --t.second.second;
                    CHKSECOND
                        PUSH(t);
                    ++t.second.second;

                    ++t.first.first;
                    CHKFIRST
                        PUSH(t);
                }
            } else {
                if (a[t.second.first][t.second.second] == m) {
                    if (a[t.second.first][t.first.second] == m) {
                        --t.second.first;
                        CHKFIRST
                            PUSH(t);
                    } else {
                        --t.second.first;
                        CHKFIRST
                            PUSH(t);
                        ++t.second.first;

                        --t.second.second;
                        CHKSECOND
                            PUSH(t);
                    }
                } else if (a[t.second.first][t.first.second] == m) {
                    --t.second.first;
                    CHKFIRST
                        PUSH(t);
                    ++t.second.first;                    

                    ++t.first.second;
                    CHKSECOND
                        PUSH(t);
                }
            }            
        }
    }
    cout << ans << endl;
    cerr << clock() << endl;
    cerr << it << endl;
    
    return 0;
}
