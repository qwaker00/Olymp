#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;
typedef long long ll;
const int N = 1000111;
int n, q; 
int x[N], y[N];
int t[N], a[N], b[N];
vector< pair<int, int> > g[N];

#ifdef DEBUG
#define CERR(x) cerr << x;
#else
#define CERR(x) 
#endif

bool checkBad() {
    ll A = y[1] - y[0];
    ll B = x[0] - x[1];
    ll C = -A * ll(x[0]) - B * ll(y[0]);
    for (int i = 2; i < n; ++i) {
        if (A * ll(x[i]) + B * ll(y[i]) + C != 0) return false; 
    }
    return true;
}

int origin = -1;
inline bool cmp(pair<int, int> a, pair<int, int> b) {
    ll x1 = x[a.first] - x[origin], x2 = x[b.first] - x[origin];
    ll y1 = y[a.first] - y[origin], y2 = y[b.first] - y[origin];
    ll z1 = y1 > 0 || y1 == 0 && x1 > 0, z2 = y2 > 0 || y2 == 0 && x2 > 0;
    if (z1 != z2) return z1 > z2;
    return x1 * y2 - x2 * y1 > 0;
}

bool used[N + N];
int from[N + N], to[N + N];
int ke = 0;
int kf = 0;
ll sq[N + N];
map< pair<int, int>, int> v2pos;
map< pair<int, int>, int> ends2num;
int w[N + N], wedge[N + N];

int fath(int x) {
    if (w[x] != x) w[x] = fath(w[x]);
    return w[x];
}

int krand = 0;
void un(int x, int y) {
    x = fath(x); y = fath(y);
    if (x == y) return;
    if (krand ^= 1) {
        swap(x, y); 
    }
    CERR("Connecting face " << x << " " << y << " and now it's " << y << endl);
    w[x] = y;
    if (sq[x] == -1 || sq[y] == -1) sq[y] = -1;
    else sq[y] += sq[x];
}

ll myabs(ll x) {
    if (x < 0) return -x;
    return x;
}

void select(int edge, int num) {
    sq[num] = 0; 
    w[num] = num; 
    CERR("Face #" << num << "[")
    while (!used[edge]) {
        CERR(to[edge] << ' ');

        used[edge] = true;
        wedge[edge] = num;
        sq[num] += ll(y[ from[edge] ] + y[ to[edge] ]) * ll(x[ from[edge] ] - x[ to[edge] ]);
        edge = g[ to[edge] ][ (1 + v2pos[ make_pair(from[edge], to[edge]) ]) % g[ to[edge] ].size() ].second;
    }
    CERR("]: square = " << sq[num] << endl);
    sq[num] = myabs(sq[num]);

}

void addEdge(int a, int b) {
    ends2num[ make_pair(a, b) ] = ke;
    from[ke] = a; to[ke] = b;
    g[a].push_back(make_pair(b, ke++));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", x + i, y + i);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d", t + i, b + i, a + i);
        if (t[i] == 1) {
            addEdge(a[i], b[i]);
            addEdge(b[i], a[i]);
        }
    }

    if (n == 1 || checkBad()) {
        for (int i = 0; i < q; ++i)
            if (t[i] == 0) puts("-1");
        return 0;
    }
    
    for (int i = 0; i < n; ++i) {
        origin = i; 
        sort(g[i].begin(), g[i].end(), cmp);
        CERR("N(" << i << ") = [");
        for (int j = 0; j < g[i].size(); ++j) {
            CERR(g[i][j].first << " ");
            v2pos[ make_pair(g[i][j].first, i) ] = j;
        }
        CERR("]\n");
    }
    origin = 0;
    for (int i = 0; i < n; ++i) {
        if (y[i] < y[origin] || (y[i] == y[origin] && x[i] < x[origin])) {
            origin = i;
        }
    }
    select(g[origin][0].second, kf++);
    sq[0] = -1;

    for (int i = 0; i < ke; ++i)
        if (!used[i]) {
            select(i, kf++);
        }
    for (int i = 0; i < ke; ++i) {
        CERR("[" << from[i] << "->" << to[i] << "] is in " << wedge[i] << endl)
    }

    vector<ll> ans;
    for (int query = q - 1; query >= 0; --query) {
        if (t[query] == 0) {
            int face = fath( wedge[ ends2num[make_pair(a[query], b[query])] ] );
            CERR("Square of face #" << face << ": " << sq[face] << endl);
            ans.push_back(sq[face]);    
        } else {
            CERR(a[query] << " <=> " << b[query] << endl);
            int w1 = ends2num[ make_pair(a[query], b[query]) ];
            int w2 = w1 ^ 1;
            un(wedge[w1], wedge[w2]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << '\n';
    }
    cout.flush();

    return 0;
}