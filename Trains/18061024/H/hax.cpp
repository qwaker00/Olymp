#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>

using namespace std;

const int N = 555;

int n, m, was[N];
vector<int> g[N];
vector<int> r[N];
int d[N];

void list(int x, vector<int>& odds, int& c) {
    if (was[x]) return;
    was[x] = 1;
    ++c;
    if (d[x] & 1)
        odds.push_back(x);
    for (int i = 0; i < (int)g[x].size(); ++i) {
        list(g[x][i], odds, c);
    }
}

int ewas[N][N];
int et = 0, spec[N][N];

void euler(int x, vector<int>& ans) {
    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (ewas[x][i]) continue;

        ewas[x][i] = ewas[g[x][i]][r[x][i]] = et;

        euler(g[x][i], ans);
    }
    ans.push_back(x);
}

int main() {
    freopen("sewers.in", "r", stdin);
    freopen("sewers.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        r[x].push_back(g[y].size());
        g[y].push_back(x);
        r[y].push_back(g[x].size() - 1);
        d[x]++;
        d[y]++;
    }

    vector< vector<int> > out;
    for (int i = 1; i <= n; ++i) if (!was[i]) {
        vector<int> odds;
        int cnt = 0;
        list(i, odds, cnt);
        if (cnt < 2) continue;
        //random_shuffle(odds.begin(), odds.end());

        if (odds.size() == 0) {
            out.push_back(vector<int>());
            ++et;
            euler(i, out.back());
        } else {
            set< pair<int, int> > spec;
            for (int i = 2; i < odds.size(); i += 2) {
                g[odds[i]].push_back(odds[i + 1]);
                r[odds[i]].push_back(g[odds[i + 1]].size());
                g[odds[i + 1]].push_back(odds[i]);
                r[odds[i + 1]].push_back(g[odds[i]].size() - 1);
                spec.insert(make_pair(odds[i], odds[i + 1]));
                spec.insert(make_pair(odds[i + 1], odds[i]));
            }

            vector<int> ans;
            ++et;
            euler(odds[0], ans);

            vector<int> preans;
            for (int i = 0; i < ans.size(); ++i) {
                preans.push_back(ans[i]);
                if (i + 1 < ans.size() && spec.find(make_pair(ans[i], ans[i + 1])) != spec.end()) {
                    out.push_back(preans);

                    spec.erase(make_pair(ans[i] , ans[i + 1]));
                    spec.erase(make_pair(ans[i + 1] , ans[i]));

                    preans.clear();
                }
            }
            out.push_back(preans);

            for (int i = 2; i < odds.size(); i += 2) {
                g[odds[i]].pop_back();
                r[odds[i]].pop_back();
                g[odds[i + 1]].pop_back();
                r[odds[i + 1]].pop_back();
            }
        }
    }

    cout << out.size() << "\n";
    for (int i = 0; i < out.size(); ++i) {
        for (int j = 0; j < out[i].size(); ++j)
            cout << out[i][j] << " ";
        cout << "\n";
    }


    return 0;
}
