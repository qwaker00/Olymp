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

vector< pair<int, string> > g[211];
char k1[211], k2[211];
int n, m, pr[211], was[211], IT = 0, nn;
vector<int> ww;

void Edge(int x, int y, char * s1, char * s2, int l) {
    string ans;
    for (int i = 0; i < l; ++i) {    
        if (s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]) return;
        if (s1[i] == '?' && s2[i] == '?') ans += 'a';else
        if (s1[i] != '?') ans += s1[i];else ans += s2[i];
    }

    g[x].push_back(make_pair(y, ans));
}

bool kuhn(int x) {
    if (was[x] == IT) return false;
    was[x] = IT;
    for (size_t i = 0; i < g[x].size(); ++i) {
        int y = g[x][i].first;
        if (pr[y] == -1 || kuhn(y)) {
            pr[y] = x;
            return true;
        }
    }
    return false;
}

bool Can(int startFrom) {
    memset(pr, -1, sizeof(pr));
    for (int j = 0; j < ww.size(); ++j) pr[ww[j]] = nn;
    for (int i = startFrom; i < nn; ++i) {
        ++IT;
        if (!kuhn(i)) return false;
    }
    return true;
}

bool BySecond(const pair<int, string>& A, const pair<int, string>& B) {
    return A.second < B.second;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        cin >> nn;
        cin >> k1;
        cin >> k2;
        n = strlen(k1);
        ww.clear();
        m = n / nn;

        for (int i = 0; i < n; i += m) {
            for (int j = 0; j < n; j += m) {
                Edge(i / m, j / m, k1 + i, k2 + j, m);
            }
            sort(g[i].begin(), g[i].end(), BySecond);
        }
        if (Can(0)) {
            string ans;

            for (int i = 0; i < nn; ++i) {
                for (int j = 0; j < g[i].size(); ++j) {
                    pair<int, string> pre = g[i][j];
                    g[i].erase(g[i].begin() + j);
                    
                    if (Can(i + 1)) {
                        ans += pre.second;
                        ww.push_back(j);
                        break;
                    }

                    g[i].insert(g[i].begin() + j, pre);
                }
           }

           printf("Case #%d: %s\n", __it, ans.c_str());            
        } else {
            printf("Case #%d: IMPOSSIBLE\n", __it);
        }

        for (int i = 0; i < nn; ++i) g[i].clear();
    }

    
    return 0;
}
