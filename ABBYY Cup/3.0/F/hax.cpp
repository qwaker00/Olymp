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

int a[2222][2222], out[2222][2222], was[2222][2222];
int n, m;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};


void dfs(int i, int j, vector<int>& x,vector<int>& y) {
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (was[i][j] || a[i][j] != 1) return;
    was[i][j] = true;
    x.push_back(i);
    y.push_back(j);
    dfs(i - 1, j, x, y);
    dfs(i + 1, j, x, y);
    dfs(i, j + 1, x, y);
    dfs(i, j - 1, x, y);
}

void dfs2(int i, int j) {
    if (was[i][j]) return;
    if (a[i][j] != 1) return;
    was[i][j] = 1;
    out[i][j] = 8;

    int cntone = 0;
       for (int dxx = -3; dxx <= 3; dxx++)
       for (int dyy = -3; dyy <= 3; dyy++) {
           int xx = i + dxx;
           int yy = j + dyy;
           if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
               cntone += a[xx][yy] == 1;
           }
       }
    if (cntone < 39) return;
    dfs2(i - 1, j);
    dfs2(i + 1, j);
    dfs2(i, j + 1);
    dfs2(i, j - 1);       
}


void OUTPUT() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << out[i][j] << " ";
        cout << endl;
    }
}

bool InRect(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
    return abs(c.first - b.first) + abs(c.first - a.first) == abs(a.first - b.first) &&
           abs(c.second - b.second) + abs(c.second - a.second) == abs(a.second - b.second);
}

double Dist(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
    double A = b.second - a.second;
    double B = a.first - b.first;
    double C = -a.first * A - a.second * B;
    return fabsl(A * c.first + B * c.second + C) / sqrt(A*A + B *B);
}

double Dist(pair<int, int>& a, pair<int, int>& b) {
    return sqrtl(sqr(a.first - b.first) + sqr(a.second - b.second));
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            out[i][j] = a[i][j];
        }
    }


    vector<pair<int, int> > centers;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (a[i][j] == 1 && !was[i][j]) {
            vector<int> sx;
            vector<int> sy;
            dfs(i, j, sx, sy);
            nth_element(sx.begin(), sx.begin() + sx.size() / 2, sx.end());
            nth_element(sy.begin(), sy.begin() + sy.size() / 2, sy.end());

            centers.push_back(make_pair(sx[sx.size() / 2], sy[sy.size() / 2]));
            out[sx[sx.size() / 2]][sy[sy.size() / 2]] = 4;
        }

    }


    memset(was, 0, sizeof(was));
    for (int i = 0; i < centers.size(); ++i) {
        dfs2(centers[i].first, centers[i].second);
    }

    set< pair<int, int> > l;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (a[i][j] == 1) {
            int nei = 0;
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m) nei += a[x][y] == 1;
            }
            if (nei <= 3) {
                bool fnd = false;

                for (int dx = -3; !fnd && dx <= 3; ++dx) 
                    for (int dy = -3; dy <= 3; ++dy) {
                        if (l.find(make_pair(i + dx, j + dy)) != l.end()) {
                            fnd = true;
                            break;
                        }
                    }

                if (!fnd && !was[i][j]) {
                    l.insert(make_pair(i, j));
                    out[i][j] = 2;
                }
            }
        }
    }



    vector<vector<pair<int, int> > > luch(centers.size());

    vector<pair<int, int> > ll(l.begin(), l.end());
    for (int j = 0; j < ll.size(); ++j) {
        double mind = 1e100;
        int ans = 0;

        for (int i = 0; i < centers.size(); ++i) {
           double d = sqrt(sqr(ll[j].first - centers[i].first) +  sqr(ll[j].second - centers[i].second));
           if (d < mind)  {
            mind = d;
            ans = i;
           }
        }

        luch[ans].push_back(ll[j]);
    }


    vector<int> ans;
    for (int i = 0; i < centers.size(); ++i) {
        vector<pair<int, int> > cl;
        for (int j = 0; j < luch[i].size(); ++j) {
            pair<int, int> p;
            int mind = 2e9;
            for (int dx = -36; dx < 36; ++dx)
            for (int dy = -36; dy < 36; ++dy) if (dx * dx + dy * dy < mind) {
                    int xx = luch[i][j].first + dx;
                    int yy = luch[i][j].second + dy;
                    if (xx >= 0 && yy >= 0 && xx < n && yy < m && out[xx][yy] == 8) {
                        mind = dx * dx + dy * dy;
                        p.first = xx;
                        p.second = yy;
                    }
            }
//            cerr << luch[i][j].first << " " << luch[i][j].second << " " << p.first << " " << p.second << endl;
//          out[p.first][p.second] = -j;
            cl.push_back(p);
        }

        vector<double> ratios;
        int cnt = 0;
        for (int j = 0; j < luch[i].size(); ++j) {

            if (Dist(cl[j], luch[i][j]) < 5) continue;

            int cntone = 0;
                for (int dxx = -4; dxx <= 4; dxx++)
                for (int dyy = -4; dyy <= 4; dyy++) {
                    int xx = luch[i][j].first + dxx;
                    int yy = luch[i][j].second + dyy;
                    if (xx >= 0 && yy >= 0 && xx < n && yy < m) {
                        cntone += a[xx][yy] == 1;
                    }
                }

            bool bad = false;
            for (int k = 0; k < luch[i].size(); ++k) if (k != j) {
                if (InRect(cl[k], luch[i][k], luch[i][j]) && Dist(cl[k], luch[i][k], luch[i][j]) < 5) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                ratios.push_back(cntone);
                out[luch[i][j].first][luch[i][j].second] = cntone;
            }
        }

        cerr << ratios.size() << ": ";
        sort(ratios.begin(), ratios.end());
        for (int j = 0; j < ratios.size(); ++j)
            cerr << ratios[j] << " ";
        cerr << endl;

        ans.push_back(ratios.size());
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
    cout << endl;
//    OUTPUT();

    return 0;
}
