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

#define N 211111

struct Tp {
    int x;
    int y;

   bool operator<(const Tp& A) {
        return y > A.y;
   } 
} a[N];

LD maxh[N];
int h, w;
int n;
LD ans = 0;

LD CalcX(const Tp& a1, const Tp& a2, int y) {
    if (a2.y == a1.y) return a2.x;
    return a1.x + (a2.x - a1.x) * (y - a1.y) / (a2.y - a1.y);
}

LD Mul(Tp& a, Tp& b, Tp& c) {
    return - (c.x - b.x) * (a.y - b.y) + (a.x - b.x) * (c.y - b.y);
}

int Y;
struct TTp {
    Tp first, second;
    int id;

    bool operator<(const TTp& B) const {
        return CalcX(first, second, Y) < CalcX(B.first, B.second, Y) || CalcX(first, second, Y) == CalcX(B.first, B.second, Y) && id < B.id;
    }
};

bool ByY(const pair<Tp,Tp>& A, const pair<Tp,Tp>& B){
    return A.first.y > B.first.y;
}

int main() {
    freopen("rag.in", "r", stdin);
    freopen("rag.out", "w", stdout);

    scanf("%d%d", &w, &h);
    scanf("%d", &n);
    int an = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }

    vector<pair<Tp, Tp> > all;
    for (int i = 0; i + 1 < n; i++) all.push_back(make_pair(a[i], a[i + 1]));

    sort(all.begin(), all.end(), ByY);

    set<TTp> ss;

    for (int i = 0, j = 0; i <= h; i++) {
        while (j < all.size() && all[j].first.y == i) {
            TTp newt;
            newt.first = all[j].first;
            newt.second = all[j].second;
            newt.id = j;
            ss.insert( newt );
            ++j;
        }

        while (ss.size() && ss.rbegin()->second.y > i) {
            ss.erase(*ss.rbegin());
        }

        if (ss.size()) {
            maxh[i] = CalcX(ss.rbegin()->first, ss.rbegin()->second, i);
        }
        a[an].x = maxh[i];
        a[an].y = i;
        an++;
    }

    a[an].x = w;
    a[an].y = h;
    an++;

    a[an] = a[0];
    for (int i = 0; i < an; i++) {
        ans += (a[i].x + a[i + 1].x) * LL(a[i].y - a[i + 1].y);
    }
    cout.precision(12);
    ans = fabsl(ans) / 2;
    cout << fixed << ans << endl;

    return 0;
}
