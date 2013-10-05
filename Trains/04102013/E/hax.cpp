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

int dx[] = {1, 1, 0, -1, -1, 0};
int dy[] = {0, 1, 1, 0, -1, -1};
char s[1111];
pair<int, int> a[1111];
map< pair<int, int>, int> was;
int an = 0;

int dist(int x, int y) {
    return min(abs(x - y), 6 - abs(x - y));
}

int finddir(int x, int y) {
    for (int i = 0; i < 6; ++i)
        if (dx[i] == x && dy[i] == y)
            return i;
    throw 1;
}

bool check(const pair<int,int>& c,
           const pair<int,int>& a1, const pair<int,int>& a2,
           const pair<int,int>& b1, const pair<int,int>& b2)
{
    vector< pair<int, int> > v;
    v.push_back(make_pair(finddir(a1.first - c.first, a1.second - c.second), 0));
    v.push_back(make_pair(finddir(a2.first - c.first, a2.second - c.second), 0));
    v.push_back(make_pair(finddir(b1.first - c.first, b1.second - c.second), 1));
    v.push_back(make_pair(finddir(b2.first - c.first, b2.second - c.second), 1));
    sort(v.begin(), v.end());
    v.push_back(v[0]);
    for (int i = 1; i < 5; ++i) if (v[i].second == v[i - 1].second) return false;
    return true;
/*
    int da2 = finddir(a2.first - c.first, a2.second - c.second);
    int db1 = finddir(b1.first - c.first, b1.second - c.second);
    int db2 = finddir(b2.first - c.first, b2.second - c.second);
    return dist(da1, da2) > dist(da1, db1) && dist(da1, da2) > dist(da1, db2) &&
           dist(db1, db2) > dist(db1, da1) && dist(db1, db2) > dist(db1, da2) &&
           dist(da1, da2) > dist(da2, db1) && dist(da1, da2) > dist(da2, db2) &&
           dist(db1, db2) > dist(db2, da1) && dist(db1, db2) > dist(db2, da2);
*/
}

int main() {
    freopen("archelon.in", "r", stdin);
    freopen("archelon.out", "w", stdout);

    gets(s);
    int x = 0, y = 0, d = 0;

    a[an++] = make_pair(x, y);
    was[a[an - 1]] = an - 1;

    int ans = 0, possib = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == 'F') {
            if (possib) {
//                cerr << "pos" << endl;
                if (an > 1) {
                    int pid = was[a[an - 1]];
                    if (pid > 0 && pid + 1 < an) {
                        if (check(a[an - 1], 
                             make_pair(x + dx[d], y + dy[d]), a[an - 2],
                             a[pid - 1], a[pid + 1]))
                         {
                            ++ans;
//                          cerr << "yeah" << endl;
                         } 
                    }
                }
                possib = 0;
            }

            x += dx[d];
            y += dy[d];
            a[an++] = make_pair(x, y);
            if (was.find(a[an - 1]) == was.end()) {
                was[a[an - 1]] = an - 1;
            } else {
                possib = true;
            }
        } else if (s[i] == 'R') d = (d + 1) % 6;else d = (d + 5) % 6;
    }
    cout << ans << endl;

    return 0;
}
