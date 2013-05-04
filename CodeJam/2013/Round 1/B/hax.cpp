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

#define double LD
#define mp make_pair
typedef vector< pair<int, int> > vp;

map<vp, double> A[22];


void fall(int x, int y, const vp& src, map<vp, double>& dest, double prob) {
    if (y == 0) {
        vp np = src;
        np.push_back(mp(x, y));
        dest[np] += prob;
        return;
    }

    bool d = find(src.begin(), src.end(), mp(x, y - 2)) != src.end();
    bool l = find(src.begin(), src.end(), mp(x - 1, y - 1)) != src.end();
    bool r = find(src.begin(), src.end(), mp(x + 1, y - 1)) != src.end();
    if (l && r) {
        vp np = src;
        np.push_back(mp(x, y));
        dest[np] += prob;
        return;
    }
    if (!l && !r) {
        if (!d) {
            fall(x, y - 1, src, dest, prob);
            return;
        } 
        fall(x + 1, y - 1, src, dest, prob / 2);
        fall(x - 1, y - 1, src, dest, prob / 2);
        return;
    }
    if (l) {
        fall(x + 1, y - 1, src, dest, prob);
        return;
    } else {
        fall(x - 1, y - 1, src, dest, prob);
        return;
    }
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    vp s;
    s.push_back(mp(0, 0));
    A[1][s] = 1.;
    for (int it = 1; it <= 20; ++it) {
        map<vp, double>& newall = A[it + 1];
        map<vp, double>& all = A[it];


        cerr << it << endl;

        for (map<vp, double>::iterator i = all.begin(); i != all.end(); ++i) {
            const vp& d = i->first;
            double prob = i->second;

            int sy = 0;
            for (int i = 0; i < d.size(); ++i) if (d[i].first == 0 && d[i].second > sy) sy = d[i].second;

            fall(0, sy + 2, d, newall, prob);


//            cerr << "[" << prob << "] ";
//            for (int j = 0; j < d.size(); ++j) cerr << (d[j].first + d[j].second) / 2 << "," << (d[j].first - d[j].second) / 2 << " ";
//            cerr << endl;
        }
        cerr << all.size() << endl;
    }
    

    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        int n;
        cin >> n;

        map<vp, double>& all = A[n];

        int x, y;
        cin >> x >> y;
        double ans = 0;
        for (map<vp, double>::iterator i = all.begin(); i != all.end(); ++i) {
            const vp& d = i->first;
            double prob = i->second;
            if (find(d.begin(), d.end(), mp(x, y) ) != d.end()) ans += prob;
        }
    
        cout.precision(12);
        cout << "Case #" << __it << ": " << fixed << ans << endl;
    }    
    
    return 0;
}
