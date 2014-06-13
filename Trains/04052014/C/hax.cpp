#include <cstdio>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

inline int digit(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    return ch - 'a' + 10;
}

void mark(int x , int y, vector<vector<bool> >& was, vector<vector<bool> >& tmp) {
    if (x < 0 || y < 0 || x >= was.size() || y >= was[0].size() || !was[x][y]) return;
    was[x][y] = false;
    tmp[x + 1][y + 1] = true;
    mark(x - 1, y, was, tmp);
    mark(x, y - 1, was, tmp);
    mark(x + 1, y, was, tmp);
    mark(x, y + 1, was, tmp);
}

void marktmp(int x , int y, vector<vector<bool> >& tmp) {
    if (x < 0 || y < 0 || x >= tmp.size() || y >= tmp[0].size() || tmp[x][y]) return;
    tmp[x][y] = true;
    marktmp(x - 1, y, tmp);
    marktmp(x, y - 1, tmp);
    marktmp(x + 1, y, tmp);
    marktmp(x, y + 1, tmp);
}

char ID[11];

int findHoles(vector< vector<bool> >& tmp) {
    int cnt = 0;
    for (int i = 0; i < tmp.size(); ++i)
        for (int j = 0; j < tmp[i].size(); ++j) {
            if (tmp[i][j] == false) {
                marktmp(i, j, tmp);
                ++cnt;
            }
        }
    return cnt - 1;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    ID[1] = 'A';
    ID[3] = 'J';
    ID[5] = 'D';
    ID[4] = 'S';
    ID[0] = 'W';
    ID[2] = 'K';

    int __it = 0;
    while (1) {
        int n, m;
        cin >> n >> m;
        m *= 4;
        if (n == 0) break;

        vector< vector<bool> > f(n, vector<bool>(m, false));
        vector< vector<bool> > was(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                f[i][j] = digit(s[j / 4]) & (1 << (3 - (j % 4)));
            }
        }

        string ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (f[i][j]) {
                    vector< vector<bool> > tmp(n + 2, vector<bool>(m + 2, false));
                    mark(i, j, f, tmp);
                    ans += ID[findHoles(tmp)];
                }
            }
        }

        sort(ans.begin(), ans.end());

        ++__it;
        printf("Case %d: %s\n", __it, ans.c_str());
    }


    return 0;
}

