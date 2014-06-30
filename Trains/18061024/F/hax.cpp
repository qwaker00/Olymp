#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long LL;

const int N = 111111;
int h[N], a[N], hn = 0, n, S[N];

int get(int x) {
    ++x;

    int sum = 0;
    while (x) {
        sum += S[x];
        x &= x - 1;
    }
    return sum;
}

void add(int x) {
    ++x;

    while (x <= hn) {
        ++S[x];
        x = (x | (x - 1)) + 1;
    }
}

int main() {
    freopen("invers.in", "r", stdin);
    freopen("invers.out", "w", stdout);

    int p, q;
    scanf("%d%d%d", &p, &q, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        h[hn++] = a[i];
    }
    sort(h, h + hn);
    hn = unique(h, h + hn) - h;
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        int ai = lower_bound(h, h + hn, a[i]) - h;

        LL y = (LL(a[i]) * q + p - 1) / p;
        int yi = hn;
        if (y <= h[hn - 1]) yi = lower_bound(h, h + hn, (int)y) - h - 1;
        //cerr << "yi " << yi << endl;

        int addv = get(yi);

        //int radd = 0;
        //for (int j = 0; j < i; ++j) if (a[j] * p < a[i] * q) ++radd;
        //cerr << radd << " " << addv << endl;

        ans += addv;

        //cerr << "add " << ai << endl;
        add(ai);
    }
    cout << ans << endl;

    return 0;
}
