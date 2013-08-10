#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct TRational {
    int a, b;

    TRational() : a(0), b(1) {}
    TRational(int a) : a(a), b(1) {}
    TRational(int av, int bv) : a(av), b(bv) {
        if (b == 0) a = 1;else
        if (a == 0) b = 1;else {
            if (b < 0) {
                b = -b;
                a = -a;
            }
            int g = __gcd(abs(a), b);
            a /= g;
            b /= g;
        }
    }

    TRational operator+(const TRational& t) const {
        return TRational(a * t.b + t.a * b, b * t.b);
    }

    TRational operator-() const {
        return TRational(-a, b);
    }

    TRational operator-(const TRational& t) const {
        return TRational(a * t.b - t.a * b, b * t.b);
    }

    TRational operator*(const TRational& t) const {
        return TRational(a * t.a, b * t.b);
    }

    TRational operator/(const TRational& t) const {
        return TRational(a * t.b, b * t.a);
    }

    bool operator==(const TRational& t) const {
        return t.a == a && t.b == b;
    }

    bool operator!=(const TRational& t) const {
        return t.a != a || t.b != b;
    }

    bool operator<(const TRational& t) const {
        return a < t.a || a == t.a && b < t.b;
    }

    friend ostream& operator<<(ostream& o, const TRational& r) {
        o << LD(r.a) / r.b;
    }
};

struct TPoint {
    TRational x, y;

    TPoint() : x(0), y(0) { }
    TPoint(TRational x, TRational y) : x(x), y(y) { }


    bool operator<(const TPoint& t) const {
        return x < t.x || x == t.x && y < t.y;
    }

    bool operator==(const TPoint& t) const {
        return x == t.x && y == t.y;
    }

    friend ostream& operator<<(ostream& o, const TPoint& r) {
        o << r.x << "," << r.y;
    }
};

struct TLine {
    TPoint A, B;


    TRational GetA() {
        return B.y - A.y;
    }

    TRational GetB() {
        return A.x - B.x;
    }

    bool Intersect(const TLine& t, TPoint& c) const {
        TRational A1 = B.y - A.y;
        TRational B1 = A.x - B.x;
        TRational C1 = - A1 * A.x - B1 * A.y;

        TRational A2 = t.B.y - t.A.y;
        TRational B2 = t.A.x - t.B.x;
        TRational C2 = - A2 * t.A.x - B2 * t.A.y;

        TRational d = A1 * B2 - A2 * B1;
        if (d == 0) return false;
        TRational dx = -C1 * B2 + C2 * B1;
        TRational dy = -C2 * A1 + A2 * C1;

        c.x = dx / d;
        c.y = dy / d;
        return true;
    }
} a[111];
int n;


vector<bool> BadPoint;
map<TPoint, int> PointId;
vector<TPoint> Point;
vector<vector<int>> g;

int GetVertex(const TPoint& p) {
    map<TPoint, int>::iterator i = PointId.find(p);
    if (i == PointId.end()) {
        PointId[p] = Point.size();
        Point.push_back(p);
        BadPoint.push_back(false);
        g.push_back(vector<int>());
        return (int)Point.size() - 1;
    }
    return i->second;
} 

void AddEdge(int x, int y) {
    g[x].push_back(y);
    cerr << Point[x].x << "," << Point[x].y << " " << Point[y].x << "," << Point[y].y << endl;
}

TPoint PointSort;

bool ByPoint(const pair<TPoint, int>& p1, const pair<TPoint, int>& p2) {
    return (p1.first.x - PointSort.x) * (p2.first.y - PointSort.y) < (p1.first.y - PointSort.y) * (p2.first.x - PointSort.x);
}

int main() {
    freopen("areas.in", "r", stdin);
    freopen("areas.out", "w", stdout);

    cout.precision(12);
    cout << fixed;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, x1, y1;
        scanf("%d%d", &x, &y);
        scanf("%d%d", &x1, &y1);
        a[i].A = TPoint(x, y);
        a[i].B = TPoint(x1, y1);
    }

    for (int i = 0; i < n; ++i) {
        vector<TPoint> vtx;
        for (int j = 0; j < n; ++j) if (i != j) {
            TPoint c;
            if (a[i].Intersect(a[j], c)) {
                vtx.push_back( c );

                cerr << i << " " << j << " " << c << endl;
            }
        }

        sort(vtx.begin(), vtx.end());
        vtx.erase(unique(vtx.begin(), vtx.end()), vtx.end());
        for (int i = 0; i < vtx.size(); ++i) {
            if (i > 0)
                AddEdge(GetVertex(vtx[i]), GetVertex(vtx[i - 1]));
            if (i  + 1 < vtx.size())
                AddEdge(GetVertex(vtx[i]), GetVertex(vtx[i + 1]));
        }
        cerr << endl;
        cerr << endl;
    }

    set< set<int> > polygons;
    for (int i = 0; i < Point.size(); ++i) if (!BadPoint[i]) {
        for (int j = 0; j < g[i].size(); ++j) {
            set<int> pts;

            int vj = g[i][j];

            pts.insert(i);
            cerr << Point[i] << " - ";
            pts.insert(vj);
            cerr << Point[vj] << " - ";
            int x = i;
            int y = vj;
            while (y != i) {
                vector< pair<TPoint, int> > v(g[y].size());
                for (int k = 0; k < g[y].size(); ++k) v[k] = make_pair(Point[g[y][k]], g[y][k]);

                PointSort = Point[y];
                sort(v.begin(), v.end(), ByPoint);

                int pk = 0;
                for (int k = 0; k < v.size(); ++k) if (v[k].first == Point[x]) {
                    pk = k;
                    break;
                }
                if (pk == 0) pk = v.size() - 1;else --pk;
                x = y;
                y = v[pk].second;
                pts.insert(y);
                cerr << Point[y] << " - ";
            }
            polygons.insert(pts);
            cerr << endl;

            pts.clear();

            pts.insert(i);
            cerr << Point[i] << " - ";
            pts.insert(vj);
            cerr << Point[vj] << " - ";

            x = i;
            y = vj;
            while (y != i) {
                vector< pair<TPoint, int> > v(g[y].size());
                for (int k = 0; k < g[y].size(); ++k) v[k] = make_pair(Point[g[y][k]], g[y][k]);

                PointSort = Point[y];
                sort(v.begin(), v.end(), ByPoint);

                int pk = 0;
                for (int k = 0; k < v.size(); ++k) if (v[k].first == Point[x]) {
                    pk = k;
                    break;
                }
                if (pk + 1 == v.size()) pk = 0;else ++pk;
                x = y;
                y = v[pk].second;
                pts.insert(y);

                cerr << Point[y] << " - ";
            }
            polygons.insert(pts);
            cerr << endl;
        }
    }
    cout << polygons.size() << endl;

    vector<LD> ans;

    for (set< set<int> >::iterator i = polygons.begin();i != polygons.end(); ++i) {
        TRational s;

        int lst = -1;
        for (set<int>::iterator j = i->begin();j != i->end(); ++j) {
            if (lst != -1) {
                s = s + (Point[lst].y - Point[*j].y) * (Point[lst].x + Point[*j].x);
            }
            lst = *j;
        }
        s = s + (Point[*i->begin()].y - Point[lst].y) * (Point[*i->begin()].x + Point[lst].x);


        if (s < 0) s = -s;
        ans.push_back(LD(s.a) / s.b);
    }
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
    
    return 0;
}
