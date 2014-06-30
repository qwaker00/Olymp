#include <iostream>
#include <set>
#include <stdio.h>

using namespace std;

const int MOD = 1000000007;
const int N = 200222;
typedef long long ll;

int pow2[N];
int w[N];
    int n, m;

int fath(int x) {
    if (w[x] != x) w[x] = fath(w[x]);
    return w[x];
}

void un(int x, int y) {
    w[fath(x)] = fath(y);
}

set<int> used;

inline bool have(int x, int y) {
    return x & (1 << y);
}


void dfs(int x) {
    if (used.find(x) != used.end()) return;
    used.insert(x);

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (fath(i) == fath(j)) {
                if (have(x, i) != have(x, j)) {

                    int lim = 1 << n;
                    for (int msk = 0; msk < lim; ++msk)
                        if (have(msk, i) != have(x, i) && have(msk, j) != have(x, j)) {
                            bool cool = true;
                            for (int k = 0; k < n; ++k) {
                                if (k == i || k == j) continue;
                                if (have(x, k) == 1 && have(msk, k) == 1) {
                                    cool = false;
                                    break;
                                }
                            }

                            if (cool) dfs(msk);
                        }

                }
            }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) w[i] = i;
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        un(x, y);
    }

    int lim = 1 << n;
    int ans = 0;
    for (int i = 0; i < lim; ++i)
        if (used.find(i) == used.end())  {
            ++ans;
            dfs(i);

            /*
            for (int j = 0; j < n; ++j)
                if (have(i, j)) cout << '1';
                else cout << '0';
            cout << endl;
            */
        }
    cout << ans << endl;


    return 0;
}
