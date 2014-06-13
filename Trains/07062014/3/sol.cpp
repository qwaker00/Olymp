#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;
const int N = 200111;
struct Tp {
    ll d, t;
    bool operator<(const Tp& c) const {
        return d < c.d || (d == c.d && t < c.t);
    }
} A[N];
bool alive[N];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; ++i) {
        alive[i] = true;
        int d, t;
        scanf("%d%d", &d, &t);
        A[i].d = d;
        A[i].t = t;
    }
    sort(A + 1, A + n + 1);

    vector< pair<ll, int> > tt;
    for (int i = 1; i <= n; ++i) {
        tt.push_back(make_pair(A[i].d + A[i].t, i));
    }
    sort(tt.begin(), tt.end());

    int ans = 0;
    for (int who = 0; who < n; ++who) {
        int x = tt[who].second;
        if (!alive[x]) continue;

        int y = x;
        while (y + 1 <= n && alive[y + 1] && A[y].d + t > A[y + 1].d) {
            if (A[y + 1].t < A[x].t) break;
            alive[y] = false;
            ++y;
        }
        ans = max(ans, y - x + 1);
    }
    cout << ans << endl;

    return 0;
}
