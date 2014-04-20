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

int n, k, q;
char s[111][1111];
int fail[1111][111];
int team[111], tn = 0, inteam[111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d%d\n", &n, &k, &q);
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
    }

    for (int i = q - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) 
            if (s[j][i] == '1')
                fail[i][j] = fail[i + 1][j] + 1;
            else
                fail[i][j] = 0;        
    }

    for (int i = 0; i < n; ++i) {
        if (tn < k) {
            team[tn++] = i;
            inteam[i] = 1;
        } else {
            int looser = 0;
            for (int j = 1; j < tn; ++j) 
                if (fail[0][team[j]] < fail[0][team[looser]]) {
                    looser = j;
                }
            if (fail[0][i] > fail[0][team[looser]]) {
                inteam[team[looser]] = 0;
                inteam[i] = 1;
                team[looser] = i;
            }
        }
    }

    vector<int> start;
    vector< pair<int, pair<int, int> > > ch;
    for (int i= 0; i < n; ++i) if (inteam[i]) start.push_back(i + 1);

    bool epicfail = false;
    for (int i = 0; i < q; ++i) {
        int looser = 0;
        for (int j = 0; j < tn; ++j) {
            if (s[team[j]][i] == '0') {
                epicfail = true;
                break;
            }
            if (fail[i + 1][team[j]] < fail[i + 1][team[looser]]) {
                looser = j;
            }
        }
        if (epicfail) break;

        int winner = -1;
        for (int j = 0; j < n; ++j) if (!inteam[j]) {
            if (winner == -1 || fail[i + 1][winner] < fail[i + 1][j]) {
                winner = j;
            }
        }
        if (i + 1 < q && fail[i + 1][winner] > fail[i + 1][team[looser]]) {
            ch.push_back(make_pair(i + 1, make_pair(team[looser] + 1, winner + 1)));

            inteam[team[looser]] = 0;
            inteam[winner] = 1;

            team[looser] = winner;
        }
    }
    if (epicfail) {
        puts("FAIL");
    } else {
        puts("WIN");

        for (int i = 0; i < start.size(); ++i) printf("%d ", start[i]);
        puts("");

        printf("%d\n", ch.size());
        for (int i = 0; i < ch.size(); ++i) {
            printf("%d %d %d\n", ch[i].first, ch[i].second.first, ch[i].second.second);
        }

    }

    return 0;
}
