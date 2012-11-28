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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int A[11][11][11];
int w, h, n;

int black[11][11], white[11][11];

string s[1044][11][11];
int f[1044][11][11];

int nxt() {
    char c = getchar();
    while (c != 'W' && c != 'B') c = getchar();
    if (c == 'W') return 0;
    return 1;
}

int mabs(int x) {
    if (x < 0) return -x;
    return x;
}

int getD(pair<int, int> a, pair<int, int> b) {
    return mabs(a.first - b.first) + mabs(a.second - b.second);
}

string getPath(pair<int, int> a, pair<int, int> b) {
    string result;
    while (a.first < b.first) {
        result += 'D';
        ++a.first;
    }
    while (a.first > b.first) {
        result += 'U';
        --a.first;
    }
    while (a.second < b.second) {
        result += 'R';
        ++a.second;
    }
    while (a.second > b.second) {
        result += 'L';
        --a.second;
    }
    return result;
}

int main() {
    freopen("image.in", "r", stdin);
    freopen("image.out", "w", stdout);
    
    cin >> n >> h >> w;
    for (int i = 0; i < n; ++i) {
        for (int x = 0; x < h; ++x)
            for (int y = 0; y < w; ++y) A[i][x][y] = nxt();
    }

    for (int x = 0; x < h; ++x)
        for (int y = 0; y < w; ++y) 
            for (int i = 0; i < n; ++i)
                if (A[i][x][y]) black[x][y] += (1 << i);
                else white[x][y] += (1 << i);

    int lim = 1 << n;
    for (int msk = 1; msk < lim; ++msk) {
        if (!(msk & (msk - 1))) {
            int c = 0;
            for (int i = 0; i < n; ++i)
                if (msk == (1 << i)) {
                    c = i;
                    break;
                }

            for (int x = 0; x < h; ++x)
                for (int y = 0; y < w; ++y) {
                    s[msk][x][y] = char('0' + c);
                    f[msk][x][y] = 0;
                }
            continue;
        }

        vector< pair<int, pair<int, int> > > a;
        for (int x = 0; x < h; ++x)
            for (int y = 0; y < w; ++y) {
                if ((msk & white[x][y]) != msk && (msk & black[x][y]) != msk) {
                    s[msk][x][y] = "(" + s[msk & white[x][y]][x][y] + ":" + s[msk & black[x][y]][x][y] + ")";
                    f[msk][x][y] = max(f[msk & white[x][y]][x][y] , f[msk & black[x][y]][x][y]); 
                    a.push_back(make_pair(f[msk][x][y], make_pair(x, y)));
                }
            }
        
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); ++i) {
            pair<int, int> bestc = a[i].second;
            int best = a[i].first;
            for (int j = 0; j < i; ++j) {
                if (getD(a[i].second, a[j].second) + a[j].first < best) {
                    best = getD(a[i].second, a[j].second) + a[j].first;
                    bestc = a[j].second;
                }    
            }

            s[msk][a[i].second.first][a[i].second.second] = getPath(a[i].second, bestc) + s[msk][bestc.first][bestc.second];
            f[msk][a[i].second.first][a[i].second.second] = best;
            a[i].first = best;
        }

        for (int x = 0; x < h; ++x) 
        for (int y = 0; y < w; ++y) {
            pair<int, int> bestc = a[0].second;
            int best = 1e8;

            pair<int, int> cur = make_pair(x, y);

            for (int j = 0; j < a.size(); ++j) {
                if (getD(cur, a[j].second) + a[j].first < best) {
                    best = getD(cur, a[j].second) + a[j].first;
                    bestc = a[j].second;
                }    
            }

            s[msk][x][y] = getPath(cur, bestc) + s[msk][bestc.first][bestc.second];
            f[msk][x][y] = best;
        }
    } 

    /*
    for (int msk = 0; msk < lim; ++msk)
        for (int x = 0; x < h; ++x)
            for (int y = 0; y < w; ++y)
                cerr << msk << "  " << x << " " << y << ": " << s[msk][x][y] << endl;
                */

    cout << s[lim - 1][0][0] << endl;

    return 0;
}
