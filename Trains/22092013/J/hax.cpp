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


//map< vector<unsigned>, int> code;
vector<int> a, b;

int counter = 0;
int n, t, p;
int m[22], l[22], pr[44];
vector< pair< pair<ULL, ULL> ,int> > A;
vector< pair< pair<ULL, ULL> ,int> > B;
int div5[44];

pair<ULL, ULL> Encode(const vector<int>& v) {
    ULL c1 = 0, c2 = 0;
    for (int i = 0; i < v.size(); ++i) c1 = c1 * 37 + v[i];
    for (int i = 0; i < v.size(); ++i) c2 = c2 * 43 + v[i];
    return make_pair(c1, c2);
}

void gen1(vector<int>& id, int c, int stps) {
    if (c == 0) {
        A.push_back(make_pair(Encode(id), stps));
        return;
    }
    for (int i = 0; i < p; ++i) {
        rotate(id.begin(), id.end() - m[i] - l[i], id.end() - m[i]);
        gen1(id, c - 1, stps * 6 + i + 1);
        rotate(id.begin(), id.begin() + l[i], id.end() - m[i]);
    }
}
void gen2(vector<int>& id, int c, int stps) {
    if (c == 0) {
        B.push_back(make_pair(Encode(id), stps));
        return;
    }
    for (int i = 0; i < p; ++i) {
        rotate(id.begin(), id.begin() + l[i], id.end() - m[i]);
        gen2(id, c - 1, stps * 6 + i + 1);
        rotate(id.begin(), id.end() - m[i] - l[i], id.end() - m[i]);
    }
}

void Answer(int x, int y) {
    deque<int> ans;
    while (x) {
        ans.push_front(x % 6);
        x /= 6;
    }
    while (y) {
        ans.push_back(y % 6);
        y /= 6;
    }
    for (deque<int>::iterator i = ans.begin(); i < ans.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
//    cerr << clock() << endl;
    exit(0);
} 

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    for (int i = 0; i < 44; i += 5) div5[i] = 1;

    scanf("%d%d%d", &n, &t, &p);
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        --b[i];
    }
    for (int i = 0; i < p; ++i) {
        scanf("%d%d", &m[i], &l[i]);
    }

    cerr << clock() << endl;
    gen1(a,   t / 2, 0);
    cerr << clock() << endl;
    gen2(b, t - t / 2, 0);
    cerr << clock() << endl;

    sort(B.begin(), B.end());
    for (int i = 0; i < A.size(); ++i) {
        int p = lower_bound(B.begin(), B.end(), make_pair(A[i].first, -1)) - B.begin();
        if (p < B.size() && B[p].first == A[i].first) {
            Answer(A[i].second, B[p].second);
        }
    }
    puts("Impossible");
    return 0;
}
