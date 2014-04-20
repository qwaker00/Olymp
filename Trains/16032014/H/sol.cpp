#include <iostream>
#include <stdio.h>
#include <math.h>
#include <assert.h>

using namespace std;

const int N = 1000111;
int grandy[N], f;
int used[2*N];
int iter = 0;

int cntiter = 0;

int doit(int x, int m) {
    assert(2 <= m && m <= x);
    
    int k = x / m;
    int cntbig = x % m;
    int cntsmall = m - cntbig;

    int ans = 0;
    if (cntbig & 1) ans ^= grandy[k + 1];
    if (cntsmall & 1) ans ^= grandy[k];
    return ans;
}

int calc(int x) {
    if (x < f) {
        return 0;
    }
    ++iter;

    int lim = sqrt(double(x)) + 1;
    if (lim > x) lim = x;

    for (int i = 1; i <= lim; ++i) {
        int l = max(2, x / (i + 1) + 1);
        int r = x / i;

        if (l > r) continue;
        used[doit(x, l)] = iter;    
        if (l + 1 <= r) {
            used[ doit(x, l + 1) ] = iter;
        }
    }    

    int from = 2;
    int to = min(x, lim + 10); 
    for (int i = from; i <= to; ++i) {
        used[ doit(x, i) ] = iter;
    }

    int result = 0;
    while (used[result] == iter) ++result;
    return result;
}

int main() {
    freopen("nimg.in", "r", stdin);
    freopen("nimg.out", "w", stdout);

    int g;
    cin >> g >> f;
    for (int i = 0; i <= 100000; ++i) {
        grandy[i] = calc(i);
        //if (!(i & 127)) cerr << i << endl;
    }

    while (g--) {
        int n; cin >> n;
        ++iter;

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            ans ^= grandy[x];
        }

        if (ans) cout << "1 ";
        else cout << "0 ";
    }
    cout << endl;

    return 0;
}