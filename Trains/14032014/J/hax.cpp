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

const int N = 11111;

struct Te {
    int x, y;
} e[N];

int n, m;
vector<int> g[N];


int findcycle(int x, const vector<int>& good, vector<int>& was, vector<int>& banned, vector<int>& cycle) {
    if (was[x]) {
        return was[x];
    }
    cycle.push_back(x);
    was[x] = cycle.size();
    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (good[ e[g[x][i]].y ]) {
            int t = findcycle(e[g[x][i]].y, good, was, banned, cycle);            
            if (t) {
                if (was[x] >= t) banned[ g[x][i] ] = true;
                return t;
            }
        }
    }

    return 0;
}

vector<int> dfs(int x, const vector<int>& good, vector<int>& was2, vector<int>& incycle, vector<int>& banned) {
    if (was2[x]) return vector<int>();
    was2[x] = true;
    if (incycle[x]) {
        return vector<int>(1, x);
    }
    vector<int> v(1, x);
    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (good[ e[g[x][i]].y ] && !banned[ g[x][i] ]) {
            vector<int> v1 = dfs(e[g[x][i]].y, good, was2, incycle, banned);
//            cerr << "dfs " << x << "->" << e[g[x][i]].y << "=" << v.size() << " " << v1.size() << endl;
            v.insert(v.end(), v1.begin(), v1.end());
        }
    }
//    cerr << "dfs " << x << "=" << v.size() << endl;
    return v;
}

vector<string> solve(const vector<int>& all) {
    cerr << "solve ";
    for (int i = 0; i < all.size(); ++i) cerr << all[i] << " ";
    cerr << endl;

    if (all.size() == 1) {
        stringstream ans;
        ans << "vertex " << all[0];

        cerr << "out" << endl;
        return vector<string>(1, ans.str());
    }
    vector<int> cycle;
    vector<int> was;
    vector<int> was2;
    vector<int> banned;
    vector<int> incycle;
    vector<int> good;
    vector<int> skip;
    int cstart;

    good.resize(n + 1, 0);
    for (int i = 0; i < (int)all.size(); ++i) good[all[i]] = 1;

    banned.assign(m + 1, 0);
    was.assign(n + 1, 0);
    skip.assign(n + 1, 0);
    incycle.assign(n + 1, 0);

    cycle.clear();
    cstart = findcycle(all[0], good, was, banned, cycle);

    vector< pair<int, vector<string> > > rc;
    vector<int> realcycle;
    for (int i = cstart - 1; i < (int)cycle.size(); ++i) {
//        cerr << cycle[i] << " ";
        realcycle.push_back(cycle[i]);
        incycle[cycle[i]] = 1;
    }
//    cerr << endl;
    for (int it = 0; it < (int)realcycle.size(); ++it) {
        int x = cycle[it];
        if (skip[x]) continue;

        was2.assign(n + 1, 0);
        vector<int> access(1, x);
        for (int i = 0; i < (int)g[x].size(); ++i) {
            if (good[ e[g[x][i]].y ] && !banned[ g[x][i] ]) {
                vector<int> access1 = dfs(e[g[x][i]].y, good, was2, incycle, banned);
                access.insert(access.end(), access1.begin(), access1.end());
            }
        }

        cerr << x << " " << access.size() << endl;
        for (int i = 0; i < access.size(); ++i) {
            cerr << " " << access[i] << endl;
        }
        for (int i = 0; i < (int)access.size(); ++i) {
            skip[access[i]] = true;
        }
        skip[x] = false;

        if (access.size() == 1)  {
            rc.push_back(make_pair(x, vector<string>()));
        } else {
            rc.push_back(make_pair(-1, solve(access)));
        }
    }

    int cnt = 0;
    for (int i = 0; i < (int)rc.size(); ++i) if (rc[i].first == -1 || !skip[rc[i].first]) ++cnt;
                
    vector<string> ans;

    stringstream ss;
    ss << "wheel " << cnt;
    ans.push_back(ss.str());

    for (int i = 0; i < (int)rc.size(); ++i)
        if (rc[i].first == -1) {
            for (int j = 0; j < (int)rc[i].second.size(); ++j) {
                ans.push_back(string("  ") + rc[i].second[j]);
            }
        } else if (!skip[rc[i].first]) {
            ans.push_back(string("  ") + solve(vector<int>(1, rc[i].first))[0]);
        }

    cerr << "out" << endl;
    return ans;
}

int main() {
    freopen("wheels.in", "r", stdin);
    freopen("wheels.out", "w", stdout);
    
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].x >> e[i].y;
        g[e[i].x].push_back(i);
    }

    vector<int> all(n);
    for (int i = 1; i <= n; ++i) all[i - 1] = i;

    vector<int> banned(m + 1);
    vector<string> ans = solve(all);
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
