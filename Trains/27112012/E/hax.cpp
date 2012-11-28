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

#define N 111111

int n, x, acad[N];
vector<int> from[N];

int A, B;
int dep[N], D[N];

int Solve(int startFrom) {
    queue<int> q[3];
    int learned = 0;

    memcpy(dep, D, sizeof(D));
    for (int i = 0; i < n; i++) {
        if (dep[i] == 0) {
            q[ acad[i] ].push(i);
        }
    }

    int ans = B * n;
    int cur = startFrom;
    while (learned < n) {
//        cerr << " === " << endl;
        ans += A;
        while (!q[cur].empty()) {
            int x = q[cur].front(); q[cur].pop();
            ++learned;
//            cerr << x << endl;

            for (int i = 0; i < from[x].size(); ++i) {
                int y = from[x][i];
                if (--dep[y] == 0) {
                    q[ acad[y] ].push( y );
                    cerr << y << endl;
                }
            }
        }
        cur = 3 - cur;
    }

    return ans;
}


int main() {
    freopen("jediacademy.in", "r", stdin);
    freopen("jediacademy.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d%d", &acad[i], &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            --x;

            D[i]++;
            from[x].push_back(i);
        }
    }
    scanf("%d%d", &A, &B);

    cout << min( Solve(2), Solve(1) ) << endl;
    
    return 0;
}
