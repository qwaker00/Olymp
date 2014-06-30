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
#include <assert.h>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct bys {
    const vector<string>& s;

    bys(const vector<string>& s) : s(s) {}

    bool operator()(int x, int y) {
        return s[x] < s[y];
    }
};

int cnt(int x, vector<int>& was, vector< vector<int> >& g, vector< vector<int> >& exist) {
    int c = 1;
    was[x] = 1;
    for (int i = 0; i < g[x].size(); ++i) {
        if (!exist[x][i]) continue;
        if (was[g[x][i]]) continue;
        c += cnt(g[x][i], was, g, exist);
    }
    return c;
}

int first;

void dfs(int x, string& ans, vector<string>& s, vector<int>& was, vector< vector<int> >& g, vector< vector<int> >& exist, vector<int>& cand, vector<vector<int> >& mir) {
    stringstream sss;
    sss << (x + 1) << " ";
    string ssss;
    getline(sss, ssss);
    ans += ssss;
//    ans += s[x];


    was[x] = 1;
    for (int i = 0; i < g[x].size(); ++i) {
        if (!exist[x][i]) continue;
        if (was[g[x][i]]) continue;

        for (int j = 0; j < cand.size(); ++j)
            if (s[g[x][i]] > s[cand[j]]) {                    
                for (int ii = i; ii < g[x].size(); ++ii) {
                    exist[x][ii] = false;
//                    cerr << x << " " << g[x][ii] << " " << ii << " " << mir[x][ii] << " " << g[x].size() << " " << g[g[x][i]].size() << endl;
                    exist[ g[x][ii] ][ mir[x][ii] ] = false;
                }

                vector<int> was(g.size(), false);
                if (cnt(first, was, g, exist) == g.size()) {
                    return;
                }

                for (int ii = i; ii < g[x].size(); ++ii) {
                    exist[x][ii] = true;
                    exist[ g[x][ii] ][ mir[x][ii] ] = true;
                }
            }

        if (i + 1 < g[x].size()) 
            cand.push_back(g[x][i + 1]);

        dfs(g[x][i], ans, s, was, g, exist, cand, mir);

        if (i + 1 < g[x].size()) 
            cand.pop_back();
    }    
}

string solve2() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > g(n, vector<int>());
    vector< vector<int> > mir(n, vector<int>());
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j =0 ; j < i; ++j)
            assert(s[j] != s[i]);
    }              
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    first = 0;
    vector< vector<int> > e(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end(), bys(s));
        if (s[i] < s[first]) first = i;
        e[i].assign(g[i].size(), true);

    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) { 
            int y = g[i][j];
//            cerr << i << " " << y << endl;
//            for (int k =0 ; k < g[y].size(); ++k) cerr << g[y][k] << " ";
//            cerr << endl;
            mir[i].push_back(lower_bound(g[y].begin(), g[y].end(), i, bys(s)) - g[y].begin());
        }
    }

    string ans;
    vector<int> was(n, 0);
    vector<int> cand;
    dfs(first, ans, s, was, g, e, cand, mir);
//    assert(ans.length() == 5 * n);
    return ans;
}

string solve() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > g(n, vector<int>());
    vector< vector<int> > mir(n, vector<int>());
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j =0 ; j < i; ++j)
            assert(s[j] != s[i]);
    }              
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> a;
    string ans = "Z";
    for (int i= 0; i < n; ++i) a.push_back(i);
    do {
//        for (int i =0 ; i < n; ++i) cerr << a[i] << " ";
//        cerr << endl;

        vector<int> st;
        bool ok = true;
        st.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            while (st.size()) {
                if (find(g[st.back()].begin(), g[st.back()].end(), a[i]) != g[st.back()].end()) {
                    st.push_back(a[i]);
                    break;
                } else {
                    st.pop_back();
                }
            }
            if (st.size() == 0) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        string ss = "";
        for (int i = 0; i < n; ++i) ss += s[a[i]];
        if (ss < ans) ans = ss;
    } while (next_permutation(a.begin(), a.end()));
    return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int it = 1; it <= T; ++it) {
        cout << "Case #" << it << ": " << solve() << endl;
    }            
    
    return 0;
}
