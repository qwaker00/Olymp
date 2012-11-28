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


int n, m, h[111][111];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int add[111][111];

int main() {
    freopen("forest.in", "r", stdin);
    freopen("forest.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; ++j) {
        scanf("%d", &h[i][j]);
    }

    vector< pair<int, int> > q1, q2;
    vector< pair<int, int> > *curq = &q1, *notcurq = &q2;

    for (int i = 0; i < n; i++) for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; k++) {
                int newx = i + dx[k];
                int newy = j + dy[k];
                if (newx < 0 || newy < 0 || newx >= n || newy >= m) continue;
                if (h[newx][newy] == h[i][j] + 1) {
                    curq->push_back(make_pair(i, j));
//                    cerr << i << " " << j << endl;
                    break;
                }
            }
    }

    int ans = 0;
    while (!curq->empty()) {
        cerr << " === " << endl;

        ++ans;
        for (int i = 0; i < curq->size(); ++i) {
            const pair<int, int>& p = curq->operator[](i);
            ++h[p.first][p.second];
        }

        for (int i = 0; i < curq->size(); ++i) {
            const pair<int, int>& p = curq->operator[](i);

            for (int j = 0; j < 4; j++) {
                int newx = p.first + dx[j];
                int newy = p.second + dy[j];

                if (newx < 0 || newy < 0 || newx >= n || newy >= m) continue;

                if (add[p.first][p.second] != ans && h[newx][newy] == h[p.first][p.second] + 1) {
                    add[p.first][p.second] = ans;
                    notcurq->push_back(make_pair(p.first, p.second));

//                    cerr << p.first << " " << p.second << endl;
                }
                if (add[newx][newy] != ans && h[newx][newy] + 1 == h[p.first][p.second]) {
                    add[newx][newy] = ans;
                    notcurq->push_back(make_pair(newx, newy));                    

//                    cerr << newx << " " << newy << endl;
                }
            }
        }
        curq->clear();

        swap(notcurq, curq); 
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", h[i][j]);
        }
        puts("");
    }

    
    return 0;
}
