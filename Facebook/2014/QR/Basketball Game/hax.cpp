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

struct Tp {
    string name;
    int p, h;

    bool operator<(const Tp& t) const {
        return p > t.p || (p == t.p && h > t.h);
    }
} a[33];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        int n, m, p;
        cin >> n >> m >> p;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].name >> a[i].p >> a[i].h;
        }
        sort(a, a + n);

        vector<int> team1, team2;
        for (int i = 0; i < n; ++i) {
            if (i & 1) team2.push_back(i);else team1.push_back(i);
        }
        queue<int> q1, q2, bench1, bench2;
        for (int i = p - 1; i >= 0; --i) q1.push(team1[i]);
        for (int i = p; i < team1.size(); ++i) bench1.push(team1[i]);

        for (int i = p - 1; i >= 0; --i) q2.push(team2[i]);
        for (int i = p; i < team2.size(); ++i) bench2.push(team2[i]);

        while (m--) {
            bench1.push(q1.front()); q1.pop();
            q1.push(bench1.front()); bench1.pop();

            bench2.push(q2.front()); q2.pop();
            q2.push(bench2.front()); bench2.pop();
        }

        vector<string> ans;
        while (!q1.empty()) {
            ans.push_back(a[q1.front()].name);
            q1.pop();
        }
        while (!q2.empty()) {
            ans.push_back(a[q2.front()].name);
            q2.pop();
        }
        sort(ans.begin(), ans.end());

        printf("Case #%d:", __it);
        for (int i = 0; i < ans.size(); ++i) {
            printf(" %s", ans[i].c_str());
        }
        puts("");
    }
    
    return 0;
}
