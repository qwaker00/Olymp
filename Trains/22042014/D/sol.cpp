#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

const int MOD = 1000000007;
const int N = 200222;
typedef long long ll;

int pow2[N];
int w[N];

int fath(int x) {
    if (w[x] != x) w[x] = fath(w[x]);
    return w[x];
}

void un(int x, int y) {
    w[fath(x)] = fath(y);
}

set<int> used;

int main() {
    pow2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        w[i] = i;
    }

    if (m == 0) {
        cout << pow2[n] << endl;
        return 0;
    } else {
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x; --y;
            un(x, y);
        }

        set<int> q;
        for (int i = 0; i < n; ++i) {
            q.insert(fath(i));
        }
        cout << (1 + pow2[q.size()]) % MOD << endl;
    }

    return 0;
}
